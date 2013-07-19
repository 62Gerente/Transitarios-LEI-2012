/**
 * @file clientes.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */


#ifndef _LOCALIDADES_H
#define	_LOCALIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"

/**
 * @struct sLocalidade;
 * @brief Estrutura que guarda os dados de uma localidade.
 */
typedef struct sLocalidade{
/**
 * @var nome;
 * @brief Nome da localidade.
 */
  char nome[80];
/**
 * @var id;
 * @brief Identificão da localidade.
 */  
  char id[30];
/**
 * @var nrservicos;
 * @brief Nº de serviços de/para a localidade;  
 */
 int nrservicos;
/**
 * @var ligacoes;
 * @brief Lista de localidades adjacentes com destino na localidade.
 */
	LLigada* ligacoes;
/**
 * @var adjacentes;
 * @brief Lista de localidades adjacentes com partida na localidade.
 */	
	LLigada* adjacentes;
/**
 * @var camioes;
 * @brief Lista de camioes ordena por custo/Km disponiveis na localidade.
 */	
	LLigada* camioes;

}Localidade;


/**
 * @struct sELocalidade;
 * @brief Estrutura que guarda os dados suficientes de uma localidade para efeitos estatisticos;
 */
 
typedef struct sELocalidade
{
	/**
 * @var id;
 * @brief id da localidade.
 */
	char id[30];
	/**
 * @var nrservicos;
 * @brief Numero de serviços de/para uma localidade.
 */
	int nrservicos;
}ELocalidade;


/**
 * @struct sLIgacao;
 * @brief Estrutura que guarda os dados de uma ligaçao entre duas localidades.
*/
typedef struct sLigacao{

/**
 * @var id;
 * @brief id da localidade de destino.
 */	
	char id[30];
/**
 * @var apl;
 * @brief Apontador para a respectiva localidade.
 */
	Localidade* apl;
	
/**
 * @var distancias;
 * @brief distancia entre duas localidades.
 */	
	float distancia;
	
/**
 * @var taxas;
 * @brief Taxas associadas a essa ligação.
 */	
	float taxas;
}Ligacao;

/**
 * @struct sAdjacente;
 * @brief Estrutura que guarda o nome de uma localidade adjacente.
*/
typedef struct sAdjacente{
/**
 * @var nome;
 * @brief Identificador da localidade.
 */
	char id[30];
}Adjacente;

/**
 * A funcão 'da_localidade' dá o nome de uma dada localidade.
 * @param 'l' Localidade.
 * @returns A funcão retorna um apontador para o nome da localidade.
 */
void* da_localidade (void* l);

/**
 * A funcão 'da_taxas' dá o valor das taxas de uma dada ligação.
 * @param 'l' Ligação.
 * @returns A funcão retorna um apontador para o valor da ligação.
 */
void* da_taxas (void* l);

/**
 * A funcão 'da_nomeligacao' dá o nome da localidade de destino de uma dada ligação.
 * @param 'l' Ligação.
 * @returns A funcão retorna um apontador para o nome da localidade de destino de ligação.
 */
void* da_idligacao (void* l);

/**
 * A funcão 'da_adjacente' dá o nome de uma localidade adjacente.
 * @param 'a' Adjacente.
 * @returns A funcão retorna um apontador para o id de uma localidade adjacente.
 */
void* da_adjacente (void* a);

/**
 * A funcão 'da_e_nrservicos' dá o número de serviços de uma dada localidade.
 * @param 'el' Localidade.
 * @returns A funcão retorna um apontador para o número de serviços.
 */
void* da_e_nrservicos (void* el);

/**
 * A funcão 'da_e_idlocal' dá a identificação de uma dada localidade.
 * @param 'el' Identificação da localidade.
 * @returns A funcão retorna um apontador para a identificação da localidade.
 */
void* da_e_idlocal (void* el);
/**
 * A funcão 'da_idlocalidade' dá a identificação de uma dada localidade.
 * @param 'el' Identificação da localidade.
 * @returns A funcão retorna um apontador para a identificação da localidade.
 */
void* da_idlocalidade (void* l);
#endif
