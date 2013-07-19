#include "interface.h"

int limpa_ecra (int tamanho)
{
	int i=0;
	
	while (i<tamanho)
	{
		fputs("\033[A\033[2K\033[A\033[2K",stdout);
		i++;
	}
	return 0;
}
int menu_principal (THash** listas[],LLigada** listae[])
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Gerir pedidos                              #\n");
	printf("#     2 - Gerir localidades                          #\n");
	printf("#     3 - Gerir camiões                              #\n");
	printf("#     4 - Gerir clientes                             #\n");
	printf("#     5 - Dados Estatísticos                         #\n");
	printf("#     6 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("######################################################\n");
	
	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	if (strcmp(opcao,"1")==0)
		return menu_gerirpedidos(listas,listae);
	if (strcmp(opcao,"2")==0)
		return menu_gerirlocalidades(listas,listae);
	else if (strcmp(opcao,"3")==0)
		return menu_gerircamioes(listas,listae);
	else if (strcmp(opcao,"4")==0)
		return menu_gerirclientes(listas,listae);
	else if (strcmp(opcao,"5")==0){
		criar_estatistica (listas, listae);
		return menu_gerirestatistica(listas,listae);}
	else if (strcmp(opcao,"6")==0) 
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_principal(listas,listae);
	}
}

int menu_gerirpedidos (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Efectuar pedido                            #\n");
	printf("#     2 - Procurar pedido                            #\n");
	printf("#     3 - Voltar atrás                               #\n");
	printf("#     4 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################# Procurar Clientes ##################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		ins_pedido(listas);
		return menu_gerirpedidos(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		 procura_pedido(listas);
		return menu_gerirpedidos(listas,listae);}
	else if (strcmp(opcao,"3")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"4")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirclientes(listas,listae);
	}
}	

int menu_gerirlocalidades (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
		
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Inserir localidade                         #\n");
	printf("#     2 - Remover localidade                         #\n");
	printf("#     3 - Gerir ligações entre localidades           #\n");
	printf("#     4 - Procurar localidades                       #\n");
	printf("#     5 - Voltar atrás                               #\n");
	printf("#     6 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################# Gerir Localidades ##################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		ler_localidade(listas);
		return menu_gerirlocalidades(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		remove_localidade(listas);
		return menu_gerirlocalidades(listas,listae);}
	else if (strcmp(opcao,"3")==0){
		menu_gerirligacoes (listas,listae);
		return menu_gerirlocalidades(listas,listae);}
	else if (strcmp(opcao,"4")==0){
		procura_localidadesid (listas);
		return menu_gerirlocalidades(listas,listae);}
	else if (strcmp(opcao,"5")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"6")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirlocalidades(listas,listae);
	}
}

int menu_gerirligacoes (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Inserir ligações de uma localidade         #\n");
	printf("#     2 - Remover ligações de uma localidade         #\n");
	printf("#     3 - Alterar ligaçoes de uma localidade         #\n");
	printf("#     4 - Voltar atrás                               #\n");
	printf("#     5 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################### Gerir Ligações ###################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		ins_lig_localidades (listas);
		return menu_gerirligacoes(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		rem_lig_localidades (listas);
		return menu_gerirligacoes(listas,listae);}
	else if (strcmp(opcao,"3")==0){
		edit_lig_localidades (listas);
		return menu_gerirligacoes(listas,listae);}
	else if (strcmp(opcao,"4")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"5")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirligacoes(listas,listae);
	}
}

int menu_gerircamioes (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Inserir camião                             #\n");
	printf("#     2 - Remover camião                             #\n");
	printf("#     3 - Alterar informação de um camião            #\n");
	printf("#     4 - Procurar camião                            #\n");
	printf("#     5 - Voltar atrás                               #\n");
	printf("#     6 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################### Gerir Camiões ####################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		ins_camiao(listas);
		return menu_gerircamioes(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		rem_camiao(listas);
		return menu_gerircamioes(listas,listae);}
	else if (strcmp(opcao,"3")==0){
		edit_camiao(listas);
		return menu_gerircamioes(listas,listae);}
	else if (strcmp(opcao,"4")==0){
		procura_camioesm(listas);
		return menu_gerircamioes(listas,listae);}
	else if (strcmp(opcao,"5")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"6")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerircamioes(listas,listae);
	}
}


int menu_gerirclientes (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Inserir cliente                            #\n");
	printf("#     2 - Remover cliente                            #\n");
	printf("#     3 - Alterar informação de um cliente           #\n");
	printf("#     4 - Procurar Cliente                           #\n");
	printf("#     5 - Voltar atrás                               #\n");
	printf("#     6 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################### Gerir Clientes ###################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		ins_clientes(listas);
		return menu_gerirclientes(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		rem_cliente(listas);
		return menu_gerirclientes(listas,listae);}
	else if (strcmp(opcao,"3")==0){
		edit_clientes(listas);
		return menu_gerirclientes(listas,listae);}
	else if (strcmp(opcao,"4")==0){
		return menu_procuraclientes(listas,listae);}
	else if (strcmp(opcao,"5")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"6")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirclientes(listas,listae);
	}
}

int menu_gerirestatistica (THash*** listas,LLigada*** listae)	
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Estado actual                              #\n");
	printf("#     2 - Estatistica clientes                       #\n");
	printf("#     3 - Estatistica localidades                    #\n");
	printf("#     4 - Voltar atrás                               #\n");
	printf("#     5 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("############## Gerir Dados Estatísticos ##############\n");

	if (scanf ("%s",opcao)!=1){
		return menu_principal(listas,listae);}
	
	if (strcmp(opcao,"1")==0){
		estado_geral(listas,listae);
		return menu_gerirestatistica(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		estatistica_clientes(listae);
		return menu_gerirestatistica(listas,listae);}
	else if (strcmp(opcao,"3")==0){
		estatistica_localidades(listae);
		return menu_gerirestatistica(listas,listae);}
	else if (strcmp(opcao,"4")==0)
		return menu_principal(listas,listae);
	else if (strcmp(opcao,"5")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirestatistica(listas,listae);
	}
}	

int menu_procuraclientes (THash*** listas,LLigada*** listae)
{
	char opcao[4];
	
	limpa_ecra(50);
	
	printf("################## TRANSITÁRIOS LEI ##################\n");
	printf("#                                                    #\n");
	printf("#     1 - Procurar por contribuinte                  #\n");
	printf("#     2 - Procurar por nome                          #\n");
	printf("#     3 - Voltar atrás                               #\n");
	printf("#     4 - Sair                                       #\n");
	printf("#                                                    #\n");
	printf("################# Procurar Clientes ##################\n");

	if (scanf ("%s",opcao)!=1)
		return menu_principal(listas,listae);
	
	if (strcmp(opcao,"1")==0){
		procura_clientesc(listas);
		return menu_procuraclientes(listas,listae);}
	else if (strcmp(opcao,"2")==0){
		procura_clientesn(listas);
		return menu_procuraclientes(listas,listae);}
	else if (strcmp(opcao,"3")==0)
		return menu_gerirclientes(listas,listae);
	else if (strcmp(opcao,"4")==0)
		return sair(listas);
	else
	{
		mensagem_de_erro(6);
		return menu_gerirclientes(listas,listae);
	}
}	
	
	 
	
