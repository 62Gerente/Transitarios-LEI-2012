#include "lista_ligada.h"

LLigada* inicializa_LLigada (int (*fcompar_ins)(void *, void *),int (*fcompar_rem)(void*, void*),void* (*lerchave_ins)(void*),void* (*lerchave_rem)(void*),size_t tamanho,int ord,int repetidos)
{
	LLigada* laux = (LLigada*) malloc (sizeof(LLigada));
	
	if(laux==NULL){
		mensagem_de_erro(8);
		exit(1);
	}
	
	laux->lista= NULL;
	laux->nrelem =0;
	laux->fcompar_ins = fcompar_ins;
	laux->fcompar_rem = fcompar_rem;	
	laux->lerchave_ins = lerchave_ins;	
	laux->lerchave_rem = lerchave_rem;
	laux->tamanho = tamanho;
	laux->ord = ord;
	laux->repetidos = repetidos;
	
	return laux;
}

int verifica_existell (LLigada* lligada, void* chave)
{
	ELigada* lista = lligada->lista;

	while (lista)
	{
		if ((lligada->fcompar_rem(lligada->lerchave_rem(lista->elem),chave))==0)
			return -1;

		lista= lista->next;
	}
	return 0;
}

int insere_LLigada (LLigada** lligada,void* elem)
{
    ELigada** aux = &((*lligada)->lista);
    ELigada* newnodo = (ELigada*) malloc (sizeof (ELigada));
   
   	newnodo->elem = malloc((*lligada)->tamanho);
    
    if(newnodo==NULL){
		mensagem_de_erro(8);
		exit(1);
	}

	if ((*lligada)->repetidos<=0)
		if (verifica_existell((*lligada),(*lligada)->lerchave_rem(elem))==-1)
			return -1;	
    
    newnodo->next = *aux;
    memcpy(newnodo->elem,elem,(*lligada)->tamanho);
    *aux = newnodo;
    
    (*lligada)->nrelem++;

    return 0;
}

int insereord_LLigada (LLigada** lligada, void* elem)
{
    ELigada** aux = &((*lligada)->lista);
    ELigada* newnodo = (ELigada*) malloc (sizeof (ELigada));
   
   	newnodo->elem = malloc((*lligada)->tamanho);
     if(newnodo==NULL){
		mensagem_de_erro(8);
		exit(1);
	}
    
    if ((*lligada)->ord>0)
		while (*aux && (((*lligada)->fcompar_ins((*lligada)->lerchave_ins((*aux)->elem), (*lligada)->lerchave_ins(elem)))<0)) 
		{
			aux = &((*aux)->next);
		}
	else  
		while (*aux && (((*lligada)->fcompar_ins((*lligada)->lerchave_ins((*aux)->elem), (*lligada)->lerchave_ins(elem)))>0)) 
		{
			aux = &((*aux)->next);
		}

    if ((*lligada)->repetidos<=0)
		if (verifica_existell((*lligada),(*lligada)->lerchave_rem(elem))==-1)
			return -1;	
    
    newnodo->next = *aux;
    memcpy(newnodo->elem,elem,(*lligada)->tamanho);
    *aux = newnodo;
    
    (*lligada)->nrelem++;

    return 0;
}

int remove_LLigada (LLigada** lligada, void* elem)
{
	ELigada** aux = &((*lligada)->lista);
	ELigada* aux2;
	
	while (*aux && (((*lligada)->fcompar_rem((*lligada)->lerchave_rem((*aux)->elem), elem))!=0))
	{
		aux = &((*aux)->next);
	}
	
	if (*aux != NULL) 
	{
        aux2 = *aux;
        *aux = (*aux)->next;
        free(aux2);
        (*lligada)->nrelem--;
    }
    else
		return -1;
	
	return 0;
}

void* procura_LLigada (LLigada* lligada, void* chave)
{
	ELigada* aux = lligada->lista;
	
	while(aux && (lligada->fcompar_rem(lligada->lerchave_rem(aux->elem),chave)!=0))
		aux = aux->next;
	
	if(aux)
		return aux->elem;
	else
		return NULL;
}

int limpa_lista (LLigada** lligada) 
{
    ELigada* aux;

    while ((*lligada)->lista != NULL) {
        aux = (*lligada)->lista;
        (*lligada)->lista = (*lligada)->lista->next;
        free(aux);
    }

    free((*lligada)->lista);
	
	(*lligada)->lista = NULL;
	(*lligada)->nrelem = 0;
	
    return 0;
}

int aplica_LLigada(LLigada* list, void (*function)(void *, void *), void *params) 
{
    ELigada* aux = list->lista;

    while (aux != NULL) {
        function(aux->elem, params);
        aux = aux->next;
    }
    return 0;
}
