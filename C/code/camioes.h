/**
 * @file camioes.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _CAMIOES_H
#define	_CAMIOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct sCamiao
 * @brief EStrutura que guarda os dados de um determinado camião.
 */
typedef struct sCamiao{
/**
 * @var id;
 * @brief Identificação do camião.
 */
	char id[50];
/**
 * @var matricula;
 * @brief Matricula do camião.
 */
char matricula[10];
/**
 * @var custokm;
 * @brief Gastos do camião por quilómetro.
 */
	float custokm;
/**
 * @var capacidade;
 * @brief Capacidade total do camião.
 */
	float capacidade;
/**
 * @var localidade;
 * @brief Localidade onde se encontra o camião em determinado momento.
 */
	char localidade[30];
}Camiao;

/**
 * @struct sACamiao
 * @brief Estrutura que guarda o apontador para um camião.
 */
typedef struct sACamiao
{
/**
 * @var camiao;
 * @brief Apontador para um camião.
 */	
	Camiao* camiao;
}ACamiao;



/**
 * A funcão 'da_custokm' dá os gastos de um camião camião por quilómetro.
 * @param 'c' Camião.
 * @returns A funcão retorna um apontador para o valor do custo por quilómetro do camião.
 */
void* da_custokm (void* c);

/**
 * A funcão 'da_matricula' dá a matricula de um camião.
 * @param 'c' Camião.
 * @returns A funcão retorna um apontador para a matricula de um camião.
 */
void* da_matricula (void* c);

/**
 * A funcão 'da_acustokm' dá os gastos de um camião camião por quilómetro.
 * @param 'c' Camião.
 * @returns A funcão retorna um apontador para o valor do custo por quilómetro do camião.
 */
void* da_acustokm (void* c);

/**
 * A funcão 'da_amatricula' dá a matricula de um camião.
 * @param 'c' Camião.
 * @returns A funcão retorna um apontador para a matricula de um camião.
 */
void* da_amatricula (void* c);


/**
 * A funcão 'da_localidade' dá o nome de uma localidade.
 * @param 'l' Localidade.
 * @returns A funcão retorna um apontador para o nome da localidade.
 */
void* da_localidade (void* l);

#endif
