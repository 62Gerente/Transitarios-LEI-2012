#include "ficheiros.h"




int ler_pedidos_teste (THash*** listas){
	
	FILE *fp;
	char string[200], lp[30],ld[30],desc[40],lixo[100];
    float carga;
    long int nif;
    int teste;
    fp = fopen("pedidos.txt", "r");
	 
	 while (fgets(string,200,fp))
		{
		sscanf (string,"%ld|%[^|]|%[^|]|%f|%[^|]|%d|%[^\r\n]",&nif,lp,ld,&carga,desc,&teste,lixo);
		printf("%s\n",desc);
		int_ins_pedido(listas,nif,lp,ld,carga,desc);
	}
	fclose(fp);
	
	return 0;
	
}

int ler_localidades_teste (THash*** listas)
{
	FILE* fp;
    char string[500], nome[80], id[30],lixo[300];
    
    fp = fopen("localidades.txt", "r");
    
    while (fgets(string,500,fp))
    {
		sscanf (string,"%[^|]|%[^|]|%[^\r\n]",id,nome,lixo);
		int_ins_localidade (listas, nome, id);
	}
	fclose(fp);
	
	return 0;
}
int ler_ligacoes_teste (THash*** listas)
{
	THash** thash = &((*listas)[0]);
	FILE* fp;
    char string[500], id2[30], id[30];
    float nrkm, custo;
    Localidade* l;
    
    fp = fopen("custosligacao.txt", "r");
    
    while (fgets(string,500,fp))
    {
		sscanf (string,"%[^|]|%[^|]|%f|%f",id,id2,&nrkm,&custo);
		l = procura_THash(*thash,id);
		int_ins_lig_local (listas,l,id,id2,nrkm,custo);
	}
	fclose(fp);
	
	return 0;
}
int ler_clientes_teste (THash*** listas)
{
	FILE* fp;
    char string[500], nome[80], mail[80], localidade[80];
    long int c;
    
    fp = fopen("utilizadores.txt", "r");
    
    while (fgets(string,500,fp))
    {
		sscanf (string,"%ld|%[^|]|%[^|]|%[^\r\n]",&c,nome,mail,localidade);
		int_ins_clientes (listas, nome, mail, localidade, c);
	}
	fclose(fp);
	
	return 0;
}
int escreve_localidades (THash*** listas)
{
	FILE* f;
	THash* thash = (*listas)[0];
	int i,nrl,nra;
	ELigada* principal;
	
	f=fopen("save_loc.txt","w+");

	for(i=0; i<thash->nrtotal; i++)
	{
		principal = thash->lista[i];
		while (principal)
		{
			Localidade* l = (Localidade*) (principal->elem);
			nrl = l->ligacoes->nrelem;
			nra = l->adjacentes->nrelem;

			fwrite(l, sizeof(Localidade) , 1,f);
			
			fwrite(&nrl,sizeof (int),1,f);
			fwrite(&nra,sizeof (int),1,f);
		
			for(;nrl;nrl--) 
			{
				fwrite(l->ligacoes->lista->elem, sizeof(Ligacao) , 1,f);
				l->ligacoes->lista = l->ligacoes->lista->next;
			}
			for(;nra;nra--) 
			{
				fwrite(l->adjacentes->lista->elem, sizeof(Adjacente) , 1,f);
				l->adjacentes->lista = l->adjacentes->lista->next;
			}
			
		principal = principal->next;
		}

	}
	fclose(f);
	
	return 0;
}
int escreve_clientes (THash*** listas)
{
	FILE* f;
	THash* thash = (*listas)[1];
	int i,nrp;
	ELigada* principal;
	
	f=fopen("save_cli.txt","w+");

	for(i=0; i<thash->nrtotal; i++)
	{
		principal = thash->lista[i];
		while (principal)
		{
			Cliente* c = (Cliente*) (principal->elem);
			
			nrp = c->pedidos->nrelem;
			
			fwrite(c, sizeof(Cliente) , 1,f);
			fwrite(&nrp,sizeof (int),1,f);

			for(;nrp;nrp--) 
			{
				fwrite(c->pedidos->lista->elem, sizeof(Pedido) , 1,f);
				c->pedidos->lista = c->pedidos->lista->next;
			}

		principal = principal->next;
		}

	}
	fclose(f);
	
	return 0;
}
int ler_localidades (THash*** listas)
{
	FILE* f;
	THash** thash = &(*listas)[0];
	int nrl,nra;
	f=fopen("save_loc.txt","r");
	
	Localidade* l = (Localidade*) malloc (sizeof(Localidade));
	Ligacao* lig = (Ligacao*) malloc (sizeof(Ligacao));
	Adjacente* adj = (Adjacente*) malloc (sizeof(Adjacente));
	
		while (fread(l,sizeof(Localidade),1,f))
		{
			if (fread(&nrl,sizeof (int),1,f))
				if (fread(&nra,sizeof (int),1,f))
			

			l->ligacoes = inicializa_LLigada (&compar_float,&compar_char,&da_taxas,&da_idligacao, sizeof(Ligacao),0,0);
			
			for(;nrl;nrl--) 
			{
				if (fread(lig, sizeof(Ligacao), 1,f))
					insereord_LLigada(&l->ligacoes,lig);
			}
			
			l->adjacentes = inicializa_LLigada (&compar_char,&compar_char,&da_adjacente,&da_adjacente, sizeof(Adjacente),0,0);
			
			for(;nra;nra--) 
			{
				if (fread(adj, sizeof(Adjacente), 1,f))
					insereord_LLigada(&l->adjacentes,adj);
			}
			
			l->camioes = inicializa_LLigada (&compar_int,&compar_char,&da_acustokm,&da_amatricula, sizeof(ACamiao),0,0);
			insere_THash (thash,l);
		}
	fclose(f);
	
	return 0;
}
int ler_clientes (THash*** listas){
	
	
	THash** thash = &(*listas)[1];
	THash** thashn = &(*listas)[3];
	int nrp;
	Cliente* c = (Cliente*) malloc (sizeof(Cliente));
	Pedido* pedido = (Pedido*) malloc (sizeof(Pedido));


	FILE* f = fopen("save_cli.txt","r");
	
	
		while (fread(c,sizeof(Cliente),1,f))
		{	

			if (fread(&nrp,sizeof (int),1,f))
			
			c->pedidos = inicializa_LLigada (&compar_char,&compar_char,&da_descricao,&da_descricao, sizeof(Pedido),0,0);
			
			for(;nrp;nrp--) 
			{
				if (fread(pedido, sizeof(Pedido), 1,f))
				  insere_LLigada(&c->pedidos,pedido);
			}
			insere_THash (thash,c);

		}
	fclose(f);
	
	int i = 0;
	for (;i<(*thash)->nrtotal;i++)
	{
		ELigada* lista = (*thash)->lista[i];
		
		while (lista)
		{
			ACliente* ac = (ACliente*) malloc (sizeof(ACliente));
			ac->cliente = lista->elem;
			insere_THash (thashn,ac);
			lista = lista->next;
		} 
	}
	
	return 0;
}

