#include <stdlib.h>

#include "grafos.h"

void* da_dij (void *elem) {
    return ((DijElem) elem)->id;
}

DijResult caminho_mais_barato(THash* thash, char* partida, char* destino, float custokm) 
{

    DijResult result = inicializa_THash(50000,50000, &fchar_Hash, &compar_char, &da_dij, sizeof(struct dij_elem),0);

    DijElem elemAct;
    Localidade* localAct;
    DijElem elemento = (DijElem) malloc(sizeof (struct dij_elem));
    
    elemento->km = 0;    
    elemento->taxas = 0;   
    elemento->custokm = custokm;   
    strcpy(elemento->id,partida);   
    elemento->vis = _VIS_GREY;    
    strcpy(elemento->idpai,"");    
    insere_THash(&result, elemento);

    int greyCount = 1;
    while (greyCount > 0) 
    {
        elemAct = NULL;
        aplica_THash(result, &verifica_prox_nodo, &elemAct);
    
        localAct = procura_THash(thash, elemAct->id);
   
		void **params = (void**) malloc (sizeof(void*)*3);
		params[0] = elemAct;
		params[1] = result;
		params[2] = &greyCount;
		
        aplica_LLigada(localAct->ligacoes, &caminhomb_aux, params);
        elemAct->vis = _VIS_BLACK;
     
        if (strcmp(elemAct->id,destino)==0 ) return result;
        greyCount--;
    }
    
    return result;
}

int verifica_prox_nodo(void *elem, void *params) {
    DijElem act = (DijElem) elem;
    DijElem *result = (DijElem *) params;

    if (act->vis != _VIS_BLACK && (*result == NULL || (*result)->km * (*result)->custokm + (*result)->taxas > act->km * act->custokm + act->taxas))
        *result = act;
    return 0;
}

void caminhomb_aux(void *elem, void *params) {
    
    Ligacao* lig = (Ligacao*) elem;
    
    DijElem elemAct = (DijElem) ((void **) params)[0];
    DijResult result =    (DijResult) ((void **) params)[1];
    int *greyCount =      (int *) ((void **) params)[2];

    float newkm = lig->distancia + elemAct->km;
    float newtx = lig->taxas + elemAct->taxas;
    float custokm = elemAct->custokm;
    float res = newkm*custokm+newtx;

    DijElem target = (DijElem) procura_THash(result, lig->id);
    
    if (target && target->vis != _VIS_BLACK && (target->km*target->custokm+target->taxas) > res && target->km != -1) {
        target->km = newkm;
        target->taxas = newtx;
        strcpy(target->idpai,elemAct->id);
    }
    else if (!target) {
        target = (DijElem) malloc(sizeof(struct dij_elem));
        target->km = newkm;
        target->taxas = newtx;
        target->custokm = custokm;
        strcpy(target->id,lig->id);
        strcpy(target->idpai,elemAct->id);
        target->vis = _VIS_GREY;

        (*greyCount)++;

        insere_THash(&result, target);
    }
}

DijResult camiao_mais_barato(THash* thash, char* destino, float peso, int* res, Camiao** cres) 
{

    DijResult result = inicializa_THash(50000,50000, &fchar_Hash, &compar_char, &da_dij, sizeof(struct dij_elem),0);

    DijElem elemAct;
    Localidade* localAct;
    DijElem elemento = (DijElem) malloc(sizeof (struct dij_elem));
    
    Camiao* camiao = (Camiao*) malloc (sizeof(Camiao));
    
    elemento->km = 0;    
    elemento->taxas = 0;    
    strcpy(elemento->id,destino);   
    elemento->vis = _VIS_GREY;    
    strcpy(elemento->idpai,"");    
    insere_THash(&result, elemento);

	localAct = procura_THash(thash, destino);
	if (localAct) 
	{
		ELigada* lista = localAct->camioes->lista;
	    while (lista)
		{
			ACamiao* ac = lista->elem;
			Camiao* c = ac->camiao;
			
			if (c->capacidade > peso)
			{
				strcpy(camiao->matricula,c->matricula);
				strcpy(camiao->id,c->id);
				camiao->custokm = c->custokm;
				strcpy(camiao->localidade,c->localidade);
				*res = 1;
				*cres = camiao;
				return result;
			}
			lista = lista->next;
		}
	}
	

    int greyCount = 1;
    while (greyCount > 0) 
    {

        elemAct = NULL;
        aplica_THash(result, &verifica_prox_nodo_camioes, &elemAct);
    
        localAct = procura_THash(thash, elemAct->id);
   
		void **params = (void**) malloc (sizeof(void*)*3);
		params[0] = elemAct;
		params[1] = result;
		params[2] = &greyCount;
		
        aplica_LLigada(localAct->ligacoes, &caminhomb_aux_camioes, params);
        elemAct->vis = _VIS_BLACK;
        
	if (localAct) 
	{
		ELigada* lista = localAct->camioes->lista;
	        while (lista)
		{
			ACamiao* ac = lista->elem;
			Camiao* c = ac->camiao;
			
			if (c->capacidade > peso)
			{
				strcpy(camiao->matricula,c->matricula);
				strcpy(camiao->id,c->id);
				camiao->custokm = c->custokm;
				strcpy(camiao->localidade,c->localidade);
				*res = 1;
				*cres = camiao;
				return result;
			}
			lista = lista->next;
		}
	}
	greyCount--;
    }
    
    return result;
}

int verifica_prox_nodo_camioes(void *elem, void *params) {
    DijElem act = (DijElem) elem;
    DijElem *result = (DijElem *) params;

    if (act->vis != _VIS_BLACK && (*result == NULL || (*result)->km > act->km ))
        *result = act;
    return 0;
}

void caminhomb_aux_camioes(void *elem, void *params) {
    
    Ligacao* lig = (Ligacao*) elem;
    
    DijElem elemAct = (DijElem) ((void **) params)[0];
    DijResult result =    (DijResult) ((void **) params)[1];
    int *greyCount =      (int *) ((void **) params)[2];

    float newkm = lig->distancia + elemAct->km;
    float newtx = lig->taxas + elemAct->taxas;   

    DijElem target = (DijElem) procura_THash(result, lig->id);
    
    if (target && target->vis != _VIS_BLACK && (target->km) > newkm && target->km != -1) {
        target->km = newkm;
        target->taxas = newtx;
        strcpy(target->idpai,elemAct->id);
    }
    else if (!target) {
        target = (DijElem) malloc(sizeof(struct dij_elem));
        target->km = newkm;
        target->taxas = newtx;
        strcpy(target->id,lig->id);
        strcpy(target->idpai,elemAct->id);
        target->vis = _VIS_GREY;

        (*greyCount)++;

        insere_THash(&result, target);
    }
}
