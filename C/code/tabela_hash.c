#include "tabela_hash.h"

THash* inicializa_THash (int nrtotal, int incremento,int (*fhash)(void*, int),int (*comparchave)(void*, void*), void* (*lerchave)(void*),size_t tamanho,int repetidos)
{
	THash* hashaux = (THash*) malloc (sizeof(THash));
	int i;
	
	
	if(hashaux==NULL){
		mensagem_de_erro(8);
		exit(1);
		}
		else{
	
	
	hashaux-> nrelem = 0;
	hashaux-> nrtotal = nrtotal;
	hashaux-> incremento = incremento;
	hashaux-> fhash = fhash;
	hashaux-> comparchave = comparchave;
	hashaux-> lerchave = lerchave;
	hashaux->tamanho = tamanho;
	hashaux->repetidos = repetidos;
	
	hashaux-> lista = (ELigada**) malloc (sizeof(ELigada*)*nrtotal);
	
	if (hashaux->lista == NULL){
	mensagem_de_erro(8);
	exit(1);
	}
	else{
	for (i=0; i<nrtotal; i++)
	{
		hashaux->lista[i] = NULL;
	}
	}
	}
	return hashaux;
	
}

int cheia_THash (THash* thash) 
{
    return (((float) thash->nrelem / (float) thash->nrtotal) > 0.8);
}

int verifica_existe (ELigada* lligada, void* chave,int (*comparchave)(void*, void*),void* (*lerchave)(void*))
{
	while (lligada)
	{
		if (comparchave(chave,lerchave(lligada->elem))==0)
			return -1;
		lligada = lligada->next;
	}
	return 0;
}

int insere_THash (THash** thash, void* elem)
{
    
	void* chave = (*thash)->lerchave(elem);
	
	int hash = (*thash)->fhash(chave, (*thash)->nrtotal);
    
    ELigada** lista = &((*thash)->lista[hash]);
    
    ELigada* aux = (ELigada*) malloc(sizeof (ELigada));
        
    if (aux==NULL){
		mensagem_de_erro(8);
		exit(1);}
    
    
    
    if ((*thash)->repetidos<=0)
		if (verifica_existe (*lista,chave,(*thash)->comparchave,(*thash)->lerchave)==-1)
			return -1;

    aux->next = *lista;
    aux->elem = malloc((*thash)->tamanho);
    memcpy(aux->elem,elem,(*thash)->tamanho);
        
    *lista = aux;

	(*thash)->lista[hash] = *lista;
	(*thash)->nrelem ++;
    
    if (cheia_THash(*thash)) {
        expandir_THash(thash);
    }
 
    return 0;
}

int expandir_THash (THash** thash) 
{
    int nrtotal= (*thash)->nrtotal;
    int new_nrtotal = nrtotal + (*thash)->incremento;
    
    int x;
    
    ELigada** lista = (*thash)->lista;
    ELigada *aux;
    
    (*thash)->lista = (ELigada **) malloc (sizeof (THash) * new_nrtotal);
	
	if ((*thash)->lista == NULL){
		mensagem_de_erro(8);
		exit(1);
	}
	
    (*thash)->nrtotal = new_nrtotal;
    (*thash)->nrelem = 0;

    for (x = 0; x < new_nrtotal; x++) {
        (*thash)->lista[x] = NULL;
    }

    for (x = 0; x < nrtotal; x++) {
        aux = lista[x];
        while (aux) 
        {
            insere_THash(thash, aux->elem);
            aux = aux->next;
        }
    }
    free(lista);

    (*thash)->nrtotal = new_nrtotal;
	
    return 0;
}

int remover_THash(THash** thash, void *chave) 
{
    int hash = (*thash)->fhash(chave, (*thash)->nrtotal);
    
    ELigada **aux = &((*thash)->lista[hash]);
    
    ELigada* libertar;
    
    while (*aux && (*thash)->comparchave(chave, (*thash)->lerchave((*aux)->elem))) 
		aux = &((*aux)->next);

    if (*aux) 
    {
        libertar = *aux;
        *aux = (*aux)->next;
        free(libertar);
        return 0;
    }
	else 
		return -1;
}

void* procura_THash (THash* thash, void *chave) 
{
	int hash = thash->fhash(chave, thash->nrtotal);
    
    ELigada* aux = thash->lista[hash];
    
    while (aux &&  (thash->comparchave(thash->lerchave(aux->elem), chave)!=0))
        aux = aux->next;

    if (aux)
		return aux->elem;
	else
		return NULL;
}

int aplica_THash (THash* thash, int (*function)(void *, void *), void *params) 
{
    
    ELigada* aux;

    int x;
    for (x = 0; x < thash->nrtotal; x++) {
        aux = thash->lista[x];
        while (aux != NULL) 
        {
            function(aux->elem, params);
            aux = aux->next;
        }
    }

    return 0;
}
