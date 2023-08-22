#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAMANHO 5

typedef struct T_FILA{
    char dados[TAMANHO][20]; // Tamanho da fila e tamanho máximo da string
    int fim; // Controlador pro fim da fila
} T_FILA;

void inicializaFila(T_FILA *f){
    int i;
    for(i = 0; i < TAMANHO; i++){
        f->dados[i][0] = '\0'; // Inicializa as strings vazias
    }
    f->fim = 0;
}

void enfileira(const char *dado, T_FILA *f){
    if(f->fim == TAMANHO){
        printf("Fila está cheia... \n");
        return;
    } else {
        strcpy(f->dados[f->fim], dado);
        f->fim++;
    }
}

const char *desenfileira(T_FILA *f) {
    const char *dado = f->dados[0];
    if (f->fim == 0) {
        printf("A fila está vazia, não tem o que tirar. \n");
        return NULL;
    } else {
        for (int i = 0; i < f->fim - 1; i++) {
            strcpy(f->dados[i], f->dados[i + 1]);
        }
        f->fim--;
    }
    return dado;
}

void imprimeFila(T_FILA *f) {
    printf("Imprimindo a fila:\n");
    for (int i = 0; i < f->fim; i++) {
        printf("%s ", f->dados[i]);
    }
    printf("\n");
}
