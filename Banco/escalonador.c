#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5){
    e = malloc(sizeof(Escalonador));
    f_inicializar(&e->comum);
    f_inicializar(&e->bronze);
    f_inicializar(&e->prata);
    f_inicializar(&e->ouro);
    f_inicializar(&e->premium);
    e->caixas = caixas;
    e->tempoOperacao = delta_t;
    e->disciplina[0] = n_1;
    e->disciplina[1] = n_2;
    e->disciplina[2] = n_3;
    e->disciplina[3] = n_4;
    e->disciplina[4] = n_5;
    e->classeAtual = 1;
    e->contador = e->disciplina[0];
}


int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes){
    if (classe == 1) {
        f_inserir(&e->premium, num_conta, qtde_operacoes);
    }
    if (classe == 2) {
        f_inserir(&e->ouro, num_conta, qtde_operacoes);
    }
    if (classe == 3) {
        f_inserir(&e->prata, num_conta, qtde_operacoes);
    }
    if (classe == 4) {
        f_inserir(&e->bronze, num_conta, qtde_operacoes);
    }
    if (classe == 5) {
        f_inserir(&e->comum, num_conta, qtde_operacoes);
    }
}

int e_obter_prox_num_conta(Escalonador *e){
    int classe, contador, conta =-1;
    classe = e->classeAtual;
    contador = e->contador;
    if (classe == 1) {
        conta = f_obter_proxima_chave(&e->premium);
        contador--;
    }
    if (classe == 2) {
        conta = f_obter_proxima_chave(&e->ouro);
        contador--;
    }
    if (classe == 3) {
        conta = f_obter_proxima_chave(&e->prata);
        contador--;
    }
    if (classe == 4) {
        conta = f_obter_proxima_chave(&e->bronze);
        contador--;
    }
    if (classe == 5) {
        conta = f_obter_proxima_chave(&e->comum);
        contador--;
    }
    if (contador == 0){
        if (classe == 1) {
            classe = 2;
            contador = e->disciplina[1];
        }
        if (classe == 2) {
            classe = 3;
            contador = e->disciplina[2];
        }
        if (classe == 3) {
            classe = 4;
            contador = e->disciplina[3];
        }
        if (classe == 4) {
            classe = 5;
            contador = e->disciplina[4];
        }
        if (classe == 5) {
            classe = 1;
            contador = e->disciplina[0];
        }
    }
    e->classeAtual = classe;
    e->contador = contador;
    return conta;
}

int e_consultar_prox_num_conta (Escalonador *e){
    int classe, conta = -1;
    classe = e->classeAtual;
    if (classe == 1) {
        conta = f_consultar_proxima_chave(&e->premium);
    }
    if (classe == 2) {
        conta = f_consultar_proxima_chave(&e->ouro);
    }
    if (classe == 3) {
        conta = f_consultar_proxima_chave(&e->prata);
    }
    if (classe == 4) {
        conta = f_consultar_proxima_chave(&e->bronze);
    }
    if (classe == 5) {
        conta = f_consultar_proxima_chave(&e->comum);
    }
    return conta;
}

int e_consultar_prox_qtde_oper (Escalonador *e){
    int classe, qtde_operacoes = -1;
    classe = e->classeAtual;
    if (classe == 1) {
        qtde_operacoes = f_consultar_proximo_valor(&e->premium);
    }
    if (classe == 2) {
        qtde_operacoes = f_consultar_proximo_valor(&e->ouro);
    }
    if (classe == 3) {
        qtde_operacoes = f_consultar_proximo_valor(&e->prata);
    }
    if (classe == 4) {
        qtde_operacoes = f_consultar_proximo_valor(&e->bronze);
    }
    if (classe == 5) {
        qtde_operacoes = f_consultar_proximo_valor(&e->comum);
    }
    return qtde_operacoes;
}

int e_consultar_prox_fila (Escalonador *e){
    int classe;
    classe = e->classeAtual;
    if (classe == 1) {
        return 2;
    }
    if (classe == 2) {
        return 3;
    }
    if (classe == 3) {
        return 4;
    }
    if (classe == 4) {
        return 5;
    }
    if (classe == 5) {
        return 1;
    }
}

int e_consultar_qtde_clientes (Escalonador *e){
    int contador = 0;

    contador = f_num_elementos(&e->premium);
    contador = contador + f_num_elementos(&e->ouro);
    contador = contador + f_num_elementos(&e->prata);
    contador = contador + f_num_elementos(&e->bronze);
    contador = contador + f_num_elementos(&e->comum);
}

int e_consultar_tempo_prox_cliente (Escalonador *e){
    
}

int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf);

void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out){
    e_conf_por_arquivo(e, nome_arq_in);
}