int escreve_camioes (THash*** listas)
{
	FILE* f;
	THash* thash = (*listas)[2];
	int i;
	ELigada* principal;
	
	f=fopen("save_cam.txt","w+");

	for(i=0; i<thash->nrtotal; i++)
	{
		principal = thash->lista[i];
		while (principal)
		{
			Camiao* c = (Camiao*) (principal->elem);
			
			fwrite(c, sizeof(Camiao) , 1,f);

		principal = principal->next;
		}

	}
	fclose(f);
	
	return 0;
}

int ler_camioes (THash*** listas)
{
	FILE* f;
	THash** thash = &(*listas)[2];
	THash** thashl = &(*listas)[0];
	int i;	
	f=fopen("save_cam.txt","r");
	
	Camiao* c = (Camiao*) malloc (sizeof(Camiao));
	ACamiao* ac = (ACamiao*) malloc (sizeof(ACamiao));
	Localidade* l;

		while (fread(c,sizeof(Camiao),1,f))
		{	
			insere_THash (thash,c);
		}
	fclose(f);
	
	for (i=0;i<(*thash)->nrtotal;i++)
	{
		ELigada* lista = (*thash)->lista[i];
		
		while (lista)
		{
			ac->camiao = lista->elem;
			l= procura_THash (*thashl,ac->camiao->localidade);
			insere_LLigada (&l->camioes,ac);
			lista = lista->next;
		} 
	}
	
	return 0;
}
