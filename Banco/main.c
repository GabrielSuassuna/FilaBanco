#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

int main(int argc, char const *argv[]){
    int teste, i;
    Escalonador escalonador;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    strcpy(nomeArquivoEntrada, "entrada-0001.txt");
    //strcpy(nomeArquivoSaida, "saida-0001.txt");
    e_conf_por_arquivo(&escalonador, nomeArquivoEntrada);
    teste = e_obter_prox_num_conta(&escalonador);
    for (i = 0; i <= 30; i++){
        if (teste != -1){
            printf("%d\n", teste);
        }
        teste = e_obter_prox_num_conta(&escalonador);
    }
    
    //e_rodar(&escalonador, nomeArquivoEntrada, nomeArquivoSaida);

    return 0;
}
