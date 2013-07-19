/**
 * @file estatistica.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _ESTATISTICA_H
#define _ESTATISTICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"
#include "tabela_hash.h"
#include "lista_ligada.h"
#include "localidades.h"
#include "camioes.h"
#include "clientes.h"
#include "interface.h"

/**
 * A funcão 'estado_geral' imprime no ecrã o estado geral, ou seja, as diferentes localidades, as ligações entre estas e os clientes e os camiões nas suas localidades.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 * @returns A funcão retorna o estado geral do sistema.
 */
int estado_geral (THash*** listas, LLigada*** listae);

/**
 * A funcão 'estatistica_clientes' imprime no ecrã o estado dos clientes, ou seja, os clientes com mais encomendas e os clientes com mais gastos.
 * @param 'listae' Lista ligada.
 * @returns A funcão retorna o estado geral dos clientes.
 */
int estatistica_clientes (LLigada*** listae);

/**
 * A funcão 'estatistica_localidades' imprime no ecrã o estado das localidades, ou seja, as localidades mais e menos requisitadas.
 * @param 'listae' Lista ligada.
 * @returns A funcão retorna o estado geral das localidades.
 */
int estatistica_localidades (LLigada*** listae);


/**
 * A funcão 'criar_estatistica' cria as estatísticas do programa, se ja existir actualiza as mesmas.
 * @param 'listas' Tabela de Hash.
 * @param 'listae' Lista ligada.
 * @returns A funcão retorna as listas actualizadas.
 */
int criar_estatistica (THash*** listas, LLigada*** listae);
#endif
