#include "erros.h"

typedef struct erro
{
  char *err_code;
  char *mensagem;
} ERRO;

static ERRO erro[] =
{
  {"E_SUCESS",     "Operação realizada com êxito"},
  {"E_ARGS",      "Erro de argumentos a mais ou a menos"},
  {"E_LOAD",     "Ficheiro nao existe"},
  {"E_SAVE",      "Nao se consegue gravar o ficheiro"},
  {"E_INVARGS",   "Argumentos invalidos"},
  {"E_PROC",      "Elemento nao existe"},
  {"E_OPT",			"Opção inválida"},
  {"E_EXIST",		"Elemento já existe"},
  {"E_MEM",			"Erro de alocacao de memoria"},
  {"E_PATH",         "Não há caminho entre as duas localidades"},
  {"E_CAM",         "Não há camião com capacidade suficiente para a entrega da mercadoria"}
};

/**
 * Reporta o erro escrevendo uma mensagem no standard error
 * @param erro_num O nmero do erro que vem da tabela de erros.
 */
int mensagem_de_erro(int erro_num)
{
  (void) fprintf(stderr, "%s: %s\n",
    erro[erro_num].err_code, erro[erro_num].mensagem);
  return erro_num;
}
