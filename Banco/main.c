#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

int main(int argc, char const *argv[]){
    Escalonador escalonador;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    
    if (strlen(argv[1]) == 1) strcpy(nomeArquivoEntrada, "entrada-000");
    else if (strlen(argv[1]) == 2) strcpy(nomeArquivoEntrada, "entrada-00");
    else strcpy(nomeArquivoEntrada, "entrada-0");
    
    strcat(nomeArquivoEntrada, argv[1]);
    strcat(nomeArquivoEntrada, ".txt");
    
    strcpy(nomeArquivoSaida, "saida.txt");
    e_rodar(&escalonador, nomeArquivoEntrada, nomeArquivoSaida);
    return 0;
}
