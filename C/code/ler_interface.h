/**
 * @file ler_interface.h
 * @author André Santos, Helena Alves, Ricardo Branco
 * @date ??
 */

#ifndef _LER_LOCALIDADE_H
#define _LER_LOCALIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"
#include "lista_ligada.h"
#include "tabela_hash.h"
#include "interface.h"
#include "interaccao.h"
#include "clientes.h"

/**
 * A funcão 'ler_localidade' imprime no ecrã as informações necessária para inserir localidades e, posteriormente, lê as localidades que o utilizador quer inserir e depois insere-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int ler_localidade (THash*** listas);

/**
 * A funcão 'remove_localidade' imprime no ecrã as informações necessária para remover localidades e, posteriormente, lê as localidades que o utilizador quer remover e depois remove-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int remove_localidade (THash*** listas);

/**
 * A funcão 'ins_lig_localidade' imprime no ecrã as informações necessária para inserir ligações entre localidades e, posteriormente, lê as novas ligações que o utilizador quer inserir e depois insere-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int ins_lig_localidades (THash*** listas);

/**
 * A funcão 'rem_lig_localidade' imprime no ecrã as informações necessária para remover ligações entre localidades e, posteriormente, lê as ligações que o utilizador quer remover e depois remove-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int rem_lig_localidades (THash*** listas);

/**
 * A funcão 'edit_lig_localidade' imprime no ecrã as informações necessária para editar ligações entre localidades e, posteriormente, lê as modificações que o utilizador quer inserir e depois insere-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int edit_lig_localidades (THash*** listas);

/**
 * A funcão 'ins_camiao' imprime no ecrã as informações necessária para inserir camiões e, posteriormente, lê os camiões que o utilizador quer inserir e depois insere-os, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int ins_camiao (THash*** listas);

/**
 * A funcão 'rem_camiao' imprime no ecrã as informações necessária para remover camiões e, posteriormente, lê os camiões que o utilizador quer remover e depois remove-os, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int rem_camiao (THash*** listas);

/**
 * A funcão 'edit_camiao' imprime no ecrã as informações necessária para editar camiões e, posteriormente, lê as modificações que o utilizador quer inserir e depois insere-as, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int edit_camiao (THash*** listas);

/**
 * A funcão 'rem_clientes' imprime no ecrã as informações necessária para remover clientes e, posteriormente, lê os clientes que o utilizador quer remover e depois remove-os, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int rem_cliente (THash*** listas);

/**
 * A funcão 'ins_clientes' imprime no ecrã as informações necessária para inserir clientes e, posteriormente, lê os clientes que o utilizador quer inserir e depois insere-os, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int ins_clientes (THash*** listas);
/**
 * A funcão 'edit_clientes' imprime no ecrã as informações necessária para editar clientes e, posteriormente, lê as  caracteristicas dos clientes que o utilizador quer editar e depois altera os campos do cliente, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int edit_clientes (THash*** listas);
/**
 * A funcão 'procura_clientesc' Função que procura um cliente por numero de contribuinte 
 * @param 'listas' Tabela de Hash.
 */
int procura_clientesc (THash*** listas);
/**
 * A funcão 'procura_clientesn' Função que procura um cliente por nome.
 * @param 'listas' Tabela de Hash.
 */
int procura_clientesn (THash*** listas);
/**
 * A funcão 'ins_pedido' imprime no ecrã as informações necessárias para inserir um pedido e, posteriormente, lê o pediso que o utilizador quer inserir e depois insere-os, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int ins_pedido (THash*** listas);
/**
 * A funcão 'sair' 
 * @param 'listas' Tabela de Hash.
 */
int sair(THash*** listas);
/**
 * A funcão 'procura_camioesm' imprime no ecrã as informações necessárias para procurar um camião e, posteriormente, lê o camião que o utilizador quer procurar e depois apresenta as suas informações, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int procura_camioesm (THash*** listas);
/**
 * A funcão 'procura_localidadesid' imprime no ecrã as informações necessárias para procurar uma localidade e, posteriormente, lê a localidade que o utilizador quer procurar e depois apresenta as suas informações, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int procura_localidadesid (THash*** listas);
/**
 * A funcão 'procura_pedido' imprime no ecrã as informações necessárias para procurar um pedido e, posteriormente, lê o pedido que o utilizador quer procurar e depois apresenta as suas informações, caso seja possível, através de uma função auxiliar.
 * @param 'listas' Tabela de Hash.
 */
int procura_pedido (THash*** listas);
#endif
