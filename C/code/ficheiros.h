#ifndef _FICHEIROS_H
#define	_FICHEIROS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"
#include "interaccao.h"
#include "localidades.h"



int ler_pedidos_teste (THash*** listas);
/**
 * A funcão 'ler_localidades_teste' lê as localidades de um ficheiro (dados teste).
 * @param 'listas' Tabela de Hash.
 */
int ler_localidades_teste (THash*** listas);
/**
 * A funcão 'ler_ligacoes_teste' lê as ligaçoes entre localidades de um ficheiro (dados teste).
 * @param 'listas' Tabela de Hash.
 */
int ler_ligacoes_teste (THash*** listas);
/**
 * A funcão 'ler_clientes_teste' lê os clientes de um ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int ler_clientes_teste (THash*** listas);
/**
 * A funcão 'escreve_localidades' escreve as características das localidades num ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int escreve_localidades (THash*** listas);
/**
 * A funcão 'ler_localidades' lê as localidades de um ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int ler_localidades (THash*** listas);
/**
 * A funcão 'ler_clientes' lê os clientes de um ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int ler_clientes (THash*** listas);
/**
 * A funcão 'escreve_clientes' escreve as características dos clientes num ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int escreve_clientes (THash*** listas);
/**
 * A funcão 'ler_camioes' lê os camiões de um ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int ler_camioes (THash*** listas);
/**
 * A funcão 'escreve_camioes' escreve as características dos camiões num ficheiro.
 * @param 'listas' Tabela de Hash.
 */
int escreve_camioes (THash*** listas);
#endif
