#include "ler_interface.h"
 
int ler_localidade (THash*** listas)
{

	char nome[80], linha[100], id[30];
	
	limpa_ecra(50);
	printf("################# INSERIR LOCALIDADES ################\n");
	printf (" * Insira uma localidade por linha no seguinte formato.\n");
	printf (" * Nome Localidade | Identificador.\n");
	printf (" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if (sscanf (linha,"%[^|] | %[^\n]",nome,id)!=2)
			mensagem_de_erro(1);
			else
			nome[strlen(nome)-1] = '\0';
			int_ins_localidade (listas,nome,id);
		}
	return 0;
}

int remove_localidade (THash*** listas)
{	
	char id[30];
	
	limpa_ecra(50);
	printf("################# REMOVER LOCALIDADES ################\n");
	printf (" * Remova uma localidade por linha, escreva o identificador da localidade.\n * Linha em branco para terminar.\n\n");

	if (fgets(id,30,stdin))
		while (fgets(id,30,stdin) && strcmp(id,"\n"))
		{	
			id[strlen(id)-1]='\0';
			int_rem_localidade (listas,id);
		}	
	return 0;
}

int ins_lig_localidades (THash*** listas)
{
	THash** thash = &((*listas)[0]);
	
	Localidade* l;

	char id[30],linha[100],id2[30];
	float distancia, taxas;
	int i=0;

	limpa_ecra(50);
	printf("######### INSERIR LIGAÇOES ENTRE LOCALIDADES #########\n");
	printf (" * Insira o identificador da localidade que quer adicionar ligações.\n");
	printf (" * Linha em branco para terminar.\n\n");
	
	if (fgets (id,30,stdin))
		while (i<1 && fgets(id,30,stdin)) 
		{
			if (strcmp(id,"\n")==0) return 0;

			id[strlen(id)-1]='\0';
			l = procura_THash(*thash,id);
		
			if (l)
			{
				limpa_ecra(50);
				printf("############ INSERIR LIGAÇOES DA LOCALIDADE ###########\n");
				printf (" * Insira as ligações da localidade com o seguinte formato.\n");
				printf (" * Id Localidade | Distancia | Taxas.\n");
				printf (" * Distancia - kilometros, Taxas - euros.\n");
				printf (" * Formato exemplo: Lisboa | 3,4 | 36,20.\n");
				printf (" * Linha em branco para terminar.\n\n");
					
					while (fgets(linha,100,stdin) && strcmp(linha,"\n")!=0)
					{			
						distancia = 0; taxas = 0;
						if(sscanf (linha,"%[^|] | %f | %f",id2,&distancia,&taxas)!=3)
						mensagem_de_erro(1);
						else
						{
							id2[strlen(id2)-1] = '\0';
							int_ins_lig_local (listas,l,id,id2,distancia,taxas);
						}
					}
				i++;
			}
			else
				mensagem_de_erro(5);
		}
		return 0;
}

int rem_lig_localidades (THash*** listas)
{
	THash** thash = &((*listas)[0]);
	
	char id[30],id2[30];
	int i=0;
	Localidade *l;
	
	limpa_ecra(50);
	printf("######### REMOVER LIGAÇOES ENTRE LOCALIDADES #########\n");
	printf (" * Insira o identificador da localidade que quer remover ligações.\n");
	printf (" * Linha em branco para terminar.\n\n");
	
	if (fgets (id,30,stdin))
		while (i<1 && fgets(id,30,stdin)) 
		{
			if (strcmp(id,"\n")==0) return 0;

			id[strlen(id)-1]='\0';
			l = procura_THash(*thash,id);
		
			if (l)
			{
				limpa_ecra(50);
				printf("############ REMOVER LIGAÇOES DA LOCALIDADE ###########\n");
				printf (" * Insira o id das ligações da localidade para remover.\n");
				printf (" * Linha em branco para terminar.\n\n");
					
					while (fgets(id2,30,stdin) && strcmp(id2,"\n")!=0)
					{	
						id2[strlen(id2)-1]='\0';
						int_rem_lig_local(listas,l,id,id2);
						
					}
			i++;
			}
			else
				mensagem_de_erro(5);
		}
		return 0;
}

