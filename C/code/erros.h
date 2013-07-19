#ifndef _ERROS

#define E_SUCESS			 0 /**             Tudo normal               */
#define E_ARGS				 1 /** Erro de argumentos a mais ou a menos  */
#define E_LOAD			     2 /**          Ficheiro nao existe          */
#define E_SAVE				 3 /**  Nao se consegue gravar o ficheiro    */
#define E_INVARGS			 4 /**         Argumentos invalidos          */
#define E_PROC				 5 /** 			Elemento nao existe 		 */
#define E_OPT				 6 /** 			Opção inválida      		 */
#define E_EXIST              7 /**  Elemento a inserir já existe */
#define E_MEM				 8 /**      Erro de alocacao de memoria      */
#define E_PATH          	 9 /** Não há ligação entre as duas localidades*/
#define E_CAM               10 /** Não há camião com capacidade suficiente para a entrega da mercadoria*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reporta o erro escrevendo uma mensagem no standard error
 * @param erro_num O nmero do erro que vem da tabela de erros.
 */
int mensagem_de_erro(int erro_num);



#endif
