#include "interaccao.h"
#include <float.h>


int contemSubString (char* string, char* substring){
    
    int i;
    int tamString = strlen(string);
    int tamSubString = strlen(substring);
	int flag=0;
    
    for(i=0 ; i<tamString && flag == 0;i++){
		if(strncmp(string+i,substring,tamSubString) == 0)
		flag = 1;
	} 
	return flag;

}

int int_ins_localidade (THash*** listas,char* nome, char* id)
{
	
	THash** thash = &((*listas)[0]);

	Localidade* l = (Localidade*) malloc (sizeof(Localidade));

	strcpy(l->nome,nome);
	strcpy(l->id,id);
	l-> nrservicos = 0;
	l->ligacoes = inicializa_LLigada (&compar_float,&compar_char,&da_taxas,&da_idligacao, sizeof(Ligacao),0,0);
	l->adjacentes = inicializa_LLigada (&compar_char,&compar_char,&da_adjacente,&da_adjacente, sizeof(Adjacente),0,0);
	l->camioes = inicializa_LLigada (&compar_int,&compar_char,&da_acustokm,&da_amatricula, sizeof(ACamiao),0,0);
			
	if (!insere_THash (thash,l))	
		mensagem_de_erro(0);
	else 
		mensagem_de_erro(7);
		
	return 0;
}

int int_ins_lig_local (THash*** listas,Localidade* l,char* id,char* id2, float distancia, float taxas)
{
	
	THash** thash = &((*listas)[0]);

	Localidade *lp;
	Ligacao lig;
	Adjacente* a = (Adjacente*) malloc (sizeof(Adjacente));

	lp = procura_THash(*thash,id2);
	strcpy (a->id,id);
	strcpy (lig.id,id2);
	lig.distancia = distancia;
	lig.taxas = taxas;
	lig.apl = lp;
						
	if (lp)
	{
		if ((insereord_LLigada(&l->ligacoes,&lig)==0) && ((insereord_LLigada(&lp->adjacentes,a))==0))
			mensagem_de_erro(0);
		else 
			mensagem_de_erro(7);
	}
	else mensagem_de_erro(5);
	
	return 0;
}


int int_rem_localidade (THash*** listas,char* id)
{
	THash** thash = &((*listas)[0]);
	char nome2[30];

	Localidade* l,*lp;
	
	l = procura_THash (*thash,id);
			
	if (l)
	{
		while (l->ligacoes->lista)
		{

			strcpy (nome2,l->adjacentes->lerchave_ins(l->ligacoes->lista->elem));
			lp = procura_THash (*thash,nome2);
			remove_LLigada (&lp->adjacentes,id);
			l->ligacoes->lista = l->ligacoes->lista->next;
		}
		while (l->adjacentes->lista)
		{
			strcpy (nome2,l->adjacentes->lerchave_ins(l->adjacentes->lista->elem));
			lp = procura_THash (*thash,nome2);
			remove_LLigada (&lp->ligacoes,id);
			l->adjacentes->lista = l->adjacentes->lista->next;
		}
		remover_THash(thash,id);
		mensagem_de_erro(0);
	}
	else 
		mensagem_de_erro(5);
		
	return 0;
}

int int_rem_lig_local (THash*** listas,Localidade* l,char* id, char* id2)
{
	THash** thash = &((*listas)[0]);

	Localidade *lp;


	lp = procura_THash(*thash,id2);
						
	if (lp)
	{
		if (remove_LLigada(&l->ligacoes,id2)==0)
		{	
			if (remove_LLigada(&lp->adjacentes,id)==0)
						mensagem_de_erro(0);

		}
		else
			mensagem_de_erro(5);
    }
    else
		mensagem_de_erro(5);
		
    return 0;
}

int int_edit_lig_local (Localidade* l, char* id2, float distancia, float taxas)
{
	Ligacao* lp;
	
	lp = procura_LLigada(l->ligacoes,id2);
						
	if (lp)
	{
		lp->distancia = distancia;
		lp->taxas = taxas;
		mensagem_de_erro(0);
	}
	else
		mensagem_de_erro(5);
		
	return 0;
}

int int_ins_camiao (THash*** listas, char* id, char* matricula, char* localidade, float custokm, float capacidade)
{
	THash** thash = &((*listas)[0]);
	THash** tcamioes = &((*listas)[2]);
	Localidade* l;
	ACamiao* ac = (ACamiao*) malloc (sizeof(ACamiao));
	Camiao* c = (Camiao*) malloc (sizeof(Camiao));
	
	l = procura_THash (*thash,localidade);
			
	if(l)
	{
		strcpy(c->id,id);
		strcpy(c->matricula,matricula);
		c->capacidade = capacidade;
		c->custokm = custokm;
		strcpy(c->localidade, localidade);

		if ((insere_THash (tcamioes,c))==0)
		{
			ac->camiao = procura_THash (*tcamioes,matricula);
			insere_LLigada (&l->camioes,ac);
			mensagem_de_erro(0);
		}
		else
			mensagem_de_erro(7);
			
	}
	else 
		mensagem_de_erro(5);
		
	return 0;
}

