/**
 * @file fhash.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */


#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"
#include "tabela_hash.h"
#include "lista_ligada.h"
#include "localidades.h"
#include "camioes.h"
#include "compar.h"
#include "clientes.h"
#include "ler_interface.h"
#include "estatistica.h"
#include "ficheiros.h"

/**
 @brief Função que limpa o ecrã.
 @param 'tamanho' Tamanho. 
 **/

int limpa_ecra (int tamanho);

/**
 * @brief Função que apresenta o ecrã inicial.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/

int menu_principal (THash** listas[],LLigada** listae[]);

/**
 @brief Função que apresenta as várias opções a realizar dentro das localidades.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerirlocalidades (THash*** listas,LLigada*** listae);


/**
 @brief Função que apresenta as varias operações a realizar sobre ligações. 
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerirligacoes (THash*** listas,LLigada*** listae);


/**
 @brief Função que apresenta as várias opções a realizar sobre camiões.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerircamioes (THash*** listas,LLigada*** listae);


/**
 @brief Função que apresenta as várias opções a realizar com os clientes.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerirclientes (THash*** listas,LLigada*** listae);


/**
 @brief Função que apresenta as várias opções estatísticas.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerirestatistica (THash*** listas,LLigada*** listae);

/**
 @brief Função que apresenta as várias opções de procura de clientes.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_procuraclientes (THash*** listas,LLigada*** listae);
/**
 @brief Função que apresenta as várias opções a realizar com os pedidos.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 **/
int menu_gerirpedidos (THash*** listas,LLigada*** listae);

#endif
