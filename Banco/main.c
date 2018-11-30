#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

int main(int argc, char const *argv[]){
    int teste;
    Escalonador escalonador;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    strcpy(nomeArquivoEntrada, "entrada-0001.txt");
    strcpy(nomeArquivoSaida, "saida.txt");
    e_rodar(&escalonador, nomeArquivoEntrada, nomeArquivoSaida);
    return 0;
}