int int_rem_camiao (THash*** listas, char* matricula)
{
	THash** thash = &((*listas)[0]);
	THash** tcamioes = &((*listas)[2]);
	Localidade *l;
	
	Camiao* c = procura_THash (*tcamioes,matricula);
	
						
	if(c)
	{
		l = procura_THash(*thash,c->localidade);
		remover_THash (tcamioes,matricula);
		remove_LLigada (&l->camioes,matricula);
		mensagem_de_erro(0);
	}
	else 
		mensagem_de_erro(5);
	return 0;
}

int int_edit_camiao (THash*** listas, char* id, char* matricula, char* localidade, float custokm, float capacidade)
{
	THash** thash = &((*listas)[0]);
	THash** tcamioes = &((*listas)[2]);
	
	Camiao* c = procura_THash (*tcamioes,matricula);
	Localidade* l = procura_THash (*thash,localidade), *laux;
					
	if(l && c)
	{
		laux = procura_THash (*thash,c->localidade);
		strcpy(c->id,id);
		strcpy(c->localidade,localidade);
		c->capacidade = capacidade;
		c->custokm = custokm;
		remove_LLigada (&laux->camioes,matricula);
		mensagem_de_erro(0);
	}
	else
		mensagem_de_erro(5);
		
	return 0;
}

int int_ins_clientes (THash*** listas, char* nome,char* mail, char* localidade, long int contribuinte)
{
	
	THash** lclientesc = &((*listas)[1]);
	THash** lclientesn = &((*listas)[3]);

	Cliente* c = (Cliente*) malloc (sizeof(Cliente));
	ACliente* ac = (ACliente*) malloc (sizeof(ACliente));
				

		strcpy(c->nome,nome);
		strcpy(c->localidade,localidade);
		strcpy(c->mail,mail);
		c->contribuinte = contribuinte;
		c->nrpedidos = 0;
		c->totalgasto = 0;
		c->pedidos = inicializa_LLigada (&compar_char,&compar_char,&da_descricao,&da_descricao, sizeof(Pedido),0,0);
		ac->cliente = c;
		
		if (insere_THash(lclientesc,c)==0)
		{
			insere_THash (lclientesn,ac);
			mensagem_de_erro(0);
		}
		else mensagem_de_erro(7);

	return 0;
}

int int_rem_clientes (THash*** listas, long int contribuinte)
{
	THash** lclientesc = &((*listas)[1]);
	THash** lclientesn = &((*listas)[3]);
	
	Cliente* c;
	
	c = procura_THash (*lclientesc,&contribuinte);
	
	if(c)
	{	
		remover_clienten(lclientesn,c->nome,contribuinte);			
		remover_THash(lclientesc,&contribuinte);
		mensagem_de_erro(0);
	}
	else
		mensagem_de_erro(5);
	return 0;
}

int int_edit_clientes (THash*** listas, char* mail, long int contribuinte, char* localidade)
{
	THash** lclientesc = &((*listas)[1]);
	Cliente* c;
	
	c = procura_THash (*lclientesc,&contribuinte);
	
	if(c)
	{
		strcpy(c->mail,mail);		
		strcpy(c->localidade,localidade);
		mensagem_de_erro(0);
	}
	else
		mensagem_de_erro(5);
	return 0;
}

int int_procura_clientesc(THash*** listas,long int contribuinte)
{
		char linha[30];
		THash** lclientesc = &((*listas)[1]);
		LLigada *aux;
		ELigada *principal;
		Pedido * pedido;
		
		Cliente* c = procura_THash (*lclientesc,&contribuinte);
		
		if (c)
		{
			limpa_ecra(50);
			printf("################ PROCURAR CLIENTES ##############\n\n");
			printf ("Nome do Cliente: %s \n", c->nome);
			printf ("Localidade: %s \n",c->localidade);
			printf ("Mail: %s\n",c->mail);
			printf ("Contribuinte: %ld \n",c->contribuinte);
			printf ("Número pedidos e total gasto: %d %.2f \n",c->nrpedidos,c->totalgasto);
			if(c->nrpedidos != 0)
			{ aux = c->pedidos;
			  principal = aux->lista;
			  pedido = principal->elem;
			  printf("################# ULTIMO PEDIDO #################\n");
			  printf(" Partida: %s\n Destino: %s\n Peso da Ecomenda: %0.2f \n Custo da Ecomenda: %0.2f\n Camião: %s\n Descrição: %s",pedido->localidadep,pedido->localidaded,pedido->peso,pedido->custo,pedido->camiao,pedido->descricao);	
				}
			if (fgets (linha,30,stdin)) 
			return 0;
		}
		else
			mensagem_de_erro(5);
			
			
		
		return 0;
}

