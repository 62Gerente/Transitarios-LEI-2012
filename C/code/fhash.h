/**
 * @file fhash.h
 * @brief Ficheiro .h (header) do fhash.c
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _FHASH_H
#define _FHASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A funcão 'fchar_Hash' é a função de hash, que atribui a uma chave (uma string), uma posição do array.
 * @param 'elem' Chave.
 * @param 'nrelem' Número de posições do array.
 * @returns A funcão retorna um inteiro que é a posição do array.
 */
int fchar_Hash(void *elem, int nrelem);

/**
 * A funcão 'flong_Hash' é a função de hash, que atribui a uma chave (um inteiro longo), uma posição do array.
 * @param 'elem' Chave.
 * @param 'nrelem' Número de posições do array.
 * @returns A funcão retorna um inteiro que é a posição do array.
 */
int flong_Hash(void *elem, int nrelem);

#endif
