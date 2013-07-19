#include "estatistica.h"

int estado_geral (THash*** listas,LLigada*** listae)
{
	THash* thash = (*listas)[0];
	THash* clientes = (*listas)[1];
	THash* camioes = (*listas)[2];
	
	LLigada** clientep = &((*listae)[0]);
	LLigada** clienteg = &((*listae)[1]);
	LLigada** localidadec = &((*listae)[2]);
	LLigada** localidaded = &((*listae)[3]);
	LLigada* pedaux;
	 
	ELigada* principal;
	ELigada* aux = (*localidaded)->lista;
	ELigada* aux2 = (*localidadec)->lista;  
	ELigada* aux3 = (*clientep)->lista;
	ELigada* aux4 = (*clienteg)->lista;
	ELigada* aux5;
	
	ELocalidade* ld = (ELocalidade*) aux->elem;
	ELocalidade* lc = (ELocalidade*) aux2->elem;
	
	EClientep* cp = (EClientep*) aux3->elem;
	EClienteg* cg = (EClienteg*) aux4->elem; 
	Cliente* c;
	Localidade* l;
	
	Pedido* ped;
	
	char linha[30];
	long int cliente_p, cliente_c;
	
	
	int i; 
	float  max_cped = 0, max_pped = 0;
	int cont_lig = 0;

	limpa_ecra(50);
	
	for(i=0; i<thash->nrtotal; i++)
	{
		principal = thash->lista[i];
		while (principal)
		{
			l = (Localidade*) (principal->elem);
			cont_lig+=(l->ligacoes->nrelem); 
			principal = principal->next;
		}

	}
	
	for(i=0;i<clientes->nrtotal;i++){
		
		principal = clientes->lista[i];
		
		while (principal){
			
			c = (Cliente*) (principal->elem);
			
			pedaux = c->pedidos;
		    aux5 = pedaux->lista;
			
		    
			while(aux5){
				
				ped = (Pedido*) aux5->elem;
				
				if (ped->peso > max_cped){
					cliente_c = ped->cliente;
					max_cped = ped->peso;
				}  
				
								
				if (ped->percorrido > max_pped){
					cliente_p = ped->cliente;
					max_pped = ped->percorrido;
				}
				
				aux5=aux5->next;
				  
				
				}
				principal = principal->next; 
		}
	}
	
	
	
	printf("################### ESTADO GERAL ##################\n\n");
	printf("################### LOCALIDADES ###################\n\n");
	printf("       Nº de localidades: %d \n", thash->nrelem);
	printf("       Nº de ligações: %d  \n",cont_lig);
	printf("       Localidade mais requisitada: %s      %d\n",ld->id, ld->nrservicos);
	printf("       Localidade menos requisitada: %s     %d\n\n",lc->id, lc->nrservicos);
	printf("#################### CLIENTES ####################\n\n"); 
	printf("       Nº de clientes: %d \n", clientes->nrelem);	
	printf("       Clientes com mais ecomendas %ld %d \n", cp->contribuinte, cp->nrpedidos);
	printf("       Cliente com mais gastos: %ld %0.2f \n\n" , cg->contribuinte, cg->totalgasto);
	printf("#################### CAMIÕES #####################\n\n");
	printf("       Nº de Camiões: %d\n\n", camioes->nrelem );
	printf("#################### PEDIDOS #####################\n\n");
	printf("       Pedido mais caro: %ld %0.2f\n",cg->contribuinte, cg->totalgasto);
	printf("       Pedido mais longo: %ld %0.2f\n",cliente_p, max_pped);
	printf("       Pedido mais pesado: %ld %0.2f\n",cliente_c, max_cped);

	
	if (fgets (linha,30,stdin)) 
		if (fgets (linha,30,stdin))
	return 0;
		return 0;
}

