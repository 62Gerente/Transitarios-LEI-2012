/**
 * @file tabela_hash.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _TABELA_HASH_H
#define _TABELA_HASH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"
#include "lista_ligada.h"


/**
 * @struct sTHash;
 * @brief Define uma tabela de hash.
 */
typedef struct sTHash{
/**
 * @var lista;
 * @brief Array de listas ligadas.
 */
	ELigada** lista;
/**
 * @var nrelem;
 * @brief Número de elementos inseridos na tabela de hash.
 */
	int nrelem;
/**
 * @var nrtotal;
 * @brief Número de posições do array.
 */
	int nrtotal;
/**
 * @var incremento;
 * @brief Número de posições a incrementar no array quando este alcançar 80% de ocupação .
 */
	int incremento;
/**
 * @var (*fhash)(void*, int);
 * @brief Função de hash.
 */
	int (*fhash)(void*, int);
/**
 * @var (*comparchave)(void*, void*);
 * @brief Função que compara duas chaves de dois elementos.
 */
	int (*comparchave)(void*, void*);
/**
 * @var (*lerchave)(void*);
 * @brief Função que lê chave de um elemento.
 */
	void* (*lerchave)(void*);
/**
 * @var tamanho;
 * @brief Tamanho da tabela.
 */
	size_t tamanho;
/**
 * @var repetidos;
 * @brief Variável de verificação de repetidos.
 */
	int repetidos;
	
}THash;
/**
 * A funcão 'inicializa_THash' inicializa uma tabela de hash.
 * @param 'nrtotal' Número de posições do array.
 * @param 'incremento' Número de posições a incrementar no array quando este alcançar 80% de ocupação.
 * @param '(*fhash)(void*, int),' Função de hash.
 * @param '(*comparchave)(void*, void*)' Função que compara chaves entre dois elementos.
 * @param '(*lerchave)(void*)' Função que lê chave de um elemento.
 * @param 'tamanho' Tamanha da tabela.
 * @param 'repetidos' Variável de verificação de repetidos.
 * @returns A funcão retorna a tabela de hash já inicializada.
 */
THash* inicializa_THash (int nrtotal, int incremento,int (*fhash)(void*, int),int (*comparchave)(void*, void*), void* (*lerchave)(void*), size_t tamanho,int repetidos);

/**
 * A funcão 'verifica_existe' verifica se existe um determinado elemento numa lista ligada.
 * @param 'lligada' Lista ligada.
 * @param 'chave' Chave.
 * @param '(*comparchave)(void*, void*)' Função que compara chaves entre dois elementos.
 * @param '(*lerchave)(void*)' Função que lê chave de um elemento.
 * @retval "0" Sucesso.
 */
int verifica_existe (ELigada* lligada, void* chave,int (*comparchave)(void*, void*),void* (*lerchave)(void*));

/**
 * A funcão 'insere_THash' insere um elemento na tabela de hash.
 * @param 'thash' Tabela de hash.
 * @param 'elem' Elemento.
 * @returns A funcão retorna a tabela de hash com o elemento inserido.
 * @retval "0" Sucesso.
 */
int insere_THash (THash** thash, void* elem);

/**
 * A funcão 'expandir_THash' duplica a tabela de hash quando a ocupação desta se encontr a 80%.
 * @param 'thash' Tabela de hash.
 * @returns A funcão retorna a tabela de hash já expandida.
 * @retval "0" Sucesso.
 */
int expandir_THash (THash** thash) ;

/**
 * A funcão 'remover_THash' remove um dado elemento na tabela de hash.
 * @param 'thash' Tabela de hash.
 * @param 'chave' Chave.
 * @returns A funcão retorna a tabela de hash sem o elemento removido.
 * @retval "0" Sucesso.
 */
int remover_THash(THash** thash, void *chave);

/**
 * A funcão 'procura_THash' procura um dado elemento na tabela de hash.
 * @param 'thash' Tabela de hash.
 * @param 'chave' Chave.
 * @returns A funcão retorna o elemento procurado.
 */
void* procura_THash (THash* thash, void *chave);
/**
 * A funcão 'aplica_THash' aplica uma função aos elementos da tabela de hash.
 * @param 'thash' Tabela de hash.
 * @param '(*function)(void*,void*)' Função a aplicar.
 */
int aplica_THash (THash* thash, int (*function)(void *, void *), void *params);

#endif