int int_procura_clientesn (THash*** listas,char* nome)
{
		THash** lclientesn = &((*listas)[3]);
		LLigada *aux;
		ELigada *principal;
		Pedido * pedido;

		int nr = 0;
		int hash = (*lclientesn)->fhash(nome,((*lclientesn)->nrtotal));
		
		char linha[30];
		
		ELigada* lista = (*lclientesn)->lista[hash];
		
		while (lista)
		{
			ACliente* ac = (ACliente*) lista->elem;
			Cliente* c = ac->cliente;
			if (strcmp(nome,c->nome)==0)
			{
				if (!nr) 
				{
					limpa_ecra(50);
					printf("################ PROCURAR CLIENTES ##############\n\n");
				}
				printf ("Nome do Cliente: %s \n", c->nome);
				printf ("Localidade: %s \n",c->localidade);
				printf ("E-mail: %s\n",c->mail);
				printf ("Contribuinte: %ld \n",c->contribuinte);
				printf ("Número de pedidos e total gasto: %d %0.2f ;\n\n",c->nrpedidos,c->totalgasto);
				if(c->nrpedidos != 0)
				{ aux = c->pedidos;
					principal = aux->lista;
					pedido = principal->elem;
					printf("################# ULTIMO PEDIDO #################\n");
					printf(" Partida: %s\n Destino: %s\n Peso da Ecomenda: %0.2f \n Custo da Ecomenda: %0.2f\n Camião: %s\n Descrição: %s",pedido->localidadep,pedido->localidaded,pedido->peso,pedido->custo,pedido->camiao,pedido->descricao);	
				}
				nr++;
			}
			lista = lista->next;
		}
		
		if (nr==0) mensagem_de_erro(5);
		
		else if (fgets (linha,30,stdin)) 
				return 0;
			
		return 0;
}

int int_ins_pedido(THash*** listas,long int contribuinte,char* loc1,char* loc2,float peso,char* descricao)
{
	THash** thash = &((*listas)[0]);
	THash** lclientesc = &((*listas)[1]);
	THash** camioes = &((*listas)[2]);
	
	Localidade *l1 = procura_THash(*thash,loc1);
	Localidade *l2 = procura_THash(*thash,loc2);
	Cliente* c = procura_THash(*lclientesc,&contribuinte);

	int flag=0;
	float mc_km=0 , mc_custokm=0 , mc_taxas=0 ;
	char mc_matricula[10], mc_localidade[30];
	
	Pedido* pedido = (Pedido*) malloc (sizeof(Pedido));
	Camiao* camiao;
	ACamiao* ac = (ACamiao*) malloc (sizeof(ACamiao));

	if (!l1 || !l2 || !c)
	{
		mensagem_de_erro(5);
		return 0;
	}
	
	DijResult result = camiao_mais_barato(*thash,loc1,peso,&flag,&camiao);

	if (!flag)
	{
		mensagem_de_erro(10);
		return 0;
	}
	
	strcpy(mc_localidade,camiao->localidade);
	
	DijElem elem2 = procura_THash (result,mc_localidade);
	
	if (!elem2)
	{
			mensagem_de_erro(10);
			return 0;
	}
	
	mc_km = elem2->km;
	mc_taxas = elem2->taxas;
	mc_custokm = camiao->custokm;
	strcpy(mc_matricula,camiao->matricula);
	
	DijResult resultado = caminho_mais_barato(*thash, loc1, loc2, mc_custokm);
	
	DijElem elem = procura_THash (resultado,loc2);
	
	if (!elem)
		mensagem_de_erro(9);
		
	else
	{
		limpa_ecra(50);
		printf("################ PEDIDO EFECTUADO ##############\n\n");
		printf ("Camiao utilizado: %s \n",mc_matricula);
		printf ("Custo por km: %f \n",mc_custokm);
		printf ("Localidade anterior: %s \n",mc_localidade);
		printf ("Distancia para a origem da entrega: %0.2f \n",mc_km);
		printf ("Custo minimo até a origem da entrega: %0.2f \n\n",mc_km*mc_custokm +mc_taxas);
		printf ("Ditancia entre a origem e o destino da entrega: %0.2f \n",elem->km);
		printf ("Custo minimo entre a origem e o destino da entrega: %0.2f \n\n",elem->km*elem->custokm + elem->taxas);
		printf ("Ditancia total: %0.2f \n",elem->km + mc_km);
		printf ("Custo total: %0.2f \n",(mc_km*mc_custokm +mc_taxas) + (elem->km*elem->custokm + elem->taxas));
		
		l1->nrservicos++;
		l2->nrservicos++;
		c->nrpedidos++;
		c->totalgasto += (mc_km*mc_custokm +mc_taxas) + (elem->km*elem->custokm + elem->taxas);
		
		pedido->cliente = contribuinte;
		strcpy(pedido->descricao,descricao);
		pedido->peso = peso;
		strcpy(pedido->localidadep,loc1);
		strcpy(pedido->localidaded,loc2);
		strcpy(pedido->camiao,mc_matricula);
		pedido->custo = (mc_km*mc_custokm +mc_taxas) + (elem->km*elem->custokm + elem->taxas);
		pedido->percorrido = elem->km + mc_km;
		
		camiao = procura_THash (*camioes,&mc_matricula);
		
		remove_LLigada (&l1->camioes,c->localidade);
		
		strcpy(camiao->localidade,loc2);
		
		ac->camiao = camiao;
		
		insereord_LLigada (&l2->camioes,ac);
		
		insere_LLigada (&c->pedidos,pedido);
		
		if (fgets (mc_localidade,30,stdin))
			return 0; 
	}
	return 0;
}


