#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "localidades.h"
#include "lista_ligada.h"
#include "fhash.h"
#include "tabela_hash.h"
#include "compar.h"
#include "camioes.h"
#include "interface.h"
#include "clientes.h"
#include "interaccao.h"
#include "localidades.h"
#include "ficheiros.h"

int main ()
{
	
	THash* t_localidades = inicializa_THash (10000,1000,&fchar_Hash,&compar_char,&da_idlocalidade,sizeof(Localidade),0);
	THash* t_clientesc = inicializa_THash (10000,1000,&flong_Hash,&compar_long,&da_contribuinte,sizeof(Cliente),0);
	THash* t_camioes = inicializa_THash (500,500,&fchar_Hash,&compar_char,&da_matricula,sizeof(Camiao),0);
	THash* t_clientesn = inicializa_THash (10000,10000,&fchar_Hash,&compar_char,&da_anome,sizeof(ACliente),1);
	
	LLigada* e_clientep = inicializa_LLigada (&compar_int, &compar_long, &da_e_nrpedidos, &da_e_contp,sizeof(EClientep),0,1);
	LLigada* e_clienteg = inicializa_LLigada (&compar_float, &compar_long, &da_e_totalgasto, &da_e_contg,sizeof(EClienteg),0,1);
	LLigada* e_localidadec = inicializa_LLigada (&compar_int, &compar_char, &da_e_nrservicos, &da_e_idlocal,sizeof(ELocalidade),1,1);
	LLigada* e_localidaded = inicializa_LLigada (&compar_int, &compar_char, &da_e_nrservicos, &da_e_idlocal,sizeof(ELocalidade),0,1);
	
	THash** listas;
	LLigada** listae;

	listas = (THash**) malloc (sizeof(THash*)*5);
	listae = (LLigada**) malloc (sizeof(LLigada*)*5);

	listas[0] = t_localidades;		
	listas[1] = t_clientesc;
	listas[2] = t_camioes;
	listas[3] = t_clientesn;	
	
	listae[0] = e_clientep;
	listae[1] = e_clienteg;
	listae[2] = e_localidadec;
	listae[3] = e_localidaded;
	/*
	ler_localidades_teste (&listas);
	ler_ligacoes_teste (&listas);
	ler_clientes_teste (&listas);
	ler_pedidos_teste(&listas);
	*/
	ler_localidades(&listas);
	ler_clientes(&listas);
	ler_camioes(&listas);
	
	menu_principal(&listas,&listae);
	
	
	return 0;
}
 
