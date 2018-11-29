#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct escalonador{
    struct escalonador *proximo;
    struct escalonador *anterior;
    Fila_FIFO *fila;
} Escalonador;

void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5);

int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes);

int e_obter_prox_num_conta(Escalonador *e);

int e_consultar_prox_num_conta (Escalonador *e);

int e_consultar_prox_qtde_oper (Escalonador *e);

int e_consultar_prox_fila (Escalonador *e);

int e_consultar_qtde_clientes (Escalonador *e);

int e_consultar_tempo_prox_cliente (Escalonador *e);

int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf);

void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out);