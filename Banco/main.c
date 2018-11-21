#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main(int argc, char const *argv[])
{
    int x,cont, pos;
    Fila_FIFO *fila;
    f_inicializar(&fila);
    f_inserir(&fila, 1, 1);
    f_inserir(&fila, 2, 2);
    f_inserir(&fila, 3, 3);
    f_inserir(&fila, 4, 4);
    //x = f_obter_proxima_chave(&fila);
    //printf ("%d\n", x);
    //x = f_obter_proxima_chave(&fila);
    //printf ("%d\n", x);
    //x = f_obter_proxima_chave(&fila);
    //printf ("%d\n", x);
    //cont = f_num_elementos(&fila);
    //printf("%d\n", cont);
    pos = f_consultar_chave_por_posicao(&fila, 4);
    printf("%d\n", pos);
    return 0;
}
