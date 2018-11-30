#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

/*Inicializa o escalonador, alocando e inicializando as 5 filas, que serão atendidas por “caixas” caixas, onde cada
operação é tratada em “delta_t” minutos por um caixa, e o escalonamento utiliza a Disciplina de Atendimento
representada por {n_1; n_2; n_2; n_4; n_5}, nos termos do que foi definido na página 1 deste enunciado.*/
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

/*Insere na fila “classe” o cliente de número “num_conta”, que pretende realizar “qtde_operacoes” operações
bancárias.*/
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

/*Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento,
retirando-o da sua respectiva fila.*/
int e_obter_prox_num_conta(Escalonador *e){
    int classe, contador, conta;
    classe = e->classeAtual;
    contador = e->contador;
    
    if (classe == 1) {
        conta = f_obter_proxima_chave(&e->premium);
        //Se a fila for nula então o contador será 0.
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 2) {
        conta = f_obter_proxima_chave(&e->ouro);
        //Se a fila for nula então o contador será 0.
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 3) {
        conta = f_obter_proxima_chave(&e->prata);
        //Se a fila for nula então o contador será 0.
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 4) {
        conta = f_obter_proxima_chave(&e->bronze);
        //Se a fila for nula então o contador será 0.
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    } else if (classe == 5) {
        conta = f_obter_proxima_chave(&e->comum);
        //Se a fila for nula então o contador será 0.
        if (conta == -1){
            contador = 0;
        } else {
            contador--;
        }
    }
    
    //Se o contador for 0 entao ira para a fila seguinte de acordo com a Disciplina de Atendimento.
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

/*Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento, sem
retirá-lo da sua respectiva fila. Retorna 0 caso não tenha mais nenhuma conta*/
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

/*Retorna a quantidade de operações bancárias que o próximo cliente das filas pretende realizar com o caixa,
sem retirá-lo da sua respectiva fila. Retorna 0 caso nao tenha mais nenhum clinete nas filas*/
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

//Retorna a próxima fila que será atendida de acordo com a Disciplina de Atendimento. Retorna 0 caso todas as filas forem vazias.
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

//Retorna a quantidade total (soma) de clientes esperando atendimento em todas as filas.
int e_consultar_qtde_clientes (Escalonador *e){
    int contador = 0;

    contador = f_num_elementos(&e->premium);
    contador = contador + f_num_elementos(&e->ouro);
    contador = contador + f_num_elementos(&e->prata);
    contador = contador + f_num_elementos(&e->bronze);
    contador = contador + f_num_elementos(&e->comum);

    return contador;
}

/*Retorna o tempo necessário para que o próximo cliente a ser atendido realize todas as operações financeiras
que deseja, sem retirá-lo da sua respectiva fila. Retornar -1 caso não tenha nenhum cliente em todas as filas.*/
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

/*Realiza a configuração de inicialização do escalonador através da leitura do arquivo de configuração de nome
“nome_arq_conf”, retornando 1 em caso de sucesso e 0 caso contrário.*/
int e_conf_por_arquivo (Escalonador *e, char *nome_arq_conf){
    FILE* arquivo_entrada;
    int QtdeCaixas, DTempo, N_1, N_2, N_3, N_4, N_5;
    char classe[10];
    int conta, operacao;
    arquivo_entrada = fopen(nome_arq_conf, "r");

    //Se estiver vazio.
    if(arquivo_entrada == NULL){
        return 0;
    }
    //Recolhe as informações iniciais.
    fscanf(arquivo_entrada,"qtde de caixas = %d\n", &QtdeCaixas);
    fscanf(arquivo_entrada,"delta t = %d\n", &DTempo);
    fscanf(arquivo_entrada,"disciplina de escalonamento = {%d,%d,%d,%d,%d}\n", &N_1, &N_2, &N_3, &N_4, &N_5);

    //Inicializa o escalonador.
    e_inicializar(e, QtdeCaixas, DTempo, N_1, N_2, N_3, N_4, N_5);

    //Coleta de informacoes gerais do cliente.
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
    //Finaliza e fecha o arquivo.
    fclose(arquivo_entrada);
    return 1;
}

/*Executar a simulação do atendimento, lendo o arquivo de configuração de nome “nome_arq_in” e escrevendo
o resultado do processamento para arquivo de nome “nome_arq_out”.*/
void e_rodar (Escalonador *e, char *nome_arq_in, char *nome_arq_out){
    Log *registrador;
    FILE *arquivo_saida;
    int timer = 0, caixa[10], index, qtde_operacoes, conta, classe, verificador, caixaAtual, maior = 0, tempoTotal, operacao[5], caixaValor[10];
    float qtde_clientes, qtde_operacoes_por_classe, tempoMedio, qtde_Media;

    //Coloca todas as configurações do escalonador. 
    e_conf_por_arquivo(e, nome_arq_in);
    arquivo_saida = fopen(nome_arq_out, "w");

    //Inicia o registrador.
    log_inicializar(&registrador);
    
    //Inicia o verificador para ver se possui algum cliente nas filas.
    verificador = e_consultar_prox_num_conta(e);
    
    //Inicializa os caixas e seus contadores.
    for (index = 0; index < e->caixas; index++){
        caixa[index] = 1;
        caixaValor[index] = 0;
    }
    
    //Inicializa os contadores de operações por classe.
    for (index = 0; index < 5; index++){
        operacao[index] = 0;
    }

    //Verifica cada caixa e modifica seu timer.
    while (verificador != 0) {
        for (index = 0; index < e->caixas; index++){
            caixa[index] = caixa[index] - 1;
            if (caixa[index] == 0){
                classe = e->classeAtual;
                qtde_operacoes = e_consultar_prox_qtde_oper(e);
                conta = e_obter_prox_num_conta(e);
                if (conta == -1){
                    conta = e_obter_prox_num_conta(e);
                    classe = e->classeAtual;
                }
                if (conta != -1 && conta != 0){
                    operacao[classe-1] = operacao[classe-1] + qtde_operacoes;
                    caixaAtual = index + 1;
                    log_registrar(&registrador, conta, classe, timer, caixaAtual);
                    if (classe == 1){
                        fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria Premium cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, conta, qtde_operacoes);
                    }
                    if (classe == 2){
                        fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria Ouro cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, conta, qtde_operacoes);
                    }
                    if (classe == 3){
                        fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria Prata cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, conta, qtde_operacoes);
                    }
                    if (classe == 4){
                        fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria Bronze cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, conta, qtde_operacoes);
                    }
                    if (classe == 5){
                        fprintf(arquivo_saida, "T = %d min: Caixa %d chama da categoria Comum cliente da conta %d para realizar %d operacao(oes).\n", timer, caixaAtual, conta, qtde_operacoes);
                    }
                    caixa[index] = qtde_operacoes*e->tempoOperacao;
                    caixaValor[index] = caixaValor[index] + 1;
                }
            }
            verificador = e_consultar_prox_num_conta(e);
        }
        timer++;
    }
    
    // Conserta o timer que andou mais um.
    timer--;

    //Pega o tempo do ultimo clinte que sairá do caixa.
    for (index = 0; index < e->caixas; index++){
        if (maior < caixa[index]){
            maior = caixa[index];
        }
    }

    timer = timer + maior;
    
    //Tempos medios de atendimento no arquivo.
    fprintf(arquivo_saida, "Tempo total de atendimento: %d minutos.\n", timer);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 1);
    tempoMedio = log_media_por_classe(&registrador, 1);

    fprintf(arquivo_saida,"Tempo medio de espera dos %.0f clientes Premium: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 2);
    tempoMedio = log_media_por_classe(&registrador, 2);

    fprintf(arquivo_saida,"Tempo medio de espera dos %.0f clientes Ouro: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 3);
    tempoMedio = log_media_por_classe(&registrador, 3);

    fprintf(arquivo_saida,"Tempo medio de espera dos %.0f clientes Prata: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 4);
    tempoMedio = log_media_por_classe(&registrador, 4);

    fprintf(arquivo_saida,"Tempo medio de espera dos %.0f clientes Bronze: %.2f\n", qtde_clientes, tempoMedio);

    qtde_clientes = log_obter_contagem_por_classe(&registrador, 5);
    tempoMedio = log_media_por_classe(&registrador, 5);

    fprintf(arquivo_saida,"Tempo medio de espera dos %.0f clientes Comuns: %.2f\n", qtde_clientes, tempoMedio);


    //Quantidades medias de operaçoes por classe.
    qtde_operacoes_por_classe = operacao[0];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 1);
    qtde_Media = qtde_operacoes_por_classe/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Premium = %.2f\n", qtde_Media);

    qtde_operacoes_por_classe = operacao[1];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 2);
    qtde_Media = qtde_operacoes_por_classe/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Ouro = %.2f\n", qtde_Media);

    qtde_operacoes_por_classe = operacao[2];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 3);
    qtde_Media = qtde_operacoes_por_classe/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Prata = %.2f\n", qtde_Media);

    qtde_operacoes_por_classe = operacao[3];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 4);
    qtde_Media = qtde_operacoes_por_classe/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Bronze = %.2f\n", qtde_Media);

    qtde_operacoes_por_classe = operacao[4];
    qtde_clientes = log_obter_contagem_por_classe(&registrador, 5);
    qtde_Media = qtde_operacoes_por_classe/qtde_clientes;
    fprintf(arquivo_saida,"Quantidade media de operacoes por cliente Comum = %.2f\n", qtde_Media);


    //Quantidade de clientes por caixa.
    for (index = 0; index < e->caixas; index++){
        fprintf(arquivo_saida,"O caixa de número %d atendeu %d clientes.\n", index+1, caixaValor[index]);
    }
}