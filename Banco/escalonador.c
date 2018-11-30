#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

//Certo
void e_inicializar (Escalonador *e, int caixas, int delta_t, int n_1, int n_2, int n_3, int n_4, int n_5){
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

//Certo
int e_inserir_por_fila (Escalonador *e, int classe, int num_conta, int qtde_operacoes){
    if (classe == 1) {
        f_inserir(&e->premium, num_conta, qtde_operacoes);
    } else if (classe == 2) {
        f_inserir(&e->ouro, num_conta, qtde_operacoes);
    } else if (classe == 3) {
        f_inserir(&e->prata, num_conta, qtde_operacoes);
    } else if (classe == 4) {
        f_inserir(&e->bronze, num_conta, qtde_operacoes);
    } else if (classe == 5) {
        f_inserir(&e->comum, num_conta, qtde_operacoes);
    }
}

//Certo
int e_obter_prox_num_conta(Escalonador *e){
    int classe, contador, conta;
    classe = e->classeAtual;
    contador = e->contador;
    
    if (classe == 1) {
        conta = f_obter_proxima_chave(&e->premium);
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 2) {
        conta = f_obter_proxima_chave(&e->ouro);
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 3) {
        conta = f_obter_proxima_chave(&e->prata);
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 4) {
        conta = f_obter_proxima_chave(&e->bronze);
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 5) {
        conta = f_obter_proxima_chave(&e->comum);
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    }
    
    if (contador == 0){
        if (classe == 1) {
            classe = e_consultar_prox_fila(e);
            e->classeAtual = classe;
            if (classe != 0) {
                contador = e->disciplina[classe - 1];
            }
        } else if (classe == 2) {
            classe = e_consultar_prox_fila(e); 
            e->classeAtual = classe;
            if (classe != 0) {
                contador = e->disciplina[classe - 1];
            }
        } else if (classe == 3) {
            classe = e_consultar_prox_fila(e); 
            e->classeAtual = classe;
            if (classe != 0) {
                contador = e->disciplina[classe - 1];
            }
        } else if (classe == 4) {
            classe = e_consultar_prox_fila(e); 
            e->classeAtual = classe;
            if (classe != 0) {
                contador = e->disciplina[classe - 1];
            }
        } else if (classe == 5) {
            classe = e_consultar_prox_fila(e); 
            e->classeAtual = classe;
            if (classe != 0) {
                contador = e->disciplina[classe - 1];
            }
        }
    }
    
    e->contador = contador;
    return conta;
}

//Certo
int e_consultar_prox_num_conta (Escalonador *e){
    int classe, conta;
    classe = e->classeAtual;
    while (classe != 0){
        if (classe == 1) {
            conta = f_consultar_proxima_chave(&e->premium);
            if (conta == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return conta;
            }
        }
        if (classe == 2) {
            conta = f_consultar_proxima_chave(&e->ouro);
            if (conta == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return conta;
            }
        }
        if (classe == 3) {
            conta = f_consultar_proxima_chave(&e->prata);
            if (conta == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return conta;
            }
        }
        if (classe == 4) {
            conta = f_consultar_proxima_chave(&e->bronze);
            if (conta == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return conta;
            }
        }
        if (classe == 5) {
            conta = f_consultar_proxima_chave(&e->comum);
            if (conta == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return conta;
            }
        }
    }
    return 0;
}

//Certo
int e_consultar_prox_qtde_oper (Escalonador *e){
    int classe, qtde_operacoes;
    classe = e->classeAtual;
    while (classe != 0){
        if (classe == 1) {
            qtde_operacoes = f_consultar_proximo_valor(&e->premium);
            if (qtde_operacoes == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return qtde_operacoes;
            }
        }
        if (classe == 2) {
            qtde_operacoes = f_consultar_proximo_valor(&e->ouro);
            if (qtde_operacoes == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return qtde_operacoes;
            }
        }
        if (classe == 3) {
            qtde_operacoes = f_consultar_proximo_valor(&e->prata);
            if (qtde_operacoes == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return qtde_operacoes;
            }
        }
        if (classe == 4) {
            qtde_operacoes = f_consultar_proximo_valor(&e->bronze);
            if (qtde_operacoes == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return qtde_operacoes;
            }
        }
        if (classe == 5) {
            qtde_operacoes = f_consultar_proximo_valor(&e->comum);
            if (qtde_operacoes == -1){
                classe = e_consultar_prox_fila(e);
            } else {
                return qtde_operacoes;
            }
        }
    }
    return 0;
}

//Certo
int e_consultar_prox_fila (Escalonador *e){
    int classe;
    classe = e->classeAtual;
    
    if (classe == 1){
        if(e->ouro != NULL){
            return 2;
        } else if(e->prata != NULL){
            return 3;
        } else if (e->bronze != NULL) {
            return 4;
        } else if (e->comum != NULL){
            return 5;
        } else {
            return 0;
        }
    }
    if (classe == 2){
        if(e->prata != NULL){
            return 3;
        } else if(e->bronze != NULL){
            return 4;
        } else if (e->comum != NULL) {
            return 5;
        } else if (e->premium != NULL){
            return 1;
        } else {
            return 0;
        }
    }
    if (classe == 3){
        if(e->bronze != NULL){
            return 4;
        } else if(e->comum != NULL){
            return 5;
        } else if (e->premium != NULL) {
            return 1;
        } else if (e->ouro != NULL){
            return 2;
        } else {
            return 0;
        }
    }
    if (classe == 4){
        if(e->comum != NULL){
            return 5;
        } else if(e->premium != NULL){
            return 1;
        } else if (e->ouro != NULL) {
            return 2;
        } else if (e->prata != NULL){
            return 3;
        } else {
            return 0;
        }
    }
    if (classe == 5){
        if(e->premium != NULL){
            return 1;
        } else if(e->ouro != NULL){
            return 2;
        } else if (e->prata != NULL) {
            return 3;
        } else if (e->bronze != NULL){
            return 4;
        } else if (e->comum != NULL){
            return 5;
        } else {
            return 0;
        }
    }
}

//Certo
int e_consultar_qtde_clientes (Escalonador *e){
    int contador = 0;

    contador = f_num_elementos(&e->premium);
    contador = contador + f_num_elementos(&e->ouro);
    contador = contador + f_num_elementos(&e->prata);
    contador = contador + f_num_elementos(&e->bronze);
    contador = contador + f_num_elementos(&e->comum);

    return contador;
}

//Certo
int e_consultar_tempo_prox_cliente (Escalonador *e){
    int verificar, qtde_operacoes, tempo;

    verificar = e_consultar_prox_num_conta(e);
    if (verificar == 0) {
        return -1;
    }

    qtde_operacoes = e_consultar_prox_qtde_oper(e);
    tempo = e->tempoOperacao * qtde_operacoes;
    return tempo;
}

int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf){
    FILE* arquivo_entrada;
    int QtdeCaixas, DTempo, N_1, N_2, N_3, N_4, N_5;
    char classe[10];
    int conta, operacao;
    arquivo_entrada = fopen(nome_arq_conf, "r");

    //se estiver vazio
    if(arquivo_entrada == NULL){
        return 0;
    }
    //recolher informações iniciais
    fscanf(arquivo_entrada,"qtde de caixas = %d\n", &QtdeCaixas);
    fscanf(arquivo_entrada,"delta t = %d\n", &DTempo);
    fscanf(arquivo_entrada,"disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &N_1, &N_2, &N_3, &N_4, &N_5);

    //inicializa o escalonador
    e_inicializar(e, QtdeCaixas, DTempo, N_1, N_2, N_3, N_4, N_5);

    //coleta de informacoes gerais do cliente
    while((fscanf(arquivo_entrada,"%s - conta %d - %d operacao(oes)", classe, &conta, &operacao) != EOF)){

        if(strcmp(classe, "Premium") == 0){
            e_inserir_por_fila(e, 1, conta, operacao);
        }else if(strcmp(classe, "Ouro") == 0){
            e_inserir_por_fila(e, 2, conta, operacao);
        }else if(strcmp(classe, "Prata") == 0){
            e_inserir_por_fila(e, 3, conta, operacao);
        }else if(strcmp(classe, "Bronze") == 0){
            e_inserir_por_fila(e, 4, conta, operacao);
        }else if(strcmp(classe, "Comum") == 0){
            e_inserir_por_fila(e, 5, conta, operacao);
        }
    }
    //finaliza e fecha o arquivo
    fclose(arquivo_entrada);
    return 1;
}

void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out){
    Log *registrador;
    FILE *arquivo_saida;
    int timer = 0, caixa[10], index, qtde_operacoes, conta, classe, verificador, caixaAtual, maior = 0, qtde_clientes, tempoTotal, operacao[5], caixaValor[10];
    float tempoMedio, qtde_Media;
    char classeStr[10];
    e_conf_por_arquivo(e, nome_arq_in);
    arquivo_saida = fopen(nome_arq_out, "w");

    log_inicializar(&registrador);
    verificador = e_consultar_prox_num_conta(e);

    for (index = 0; index < e->caixas; index++){
        caixa[index] = 1;
        caixaValor[index] = 0;
    }
    
    for (index = 0; index < 5; index++){
        operacao[index] = 0;
    }

    while (verificador != 0) {
        for (index = 0; index < e->caixas; index++){
            if (verificador != 0){
                caixa[index] = caixa[index] - 1;
                if (caixa[index] == 0){
                    classe = e->classeAtual;
                    qtde_operacoes = e_consultar_prox_qtde_oper(e);
                    conta = e_obter_prox_num_conta(e);
                    if (conta == -1){
                        conta = e_obter_prox_num_conta(e);
                        classe = e->classeAtual;
                    }
                    operacao[classe-1] = operacao[classe-1] + qtde_operacoes;
                    caixaAtual = index + 1;
                    log_registrar(&registrador, conta, classe, timer, caixaAtual);
                    if (classe == 1){
                        strcpy(classeStr, "Premium");
                    }
                    if (classe == 2){
                        strcpy(classeStr, "Ouro");
                    }
                    if (classe == 3){
                        strcpy(classeStr, "Prata");
                    }
                    if (classe == 4){
                        strcpy(classeStr, "Bronze");
                    }
                    if (classe == 5){
                        strcpy(classeStr, "Comum");
                    }
                    fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria %s cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, classeStr, conta, qtde_operacoes);
                    caixa[index] = qtde_operacoes*e->tempoOperacao;
                    caixaValor[index] = caixaValor[index] + 1;
                }
                verificador = e_consultar_prox_num_conta(e);
            }
        }
        timer++;
    }

    timer--;

    for (index = 0; index < e->caixas; index++){
        if (maior < caixa[index]){
            maior = caixa[index];
        }
    }

    timer = timer + maior;
    
    //Tempos medios
    fprintf(arquivo_saida, "Tempo total de atendimento: %d minutos.\n", timer);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 1);
    tempoMedio = log_media_por_classe(&registrador, 1);

    fprintf(arquivo_saida,"Tempo medio de espera dos %d clientes Premium: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 2);
    tempoMedio = log_media_por_classe(&registrador, 2);

    fprintf(arquivo_saida,"Tempo medio de espera dos %d clientes Ouro: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 3);
    tempoMedio = log_media_por_classe(&registrador, 3);

    fprintf(arquivo_saida,"Tempo medio de espera dos %d clientes Prata: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 4);
    tempoMedio = log_media_por_classe(&registrador, 4);

    fprintf(arquivo_saida,"Tempo medio de espera dos %d clientes Bronze: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 5);
    tempoMedio = log_media_por_classe(&registrador, 5);

    fprintf(arquivo_saida,"Tempo medio de espera dos %d clientes Comum: %.2f\n", qtde_clientes, tempoMedio);


    //Quantidades medias
    qtde_operacoes = operacao[0];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 1);
    qtde_Media = qtde_operacoes/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium: %f\n", qtde_Media);

    qtde_operacoes = operacao[1];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 2);
    qtde_Media = qtde_operacoes/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium: %f\n", qtde_Media);

    qtde_operacoes = operacao[2];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 3);
    qtde_Media = qtde_operacoes/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium: %f\n", qtde_Media);

    qtde_operacoes = operacao[3];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 4);
    qtde_Media = qtde_operacoes/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium: %f\n", qtde_Media);

    qtde_operacoes = operacao[4];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 5);
    qtde_Media = qtde_operacoes/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium: %f\n", qtde_Media);

    for (index = 0; index < e->caixas; index++){
        fprintf(arquivo_saida,"O caixa de número %d atendeu %d clientes.\n", index+1, caixaValor[index]);
    }
}