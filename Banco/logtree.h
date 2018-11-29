#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct abb {
    struct abb *pai;
    struct abb *esquerdo;
    struct abb *direito;
    int conta, classe, timer, caixa;
} Log;

void log_inicializar(Log **l);

void log_registrar(Log **l, int conta, int classe, int timer, int caixa);

float log_media_por_classe(Log **l, int classe);

int log_obter_soma_por_classe(Log **l, int classe);

int log_obter_contagem_por_classe(Log **l, int classe);