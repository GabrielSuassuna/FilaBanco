#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

//Inicializa a fila.
void f_inicializar (Fila_FIFO **fila){
    *fila = NULL;
}

/*Insere um determinado valor inteiro indexado por um valor de chave na fila. Retorna 1 se a inserção for bem
sucedida e 0 se houver algum problema (duplicação de chave ou falta de memória).*/
int f_inserir (Fila_FIFO **fila, int chave, int valor){
    Fila_FIFO *novoElemtento;
    int qtde_elementos, teste_chave;
    
    qtde_elementos = f_num_elementos(fila);
    if (qtde_elementos != 0){
        while (qtde_elementos == 0){
            teste_chave = f_consultar_chave_por_posicao(fila, qtde_elementos);
            if (teste_chave == chave){
                return 0;
            }
            qtde_elementos--;
        }
    }

    novoElemtento = malloc(sizeof(Fila_FIFO));
    novoElemtento->chave = chave;
    novoElemtento->valor = valor;

    if (*fila == NULL) {
        if (novoElemtento != NULL){
            novoElemtento->proximo = NULL;
            *fila = novoElemtento;
            return 1;     
        } else {
            return 0;
        }
    } else {
        if (novoElemtento != NULL){
            novoElemtento->proximo = *fila;
            *fila = novoElemtento;
            return 1;  
        } else {
            return 0;
        }
    }
}

//Retorna o número de chave do próximo elemento da fila, retirando-o da fila. Retorna -1 se a fila estiver vazia.
int f_obter_proxima_chave (Fila_FIFO **fila){
    int chave;
    Fila_FIFO *auxiliar;

    auxiliar = *fila;

    if (*fila != NULL) {
        if ((*fila)->proximo == NULL) {
            chave = (*fila)->chave;
            free(*fila);
            *fila = NULL;
            return chave;
        } else {
            while (auxiliar->proximo->proximo != NULL){
                auxiliar = auxiliar->proximo;
            }
            chave = auxiliar->proximo->chave;
            free(auxiliar->proximo);
            auxiliar->proximo = NULL;
            return chave;
        }
    } else {
        return -1;
    }
}

//Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proxima_chave (Fila_FIFO **fila){
    int chave;

    if (*fila != NULL) {
        chave = f_consultar_chave_por_posicao(fila, 1);
        return chave;
    } else {
        return -1;
    }
}

//Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.
int f_consultar_proximo_valor (Fila_FIFO **fila){
    int valor;

    if (*fila != NULL) {
        valor = f_consultar_valor_por_posicao(fila, 1);
        return valor;
    } else {
        return -1;
    }
}

//Retorna o número de elementos presentes na fila.
int f_num_elementos (Fila_FIFO **fila){
    int contador = 0;
    Fila_FIFO *auxiliar;

    auxiliar = *fila;

    if (auxiliar != NULL) {
        if (auxiliar->proximo == NULL){
            contador++;
            return contador;
        } else {
            contador++;
            while(auxiliar->proximo != NULL){
                contador++;
                auxiliar = auxiliar->proximo;  
            }
            return contador;
        }
    } else {
        return contador;
    }
}

/*Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1. A posição
se inicia em 1.*/
int f_consultar_chave_por_posicao (Fila_FIFO **fila, int posicao){ 
    int chave, posicaoTemp;
    Fila_FIFO *auxiliar;

    auxiliar = *fila;
    posicaoTemp = f_num_elementos(fila);

    while (auxiliar != NULL && posicaoTemp != posicao) {
        auxiliar = auxiliar->proximo;
        posicaoTemp--;
    }
    if (auxiliar == NULL){
        return -1;
    } else {
        chave = auxiliar->chave;
        return chave;
    }
    
}

/*Retorna o valor do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1. A posição
se inicia em 1.*/
int f_consultar_valor_por_posicao (Fila_FIFO **fila, int posicao){
    int valor, posicaoTemp;
    Fila_FIFO *auxiliar;

    auxiliar = *fila;
    posicaoTemp = f_num_elementos(fila);

    while (auxiliar != NULL && posicaoTemp != posicao) {
        auxiliar = auxiliar->proximo;
        posicaoTemp--;
    }
    if (auxiliar == NULL){
        return -1;
    } else {
        valor = auxiliar->valor;
        return valor;
    } 
}