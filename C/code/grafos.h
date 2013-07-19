#ifndef _GRAFOS_H
#define	_GRAFOS_H
#define    _VIS_WHITE  -1 /**Não visitado*/
#define    _VIS_GREY   0 /** Na orla*/
#define    _VIS_BLACK  1 /**Visitado*/


#include "lista_ligada.h"
#include "tabela_hash.h"
#include "localidades.h"
#include "fhash.h"
#include "compar.h"
#include "camioes.h"



/**
 * @struct dij_elem;
 * @brief Estrutura que guarda um caminho para uma localidade.
 */
typedef struct dij_elem {
/**
 * @var id;
 * @brief Identificador da localidade.
 */
    char id[30];
   /**
 * @var km;
 * @brief Distância em quilómetros entre a localidade e a localidade de partida.
 */
    float km;
/**
 * @var taxas;
 * @brief Valor das taxas correspondente ao percurso.
 */
    float taxas;
/**
 * @var custokm;
 * @brief Custo por quilómetro corresponde ao percurso.
 */
    float custokm;
/**
 * @var idpai;
 * @brief Identificação da localidade de partida.
 */
    char idpai[30];
/**
 * @var vis;
 * @brief Variável que indica se a localidade foi ou não visitada.
 */
    int vis;
} *DijElem;



/**
 * @struct DijResult;
 * @brief Tabela de Hash de elementos DijElem.
 */
typedef THash* DijResult;
/**
 * A função 'caminho_mais_barato' calcula o caminho mais barato entre duas localidades.
 * @param 'thash' Tabele da Hash.
 * @param 'partida' Identificador da localidade de partida.
 * @param 'destino' Identificador da localidade de destino.
 * @param 'custokm' Custo por quilómnetro entre as duas localidades.
 */
DijResult caminho_mais_barato(THash* thash, char* partida, char* destino, float custokm);

/**
 * A função 'verifica_prox_nodo' verifica qual é o próximo nodo a visitar.
*/

int verifica_prox_nodo(void *elem, void *params);

/**
 * A função 'caminhomb_aux' calcula o caminho entre duas localidades.
 */
 
void caminhomb_aux(void *data, void *params);

/**
 * A função 'caminho_mais_barato' calcula o caminho mais barato até ao primeiro camião.
 * @param 'thash' Tabele da Hash.
 * @param 'destino' Identificador da localidade de destino.
 * @param 'peso' Peso da mercadoria.
 * @param 'res' Variável que indica se encontrou algum camião ou não.
 * @param 'c' Camião.
 */
DijResult camiao_mais_barato(THash* thash, char* destino, float peso, int* res, Camiao** c);

/**
 * A função 'verifica_prox_nodo_camioes' verifica qual é o próximo nodo a visitar.
 */
int verifica_prox_nodo_camioes(void *elem, void *params);

/**
 * A função 'caminhomb_aux_camioes' calcula o caminho entre duas localidades.
 */
void caminhomb_aux_camioes(void *elem, void *params);

#endif	
