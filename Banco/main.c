#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

// Gabriel Suassuna Almeida - 412715.
// Pedro Victor Oliveira Carvalho - 417338.

int main(int argc, char const *argv[]){
    Escalonador escalonador;
    char nomeArquivoEntrada[17], nomeArquivoSaida[15];
    
    if (strlen(argv[1]) == 1) strcpy(nomeArquivoEntrada, "entrada-000");
    else if (strlen(argv[1]) == 2) strcpy(nomeArquivoEntrada, "entrada-00");
    else strcpy(nomeArquivoEntrada, "entrada-0");
    
    strcat(nomeArquivoEntrada, argv[1]);
    strcat(nomeArquivoEntrada, ".txt");
    
    if (strlen(argv[1]) == 1) strcpy(nomeArquivoSaida, "saida-000");
    else if (strlen(argv[1]) == 2) strcpy(nomeArquivoSaida, "saida-00");
    else strcpy(nomeArquivoSaida, "saida-0");
    
    strcat(nomeArquivoSaida, argv[1]);
    strcat(nomeArquivoSaida, ".txt");

    e_rodar(&escalonador, nomeArquivoEntrada, nomeArquivoSaida);
    return 0;
}
