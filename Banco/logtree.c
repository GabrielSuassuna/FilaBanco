#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logtree.h"

void log_inicializar(Log **l){
    *l = NULL;
}

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

float log_media_por_classe(Log **l, int classe){
    float tempo_total, qtd_clientes, tempo_medio;

    tempo_total = log_obter_soma_por_classe(l, classe);
    qtd_clientes = log_obter_contagem_por_classe(l, classe);
    tempo_medio = tempo_total/qtd_clientes;
    return tempo_medio;
}

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