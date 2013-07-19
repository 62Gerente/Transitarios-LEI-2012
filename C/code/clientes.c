#include "clientes.h"

void* da_contribuinte (void* cliente)
{
	Cliente* c = (Cliente*) cliente;
	
	return &c->contribuinte;
}

void* da_totalgasto (void* cliente)
{
	Cliente* c = (Cliente*) cliente;
	
	return &c->totalgasto;
}

void* da_nome (void* cliente)
{
	Cliente* c = (Cliente*) cliente;
	
	return c->nome;
}

void* da_nrpedidos (void* cliente)
{
	Cliente* c = (Cliente*) cliente;
	
	return &c->nrpedidos;
}

void* da_e_nrpedidos (void* ecliente)
{
	EClientep* c = (EClientep*) ecliente;
	
	return &c->nrpedidos;
}

void* da_e_totalgasto (void* ecliente)
{
	EClienteg* c = (EClienteg*) ecliente;
	
	return &c->totalgasto;
}

void* da_e_contp (void* ecliente)
{
	EClientep* c = (EClientep*) ecliente;
	
	return &c->contribuinte;
}

void* da_e_contg (void* ecliente)
{
	EClienteg* c = (EClienteg*) ecliente;
	
	return &c->contribuinte;
}

void* da_anome (void* cliente)
{
	ACliente* c = (ACliente*) cliente;
	return c->cliente->nome;
}

void* da_descricao (void* pedido)
{
	Pedido* p = (Pedido*) pedido;
	return p->descricao;
}

int remover_clienten (THash** thash, void *chave, int contribuinte) 
{
    int hash = (*thash)->fhash(chave, (*thash)->nrtotal);
    
    ELigada **aux = &((*thash)->lista[hash]);
    
    ELigada* libertar;
    
    while (*aux && (*thash)->comparchave(chave, (*thash)->lerchave((*aux)->elem)) && ((((ACliente*)(*aux)->elem))->cliente->contribuinte)==contribuinte ) 
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