int criar_estatistica (THash*** listas, LLigada*** listae)
{	
	THash* thash = (*listas)[0];
	THash* thashc = (*listas)[1];
	ELigada* principal;
	
	LLigada** clientesp = &((*listae)[0]);
	LLigada** clientesg = &((*listae)[1]);	
	LLigada** localidadec = &((*listae)[2]);
	LLigada** localidaded = &((*listae)[3]);
	
	limpa_lista (clientesp);
	limpa_lista (clientesg);
	limpa_lista (localidadec);
	limpa_lista (localidaded);
	
	EClienteg *cg = (EClienteg*) malloc (sizeof(EClienteg));
	EClientep *cp = (EClientep*) malloc (sizeof(EClientep));
	
	ELocalidade *lc,*ld;
	lc = (ELocalidade*) malloc (sizeof(ELocalidade));
	ld = (ELocalidade*) malloc (sizeof(ELocalidade));
	
	int i;

	for(i=0; i<thash->nrtotal; i++)
	{
		principal = thash->lista[i];
		while (principal)
		{
			Localidade* l = (Localidade*) (principal->elem);

			strcpy (lc->id,l->id);
			strcpy (ld->id,l->id);
			lc->nrservicos = l->nrservicos;
			ld->nrservicos = l->nrservicos;
			
			insereord_LLigada (localidadec,lc);
			insereord_LLigada (localidaded,ld);

			
		principal = principal->next;
		}

	}

	for(i=0; i<thashc->nrtotal; i++)
	{
		principal = thashc->lista[i];
		while (principal)
		{
			Cliente* c = (Cliente*) (principal->elem);

				cp->contribuinte = c->contribuinte;
				cp->nrpedidos=c->nrpedidos;
				cg->contribuinte= c->contribuinte;
				cg->totalgasto =c->totalgasto;
				
				insereord_LLigada(clientesp,cp);
				insereord_LLigada(clientesg,cg);

			
		principal = principal->next;
		}

	}

		return 0; 
}

int estatistica_clientes (LLigada*** listae)
{
	LLigada** clientesp = &((*listae)[0]);
	LLigada** clientesg = &((*listae)[1]);
	ELigada* aux = (*clientesp)->lista;
	ELigada* aux2 = (*clientesg)->lista;  
	char linha[30];
	int i = 10;
	

	limpa_ecra(50);
	printf("##################### CLIENTES ####################\n\n");
	printf("############ CLIENTES COM MAIS ENCOMENDAS #########\n\n");	
	while (aux && i>0)
	{
		EClientep* cp = (EClientep*) aux->elem;
		printf ("  **  %ld    %d\n",cp->contribuinte, cp->nrpedidos);
		i--;
		aux = aux -> next;
	}
	i=10;
	printf("\n\n############## CLIENTES COM MAIS GASTOS ##########\n\n");
	while (aux2 && i>0)
	{
		EClienteg* cg = (EClienteg*) aux2->elem;
		printf ("  **  %ld    %0.3f\n",cg->contribuinte, cg->totalgasto);
		i--;
		aux2 = aux2 -> next;
	}
	if (fgets (linha,30,stdin)) 
		if (fgets (linha,30,stdin))
	return 0;
		return 0;
}

int estatistica_localidades (LLigada*** listae)
{
	LLigada** localidadec = &((*listae)[2]);
	LLigada** localidaded = &((*listae)[3]);
	ELigada* aux = (*localidaded)->lista;
	ELigada* aux2 = (*localidadec)->lista;  
	char linha[30];
	int i=10;

	limpa_ecra(50);
	printf("################### LOCALIDADES ####################\n\n");
	printf("############ LOCALIDADES MAIS REQUISITADAS #########\n\n");	
	while (aux && i>0)
	{
		ELocalidade* ld = (ELocalidade*) aux->elem;
		printf ("  **  %15s      %d\n",ld->id, ld->nrservicos);
		i--;
		aux = aux -> next;
	}
	i=10;
	printf("\n\n############ LOCALIDADES MENOS REQUISITADAS ########\n\n");
	while (aux2 && i>0)
	{
		ELocalidade* lc = (ELocalidade*) aux2->elem;
		printf ("  **  %15s      %d\n",lc->id, lc->nrservicos);
		i--;
		aux2 = aux2 -> next;
	}
	if (fgets (linha,30,stdin)) 
		if (fgets (linha,30,stdin))
	return 0;
		return 0;
}
