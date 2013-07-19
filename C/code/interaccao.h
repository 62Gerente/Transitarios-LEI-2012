/**
 * @file clientes.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */
 
#ifndef _INTERACCAO_H
#define _INTERACCAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"
#include "interface.h"
#include "tabela_hash.h"
#include "lista_ligada.h"
#include "localidades.h"
#include "camioes.h"
#include "compar.h"
#include "clientes.h"
#include "grafos.h"

/**
 * A funcão 'int_ins_localidade' insere uma localidade na respectiva tabela de hash.
 * @param 'listas' Tabela de Hash.
 * @param 'id' Identificador da localidade.
 * @returns A funcão retorna a tabela de hash já com a dada localidade inserida.
 */
int int_ins_localidade (THash*** listas,char* nome,char* id);

/**
 * A funcão 'int_ins_lig_local' insere uma ligação numa localidade.
 * @param 'listas' Tabela de Hash.
 * @param 'l' Localidade.
 * @param 'id' Identificador da localidade que quer adicionar ligações.
 * @param 'id2' Identificador da da nova localidade da ligação.
 * @param 'distancia' Distância entre as localidades.
 * @param 'taxas' Valor das taxas entre as duas localidades. 
 * @returns A funcão retorna a tabela de hash já com a ligação inserida.
 */
int int_ins_lig_local (THash*** listas,Localidade* l,char* id, char* id2, float distancia, float taxas);

/**
 * A funcão 'int_rem_localidade' remove uma localidade da respectiva tabela de hash.
 * @param 'listas' Tabela de Hash.
 * @param 'id' Identificador da localidade a remover.
 * @returns A funcão retorna a tabela de hash já com a ligação inserida.
 */
int int_rem_localidade (THash*** listas,char* id);

/**
 * A funcão 'int_rem_lig_local' remove uma ligação de uma localidade.
 * @param 'listas' Tabela de Hash.
 * @param 'l' Localidade.
 * @param 'id' Identificador da localidade que quer remover ligações.
 * @param 'id2' Identificador da da nova localidade da ligação.
 * @returns A funcão retorna a tabela de hash sem a ligação removida.
 */
int int_rem_lig_local (THash*** listas,Localidade* l,char* id, char* id2);
/**
 * A função int_edit_lig_local' edita a ligação entre duas localidades.
 * @param 'l' Localidade.
 * @param 'id2' Identificador da da localidade de destino
 * @param 'distacias' Valor da nova distância
 * @param 'distacias' Valor das novas taxas
 * @returns A função retorna a tabela de hash com a ligação editada.
 * */
  
int int_edit_lig_local (Localidade* l, char* id2, float distancias, float taxas);
/**
 * A funcão 'int_ins_camiao' insere um camião.
 * @param 'listas' Tabela de Hash.
 * @param 'id' identificação do camião.
 * @param 'matricula' Matricula do camião.
 * @param 'localidade' localidade onde se encontra o camião.
 * @param 'custokm' Custo por Km de um camião.
 * @param 'capacidade' Capacidade de carga de um camião 
 * @returns A funcão retorna a tabela de hash já com o camiao inserido.
 */

int int_ins_camiao (THash*** listas, char* id, char* matricula, char* localidade, float custokm, float capacidade);
/**
 * A funcão 'int_rem_camiao' remove um camião.
 * @param 'listas' Tabela de Hash.
 * @param 'matricula' Matricula do camião.
 * @returns A funcão retorna a tabela de hash já com o camiao removido.
 */
int int_rem_camiao (THash*** listas, char* matricula);

/**
 * A funcão 'int_edit_camiao' edita um camião.
 * @param 'listas' Tabela de Hash.
 * @param 'id' Nova identificação do camião.
 * @param 'matricula' Matricula do camião.
 * @param 'localidade' Nova localidade onde se encontra o camião.
 * @param 'custokm' Novo Custo por Km de um camião.
 * @param 'capacidade' Nova Capacidade de carga de um camião 
 * @returns A funcão retorna a tabela de hash já com o camiao editado.
 */
int int_edit_camiao (THash*** listas, char* id, char* matricula, char* localidade, float custokm, float capacidade);
/**
 * A funcão 'int_ins_clientes' insere um cliente.
 * @param 'listas' Tabela de Hash.
 * @param 'nome' nome do cliente.
 * @param 'localidade' localidade do cliente.
 * @param 'contribuinte' NIF do cliente 
 * @returns A funcão retorna a tabela de hash já com o cliente o cliente inserido.
 */
int int_ins_clientes (THash*** listas, char* nome,char* mail, char* localidade, long int contribuinte);
/**
 * A funcão 'int_rem_clientes' remove um cliente.
 * @param 'listas' Tabela de Hash.
 * @param 'contribuinte' NIF do cliente.
 * @returns A funcão retorna a tabela de hash já com o cliente removido.
 */
int int_rem_clientes (THash*** listas, long int contribuinte);
/**
 * A funcão 'int_edit_cliente' edita um cliente.
 * @param 'listas' Tabela de Hash.
 * @param 'contribuinte' NIF do cliente.
 * @param 'localidade' Nova localidade do cliente.
 * @returns A funcão retorna a tabela de hash já com o cliente editado.
 */
int int_edit_clientes (THash*** listas,char* mail, long int contribuinte, char* localidade);
/**
 * A função 'int_procura_clientesc' procura um cliente por numero de contribuinte.
 * @param 'listas' Tabela de Hash.
 * @param 'contribuinte' NIF do cliente
 * @returns A função retorna o cliente que possui o NIF passado como argumento, ou erro caso nao exista. 
*/
int int_procura_clientesc(THash*** listas,long int contribuinte);
/**
 * A função 'int_procura_clientesn' procura um cliente por numero de contribuinte.
 * @param 'listas' Tabela de Hash.
 * @param 'nome' NIF do cliente.
 * @returns A função retorna todos os clientes  que possui o nome passado como argumento, ou erro caso nao exista. 
*/
int int_procura_clientesn (THash*** listas,char* nome);
/**
 * A função 'int_procura_camioesm' procura um camião por matrícula.
 * @param 'listas' Tabela de Hash.
 * @param 'matricula' Matrícula do camião.
 * @returns A função retorna o camião que possui a matrícula passada como argumento. 
*/
int int_procura_camioesm(THash*** listas, char* matricula);
/**
 * A função 'int_procura_localidadesid' procura uma localidade através do seu identifacador.
 * @param 'listas' Tabela de Hash.
 * @param 'id' Identificação da localidade.
 * @returns A função retorna a localidadeque que possui a identificação passada como argumento. 
*/
int int_procura_localidadesid(THash*** listas, char* id);
/**
 * A função 'int_procura_pedido' procura um pedido através da sua descrição.
 * @param 'listas' Tabela de Hash.
 * @param 'descrição' Descrição do pedido.
 * @returns A função retorna o pedido que possui a descrição passada como argumento. 
*/
int int_procura_pedido(THash*** listas, char* descricao);
/**
 * A função 'int_ins_pedido' insere um cliente.
 * @param 'listas' Tabela de Hash.
 * @param 'contribuinte' Contribuinte do cliente que efectuou o pedido.
 * @param 'loc1' Identificador da localidade de partida do pedido.
 * @param 'loc1' Identificador da localidade de destino do pedido.
 * @returns A função retorna a tabela de hash já com o pedido inserido. 
*/
int int_ins_pedido(THash*** listas,long int contribuinte,char* loc1,char* loc2,float peso,char* descricao);
#endif
