#include "localidades.h"

void* da_localidade (void* l)
{
	Localidade* local = (Localidade*) l; 
	
	return local-> nome;
}
void* da_idlocalidade (void* l)
{
	Localidade* local = (Localidade*) l; 
	
	return local-> id;
}
void* da_taxas (void* l)
{
	Ligacao* lig = (Ligacao*) l;
	
	return &lig->taxas;
}

void* da_idligacao (void* l)
{
	Ligacao* lig = (Ligacao*) l;
	
	return lig->id;
}

void* da_adjacente (void* a)
{
	Adjacente* adj = (Adjacente*) a;
	
	return adj->id;
}
 void* da_e_nrservicos (void* el)
 {
	 ELocalidade* l = (ELocalidade*) el;
	 
	 return &l->nrservicos;
 }

void* da_e_idlocal (void* el)
 {
	 ELocalidade* l = (ELocalidade*) el;
	 
	 return l->id;
 }
