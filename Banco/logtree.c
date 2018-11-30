#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logtree.h"

//Inicializa o registrador l.
void log_inicializar(Log **l){
    *l = NULL;
}

/*Inclui um registro de tempo de atendimento da conta de número “conta”, que faz parte da classe de número
“classe”, que esperou “timer” minutos para ser atendido pelo caixa de número “caixa”.*/
void log_registrar(Log **l, int conta, int classe, int timer, int caixa){
    Log *novoElemento;

    if (*l == NULL){
        novoElemento = malloc(sizeof(Log));
        novoElemento->conta = conta;
        novoElemento->classe = classe;
        novoElemento->timer = timer;
        novoElemento->caixa = caixa;
        novoElemento->esquerdo = NULL;
        novoElemento->direito = NULL;
        novoElemento->pai = NULL;
        *l = novoElemento;
    } else {
        
        if ((*l)->esquerdo != NULL &&  conta < (*l)->conta){
            log_registrar(&(*l)->esquerdo, conta, classe, timer, caixa);
        } else if ((*l)->direito != NULL &&  conta > (*l)->conta){
            log_registrar(&(*l)->direito, conta, classe, timer, caixa);
        } else {
            novoElemento = malloc(sizeof(Log));
            novoElemento->conta = conta;
            novoElemento->classe = classe;
            novoElemento->timer = timer;
            novoElemento->caixa = caixa;
            novoElemento->esquerdo = NULL;
            novoElemento->direito = NULL;
            novoElemento->pai = *l;
            if (conta < (*l)->conta){
                (*l)->esquerdo = novoElemento;
            } else {
                (*l)->direito = novoElemento;
            }
        }
    }
}

//Retorna o tempo médio de espera, em minutos, para a classe de número “classe”.
float log_media_por_classe(Log **l, int classe){
    float tempo_total, qtd_clientes, tempo_medio;

    tempo_total = log_obter_soma_por_classe(l, classe);
    qtd_clientes = log_obter_contagem_por_classe(l, classe);
    tempo_medio = tempo_total/qtd_clientes;
    return tempo_medio;
}

/*Retorna a soma dos tempos de espera de todos os clientes cujas contas fazem parte da classe de número
“classe”.*/
int log_obter_soma_por_classe(Log **l, int classe){
    if (*l == NULL){
        return 0;
    } else {
        if ((*l)->classe != classe){
            return 0 + log_obter_soma_por_classe(&(*l)->esquerdo , classe) + log_obter_soma_por_classe(&(*l)->direito , classe);
        } else {
            return (*l)->timer + log_obter_soma_por_classe(&(*l)->esquerdo , classe) + log_obter_soma_por_classe(&(*l)->direito , classe);
        }
    }
}

//Retorna a quantidade de clientes atendidos cujas contas são da categoria de número “classe”.
int log_obter_contagem_por_classe(Log **l, int classe){
    if (*l == NULL){
        return 0;
    } else {
        if ((*l)->classe != classe){
            return 0 + log_obter_contagem_por_classe(&(*l)->esquerdo , classe) + log_obter_contagem_por_classe(&(*l)->direito , classe);
        } else {
            return 1 + log_obter_contagem_por_classe(&(*l)->esquerdo , classe) + log_obter_contagem_por_classe(&(*l)->direito , classe);
        }
    }
}