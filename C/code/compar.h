/**
 * @file compar.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */


#ifndef _COMPAR_H
#define	_COMPAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * A funcão 'compar_int' faz a comparação entre dois inteiros.
 * @param 'int1' Primeiro número.
 * @param 'int2' Segundo número.
 * @returns A funcão retorna '1' quando o primeiro número é maior que o segundo, retorna '-1' quando o segundo número é maior que o primeiro e retorna '0' quando os dois são iguais.
 */
 int compar_int (void* int1,void* int2);
 
/**
 * A funcão 'compar_char' faz a comparação entre duas strings.
 * @param 'c1' Primeira string.
 * @param 'c2' Segunda string.
 * @returns A funcão retorna '1' quando, alfabeticamente, a primeira string situa-se primeiro que a segunda, retorna '-1' quando a segunda string situa-se depois da primeira e retorna '0' quando as duas são iguais.
 */
int compar_char (void* c1, void* c2);

/**
 * A funcão 'compar_float' faz a comparação entre dois floats.
 * @param 'int1' Primeiro número.
 * @param 'int2' Segundo número.
 * @returns A funcão retorna '1' quando o primeiro número é maior que o segundo, retorna '-1' quando o segundo número é maior que o primeiro e retorna '0' quando os dois são iguais.
 */
int compar_float (void* f1, void* f2);

/**
 * A funcão 'compar_long' faz a comparação entre dois inteiros longos.
 * @param 'int1' Primeiro número.
 * @param 'int2' Segundo número.
 * @returns A funcão retorna '1' quando o primeiro número é maior que o segundo, retorna '-1' quando o segundo número é maior que o primeiro e retorna '0' quando os dois são iguais.
 */
int compar_long (void* long1, void* long2);

#endif