int edit_lig_localidades (THash*** listas)
{
	THash** thash = &((*listas)[0]);
	
	char id[30],id2[30],linha[100];
	float distancia=0, taxas=0;
	int i=0;
	Localidade *l;

	limpa_ecra(50);
	printf("######### EDITAR LIGAÇOES ENTRE LOCALIDADES ###########\n");
	printf (" * Insira o identificador da localidade que quer editar ligações.\n");
	printf (" * Linha em branco para terminar.\n\n");
	
	if (fgets (id,30,stdin))
		while (i<1 && fgets(id,30,stdin)) 
		{
			if (strcmp(id,"\n")==0) return 0;

			id[strlen(id)-1]='\0';
			l = procura_THash(*thash,id);
		
			if (l)
			{
				limpa_ecra(50);
				printf("############ EDITAR LIGAÇOES DA LOCALIDADE ###########\n");
				printf (" * Insira as ligações da localidade que quer editar com o seguinte formato.\n");
				printf (" * Id da localidade a editar | Nova Distancia | Novas taxas.\n");
				printf (" * Distancia - kilometros, Taxas - euros.\n");
				printf (" * Formato exemplo: Lisboa | 3,4 | 36,20.\n");
				printf (" * Linha em branco para terminar.\n\n");
					
					while (fgets(linha,100,stdin) && strcmp(linha,"\n")!=0)
					{						
						if(sscanf (linha,"%[^|] | %f | %f",id2,&distancia,&taxas)!=3)
						mensagem_de_erro(1);
						else
						{
							id2[strlen(id2)-1]='\0';
							int_edit_lig_local (l,id2,distancia,taxas);
						}	
						
					 }
			i++;
			}	
			else
				mensagem_de_erro(5);
		}
		return 0;
}


int ins_camiao (THash*** listas)
{
	char linha[100],id[50],matricula[10],localidade[30];
	float custokm=0, capacidade=0;

	
	limpa_ecra(50);
	printf("################# INSERIR CAMIOES ################\n");
	printf(" * Insira um camião com o seguinte formato:\n"); 
	printf(" * Id Localidade | Matricula | Custo km | Capacidade | Informacoes\n"); 
	printf(" * Capacidade - toneladas, Custo - euros.\n"); 
	printf(" * Formato exemplo: 100 | 00-00-AA | 10 | 3.4 | Mercedes,Azul,2012 \n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^|] | %[^|] | %f | %f | %[^\n]", localidade, matricula, &custokm, &capacidade, id)!=5)
				mensagem_de_erro(1);
			else
			{
				localidade[strlen(localidade)-1]='\0';
				matricula[strlen(matricula)-1]='\0';
				int_ins_camiao(listas, id, matricula, localidade, custokm, capacidade);
			}
		}
	return 0;
}

int rem_camiao (THash*** listas)
{	
	char linha[100],matricula[10];
	
	limpa_ecra(50);
	printf("################# REMOVER CAMIOES ################\n");
	printf(" * Insira a matrícula do camião a remover.\n");  
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^\n]", matricula)!=1)
			mensagem_de_erro(1);
			else
			int_rem_camiao(listas,matricula);
		}
		return 0;
}

int edit_camiao (THash*** listas)
{
	char linha[100],id[50],matricula[10],localidade[30];
	float custokm=0, capacidade=0;

	
	limpa_ecra(50);
	printf("################# EDITAR CAMIOES ################\n");
	printf(" * Insira os novos dados dos camioes com o seguinte formato:\n"); 
	printf(" * Identificador da localidade | Matricula | Custo km | Capacidade | Informações.\n"); 
	printf(" * Capacidade - toneladas, Custo - euros.\n"); 
	printf(" * Formato exemplo: Lisboa | 00-00-AA | 10 | 3,4 | Mercedes,Azul,2012 \n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^|] | %[^|] | %f | %f | %[^\n]", localidade, matricula, &custokm, &capacidade, id)!=5)
			mensagem_de_erro(1);
			else
			{
				localidade[strlen(localidade)-1]='\0';
				matricula[strlen(matricula)-1]='\0';
				int_edit_camiao(listas, id, matricula, localidade, custokm, capacidade);
			}
			
		}
		return 0;
}