int int_procura_camioesm(THash*** listas, char* matricula)
{
		char linha[30];
		THash** lcamioesm = &((*listas)[2]);
		
		Camiao* c = procura_THash (*lcamioesm,matricula);
		
		if (c)
		{
			limpa_ecra(50);
			printf("################ PROCURAR CAMIÕES ##############\n\n");
			printf ("Identificador: %s ;\n", c->id);
			printf ("Matrícula: %s ;\n",c->matricula);
			printf ("Custo por quilómetro: %.2f ;\n",c->custokm);
			printf ("Capacidade total: %.2f ;\n",c->capacidade);
			printf ("Localidade onde se encontra: %s ;\n", c->localidade);
			if (fgets (linha,30,stdin)) 
			return 0;
		}
		else
			mensagem_de_erro(5);
			
			
		
		return 0;
}

int int_procura_localidadesid(THash*** listas, char* id)
{
		char linha[30];
		THash** llocalidades = &((*listas)[0]);
		
		Localidade* l = procura_THash (*llocalidades,id);
		
		if (l)
		{
			limpa_ecra(50);
			printf("################ PROCURAR LOCALIDADES ##############\n\n");
			printf ("Nome: %s ;\n", l->nome);
			printf ("Identificação: %s ;\n",l->id);
			printf ("Número de serviços: %d ;\n",l->nrservicos);
			printf ("Número de clientes na localidade: %d ;\n",l->camioes->nrelem);
			if (fgets (linha,30,stdin)) 
			return 0;
		}
		else
			mensagem_de_erro(5);
			
			
		
		return 0;
}




int int_procura_pedido(THash*** listas, char* descricao)
{
		char linha[30]; int i;
		THash** lclientes = &((*listas)[1]);
		LLigada* pedaux;
		ELigada* principal;
		ELigada* aux;
		Cliente* c;
		Pedido* ped;
		int flag = 0; 
		
		limpa_ecra(50);
		printf("################## PROCURAR PEDIDOS ################\n\n");
		for(i = 0;i<(*lclientes)->nrtotal;i++)
		{
			principal = (*lclientes)->lista[i];
		
			while (principal)
			{
				c = (Cliente*) (principal->elem);
				pedaux = c->pedidos;
		        aux = pedaux->lista;
				
				while(aux){
					ped = (Pedido*) aux->elem;
					if(contemSubString(ped->descricao,descricao)){
						flag = 1;
						printf ("Nº de contribuinte: %ld \n", ped->cliente);
						printf ("Descrição do Pedido: %s \n",ped->descricao);
						printf ("Partida: %s \n",ped->localidadep);
						printf ("Destino: %s \n",ped->localidaded);
						printf ("Peso da Mercadoria: %0.2f\n", ped->peso);
						printf ("Matriculo do camiao: %s\n", ped->camiao);
						printf ("Nº de Km percorridos %0.2f\n", ped->percorrido);
						printf ("Custo da mercadoria %0.2f\n\n", ped->custo);
						}
						aux=aux->next;
					}
					principal=principal->next;
				}
			}
			
			if (flag == 0)
			mensagem_de_erro(5);
				
			if (fgets (linha,30,stdin)) 
							return 0;
							return 0;
		}

