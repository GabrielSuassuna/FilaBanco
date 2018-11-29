#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"
#include "fila.h"

void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5){
    Fila_FIFO *comum;
    Fila_FIFO *bronze;
    Fila_FIFO *prata;
    Fila_FIFO *ouro;
    Fila_FIFO *premium;
    Escalonador *auxiliar;
    int index, chave, valor;
  
    auxiliar = e;
    f_inicializar(&premium);
    for (index = 0; index <= n_1; index++) {
        valor = f_consultar_proximo_valor(auxiliar->fila);
        chave = f_obter_proxima_chave(auxiliar->fila);
        f_inserir(&premium, chave, valor);
    }

    auxiliar = auxiliar->proximo;
    f_inicializar(&ouro);
    for (index = 0; index <= n_2; index++) {
        valor = f_consultar_proximo_valor(auxiliar->fila);
        chave = f_obter_proxima_chave(auxiliar->fila);
        f_inserir(&ouro, chave, valor);
    }

    auxiliar = auxiliar->proximo;
    f_inicializar(&prata);
    for (index = 0; index <= n_3; index++) {
        valor = f_consultar_proximo_valor(auxiliar->fila);
        chave = f_obter_proxima_chave(auxiliar->fila);
        f_inserir(&prata, chave, valor);
    }

    auxiliar = auxiliar->proximo;
    f_inicializar(&bronze);
    for (index = 0; index <= n_4; index++) {
        valor = f_consultar_proximo_valor(auxiliar->fila);
        chave = f_obter_proxima_chave(auxiliar->fila);
        f_inserir(&bronze, chave, valor);
    }

    auxiliar = auxiliar->proximo;
    f_inicializar(&comum);
    for (index = 0; index <= n_5; index++) {
        valor = f_consultar_proximo_valor(auxiliar->fila);
        chave = f_obter_proxima_chave(auxiliar->fila);
        f_inserir(&comum, chave, valor);
    }

    
}


int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes){

}

int e_obter_prox_num_conta(Escalonador *e);

int e_consultar_prox_num_conta (Escalonador *e);

int e_consultar_prox_qtde_oper (Escalonador *e);

int e_consultar_prox_fila (Escalonador *e);

int e_consultar_qtde_clientes (Escalonador *e);

int e_consultar_tempo_prox_cliente (Escalonador *e);

int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf);

void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out){
    e_conf_por_arquivo(e, nome_arq_in);
}