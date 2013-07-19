/**
 * @file clientes.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _CLIENTES_H
#define	_CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"
#include "tabela_hash.h"
#include "camioes.h"
/**
 * @struct sCliente;
 * @brief Estrutura que guarda os dados de um determinado cliente.
 */
typedef struct sCliente{
	
/**
 * @var nome;
 * @brief Nome do cliente.
 */
	char nome[80];
/**
 * @var localidade;
 * @brief Morada do cliente.
 */
	char localidade[80];
/**
 * @var mail;
 * @brief Email do cliente.
 */
	char mail[80];
/**
 * @var contribuinte;
 * @brief Número de contribuinte do cliente.
 */
	long int contribuinte;
/**
 * @var nrpedidos;
 * @brief Número de pedidos do cliente.
 */
	int nrpedidos;
/**
 * @var totalgasto;
 * @brief Quantia total que já gastou em encomendas.
 */
	float totalgasto;
/**
 * @var pedidos;
 * @brief Lista dos pedidos que já efectuou.
 */
	LLigada* pedidos;
}Cliente;

/**
 * @struct sEClientep;
 * @brief Estrutura que guarda os dados de um cliente para efeitos estatisticos.
*/
typedef struct sEClientep
{
	
/**
 * @var contribuinte;
 * @brief Nº de contribuinte de um cliente .
 */	
	
	int long contribuinte;
/**
 * @var nrpedidos;
 * @brief Nº de pedidos feitos por um cliente.
 */	
	int nrpedidos;
}EClientep;

/**
 * @struct sEClienteg;
 * @brief Estrutura que guarda os dados de um cliente para efeitos estatisticos.
*/
typedef struct sEClienteg
{
	
/**
 * @var contribuinte;
 * @brief Nº de contribuinte de um cliente .
 */	
	
	int long contribuinte;
/**
 * @var nrpedidos;
 * @brief Total gasto por um cliente.
 */	
	float totalgasto;
}EClienteg;

/**
 * @struct sPedido;
 * @brief Estrutura que guarda os dados acerca de um pedido efectuado.
 */
typedef struct sPedido{
/**
 * @var cliente;
 * @brief Dados do cliente que efectuou o pedido.
 */
	long int cliente;
/**
 * @var descricao;
 * @brief Descrição do pedido.
 */
	char descricao[50];
/**
 * @var peso;
 * @brief Peso da mercadoria.
 */
	float peso;
/**
 * @var localidadep;
 * @brief Identificador da localidade de partida da mercadoria.
 */
	char localidadep[30];
/**
 * @var localidaded;
 * @brief Identificador da localidade de destino da mercadoria.
 */
	char localidaded[30];
/**
 * @var camião;
 * @brief Camião que vai efectuar o serviço.
 */
	char camiao[10];
/**
 * @var percorrido;
 * @brief Quilómetros que o camião vai percorrer desde a localidade de partida até à localidade de destino.
 */	
	float percorrido;
/**
 * @var custo;
 * @brief Custo total do pedido.
 */	
	float custo;
	
}Pedido;


/**
 * @struct sACliente;
 * @brief Estrutura que guarda o apontador para um cliente.
 */

typedef struct sACliente
{
	/**
 * @var cliente;
 * @brief Apontador para um cliente.
 */
	Cliente* cliente;
}ACliente;

/**
 * A funcão 'da_contribuinte' dá o contribuinte de um dado cliente.
 * @param 'cliente' Cliente.
 * @returns A funcão retorna um apontador para o valor do contribuinte de um dado cliente.
 */
void* da_contribuinte (void* cliente);

/**
 * A funcão 'da_totalgasto' dá a quantia total gasta por um dado cliente em encomendas.
 * @param 'cliente' Cliente.
 * @returns A funcão retorna um apontador para o valor da quantia total gasta de um dado cliente.
 */
void* da_totalgasto (void* cliente);

/**
 * A funcão 'da_nome' dá o nome de um dado cliente.
 * @param 'cliente' Cliente.
 * @returns A funcão retorna um apontador para o nome de um dado cliente.
 */
void* da_nome (void* cliente);

/**
 * A funcão 'da_nrpedidos' dá o número total de pedidos de um dado cliente.
 * @param 'cliente' Cliente.
 * @returns A funcão retorna um apontador para o valor do número total de pedidos de um dado cliente.
 */
void* da_nrpedidos (void* cliente);

/**
 * A funcão 'da_e_nrpedidos' dá o número total de pedidos de um dado cliente. Função necessária para dados estatísticos.
 * @param 'ecliente' Cliente.
 * @returns A funcão retorna um apontador para o valor do número total de pedidos de um dado cliente.
 */
void* da_e_nrpedidos (void* ecliente);

/**
 * A funcão 'da_e_totalgasto' dá a quantia total gasta por um dado cliente em encomendas. Função necessária para dados estatísticos.
 * @param 'ecliente' Cliente.
 * @returns A funcão retorna um apontador para o valor da quantia total gasta de um dado cliente.
 */
void* da_e_totalgasto (void* ecliente);

/**
 * A funcão 'da_e_contp' dá o contribuinte de um dado cliente. Função necessária para dados estatísticos.
 * @param 'ecliente' Cliente.
 * @returns A funcão retorna um apontador para o valor do contribuinte de um dado cliente.
 */
void* da_e_contp (void* ecliente);

/**
 * A funcão 'da_e_contg' dá o contribuinte de um dado cliente. Função necessária para dados estatísticos.
 * @param 'ecliente' Cliente.
 * @returns A funcão retorna um apontador para o valor do contribuinte de um dado cliente.
 */
void* da_e_contg (void* ecliente);


/**
 * A funcão 'da_anome' dá o nome de um dado cliente.
 * @param 'cliente' Cliente.
 * @returns A funcão retorna um apontador para o nome de um dado cliente.
 */
void* da_anome (void* cliente);

/**
 * A funcão 'remover_clienten' remove um cliente da tabela de clientes.
 * @param 'thash' Tabela de Clientes.
 * @param 'chave'  Caracteristica do elemento a remover, neste caso é o nome do cliente.
 * @param 'contribuinte' Nº de contribuinte do cliente    
 * @returns A funcão retorna o resultado da operação.
 */

int remover_clienten (THash** thash, void *chave, int contribuinte);

/**
 * A funcão 'da_descrição' dá a descrição de um dado pedido.
 * @param 'pedido' Pedido.    
 * @returns A funcão retorna um apontador para a descrição do pedido.
 */
void* da_descricao (void* pedido);
#endif