int ins_clientes (THash*** listas)
{
	char linha[200],nome[80],localidade[80],mail[80]; 
	long int contribuinte; 
	
	limpa_ecra(50);
	printf("################# INSERIR CLIENTES ################\n");
	printf(" * Insira um cliente com o seguinte formato:\n"); 
	printf(" * Nome | Mail | Morada do cliente | Contribuinte \n"); 
	printf(" * Formato exemplo: António | antonio22@gmail.com | Torres Novas | 131456263\n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,200,stdin))
		while (fgets(linha,200,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^|] | %[^|] | %[^|] | %ld", nome, mail, localidade, &contribuinte)!=4)
			mensagem_de_erro(1);
			else 
			{
				nome[strlen(nome)-1]='\0';
				mail[strlen(mail)-1]='\0';
				localidade[strlen(localidade)-1]='\0';
				int_ins_clientes (listas, nome, mail, localidade, contribuinte);
			}
		}
	return 0;
}
		
 
int rem_cliente (THash*** listas)
{
	char nome[80];
	long int contribuinte;
	
	limpa_ecra(50);
	printf("################# REMOVER CLIENTES ################\n");
	printf(" * Insira o contribuinte do cliente que quer remover.\n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(nome,80,stdin))
		while (fgets(nome,80,stdin) && strcmp(nome,"\n"))
		{
			if(sscanf (nome,"%ld",&contribuinte)!=1)
			mensagem_de_erro(1);
			else
			int_rem_clientes (listas, contribuinte);
			strcpy (nome,"\n");
		}
		return 0;
}

int edit_clientes (THash*** listas)
{
	char linha[200],localidade[80],mail[80]; 
	long int contribuinte; 
	
	limpa_ecra(50);
	printf("################# EDITAR CLIENTES ################\n");
	printf(" * Insira os novos dados de um cliente com o seguinte formato:\n"); 
	printf(" * Novo Mail | Contribuinte | Nova Morada \n"); 
	printf(" * Formato exemplo: antonio@gmail.com | 131456263 | Torres Novas \n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^|] | %ld | %[^\n]", mail, &contribuinte, localidade)!=3)
				mensagem_de_erro(1);
			else 
			{
				mail[strlen(mail)-1]='\0';
				int_edit_clientes (listas, mail, contribuinte, localidade);
			}
		}
	return 0;
}

int procura_clientesc (THash*** listas)
{
	char linha[100]; 
	long int contribuinte; 
	
	limpa_ecra(50);
	printf("################ PROCURAR CLIENTES ##############\n");
	printf(" * Insira o contribuinte do cliente.\n"); 
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%ld" , &contribuinte)!=1)
				mensagem_de_erro(1);
			else 
				int_procura_clientesc(listas,contribuinte);
		}
	return 0;	
}

int procura_clientesn (THash*** listas)
{
	char linha[100],nome[80]; 
	
	limpa_ecra(50);
	printf("################ PROCURAR CLIENTES ##############\n");
	printf(" * Insira o nome do cliente.\n"); 
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^\n]" , nome)!=1)
				mensagem_de_erro(1);
			else 
				int_procura_clientesn(listas,nome);
		}
	return 0;	
}

int ins_pedido (THash*** listas)
{
	char linha[200],loc1[30],loc2[30],descricao[50];
	float peso; 
	long int contribuinte;
	
	limpa_ecra(50);
	printf("################ INSERIR PEDIDO ##############\n");
	printf(" * Insira um novo pedido no seguinte formato: \n");
	printf(" * Contribuinte | ID Partida | ID Destino | Peso | Descrição.\n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,200,stdin))
		while (fgets(linha,200,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%ld | %s | %s | %f | %[^\n]" ,&contribuinte,loc1,loc2,&peso,descricao)!=5)
				mensagem_de_erro(1);
			else 
			{
				if(int_ins_pedido(listas,contribuinte,loc1,loc2,peso,descricao))
					return 0;
			}
		}
	return 0;	
}

int sair(THash*** listas)
{
	escreve_clientes (listas);
	escreve_localidades (listas);	
	escreve_camioes(listas);
	exit(1);
}

int procura_pedido (THash*** listas)
{
	char linha[200];
	 
	
	
	limpa_ecra(50);
	printf("################ PROCURAR PEDIDO ##############\n");
	printf(" * Insira a descrição do pedido. \n");
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,200,stdin))
		while (fgets(linha,200,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^\n]" ,linha)!=1)
				mensagem_de_erro(1);
			else 
				int_procura_pedido(listas,linha);
		}
	return 0;	
}

int procura_camioesm (THash*** listas)
{
	char linha[100],matricula[80]; 
	
	limpa_ecra(50);
	printf("################ PROCURAR CAMIÕES ##############\n");
	printf(" * Insira a matricula do camião.\n"); 
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^\n]" , matricula)!=1)
				mensagem_de_erro(1);
			else 
				int_procura_camioesm(listas,matricula);
		}
	return 0;	
}

int procura_localidadesid (THash*** listas)
{
	char linha[100],id[80]; 
	
	limpa_ecra(50);
	printf("################ PROCURAR LOCALIDADES ##############\n");
	printf(" * Insira a identificação da localidade.\n"); 
	printf(" * Linha em branco para terminar.\n\n");
	
	if (fgets(linha,100,stdin))
		while (fgets(linha,100,stdin) && strcmp(linha,"\n"))
		{
			if(sscanf(linha, "%[^\n]" , id)!=1)
				mensagem_de_erro(1);
			else 
				int_procura_localidadesid(listas,id);
		}
	return 0;	
}
