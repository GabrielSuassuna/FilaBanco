#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logtree.h"

void log_inicializar(Log **l){
    *l = NULL;
}

void log_registrar(Log **l, int conta, int classe, int timer, int caixa){
    Log *novoElemento;
    Log *auxiliar;
    
    novoElemento = malloc(sizeof(Log));
    novoElemento->conta = conta;
    novoElemento->classe = classe;
    novoElemento->timer = timer;
    novoElemento->caixa = caixa;
    

    if (*l == NULL){
        novoElemento->pai = NULL;
        novoElemento->esquerdo = NULL;
        novoElemento->direito = NULL;
        *l = novoElemento;
        return 1;
    } else {
        auxiliar = malloc(sizeof(Log));
        *auxiliar = **l;

        while (*l != NULL) {
            *auxiliar = **l;
            
            if (novoElemento->classe < (*l)->classe) {
                *l = (*l)->esquerdo;
            } else if (novoElemento->classe > (*l)->classe){
                *l = (*l)->direito;
            } else {
                if (novoElemento->conta < novoElemento->conta){
                    *l = (*l)->esquerdo; 
                } else {
                    *l = (*l)->direito;
                }
            }
        }

        novoElemento->pai = auxiliar;
        
        if (novoElemento->conta < auxiliar->conta){
            auxiliar->esquerdo = novoElemento;
        } else {
            auxiliar->direito = novoElemento;
        }
        return 1;
    }
}

int percorrer_arvore_cliente (Log *l) {
    int contador = 0;

    if (l != NULL){
        percorrer_arvore_cliente (l->esquerdo);
        contador = contador + l->timer;
        percorrer_arvore_cliente (l->direito);
    }

    return contador;
}

int percorrer_arvore_tempo (Log *l) {
    int tempo = 0;

    if (l != NULL){
        percorrer_arvore_tempo (l->esquerdo);
        tempo = tempo + l->timer;
        percorrer_arvore_tempo (l->direito);
    }

    return tempo; 
}

float log_media_por_classe(Log **l, int classe){
    Log *auxiliar;
    int tempo_total, tempo_medio, qtd_clientes;

    auxiliar = *l;

    while (auxiliar->classe =! classe) {
        if (auxiliar->classe < classe) {
            auxiliar = auxiliar->esquerdo;
        } else {
            auxiliar = auxiliar->direito;
        }
    }

    tempo_total = log_obter_soma_por_classe(l, classe);
    qtd_clientes = log_obter_contagem_por_classe(l, classe);
    tempo_medio = tempo_total/qtd_clientes;
    return tempo_medio;
}

int log_obter_soma_por_classe(Log **l, int classe){
    Log *auxiliar;
    int tempo;

    while (auxiliar->classe =! classe) {
        if (auxiliar->classe < classe) {
            auxiliar = auxiliar->esquerdo;
        } else {
            auxiliar = auxiliar->direito;
        }
    }

    tempo = percorrer_arvore_tempo(auxiliar);
    return tempo;
}

int log_obter_contagem_por_classe(Log **l, int classe){
    Log *auxiliar;
    int contador;

    while (auxiliar->classe =! classe) {
        if (auxiliar->classe < classe) {
            auxiliar = auxiliar->esquerdo;
        } else {
            auxiliar = auxiliar->direito;
        }
    }

    contador = percorrer_arvore_cliente(auxiliar);
    return contador;

}