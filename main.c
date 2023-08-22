#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define TAMANHO_PLACA 8 
#define TAMANHO 5

void iniciarMenu(){
    printf("Escolha uma opcao \n");
    printf("(1) - Cadastrar Campos-Guarus \n");
    printf("(2) - Cadastrar Guarus-Campos \n");
    printf("(3) - Liberar Travessia \n");
    printf("(4) - Impressão \n");
    printf("(5) - Sair do programa \n");
}

int cadastrarCarro(T_FILA *f){
    int parada = 0;
    char vetorCarro[TAMANHO_PLACA];
    
    if(f->fim == TAMANHO){
        printf("A fila está cheia, não aceitamos mais carros. \n");
        return 0;
    } else {
        while(parada == 0){
            printf("Escreva a placa do carro: \n");
            scanf(" %7[^\n]", vetorCarro); // Limita a leitura a 7 caracteres
            vetorCarro[TAMANHO_PLACA - 1] = '\0'; // Garante que a string esteja terminada
            if(strlen(vetorCarro) != TAMANHO_PLACA - 1){
                printf("Perdão, essa placa não é válida, escreva novamente. \n");
            }else{
                enfileira(vetorCarro, f);
                printf("Carro cadastrado com sucesso!\n");
                parada = 1;
                return 1;
            }
        }
    }
    return 0; 
}

const char *retiraCarro(T_FILA *f) {
    if (f->fim == 0) {
        return NULL;
    } else {
        const char *carroRetirado = desenfileira(f);
        return carroRetirado;
    }
}


int main(){
    int escolhaMenu, parada = 0;
    T_FILA fcampos;
    inicializaFila(&fcampos);
    T_FILA fguarus;
    inicializaFila(&fguarus);
    
    while(parada == 0){
        int parada = 0;
        char continuar;
        iniciarMenu();
        scanf ("%d", &escolhaMenu );
        switch ( escolhaMenu ) {
            case 1: 
                cadastrarCarro(&fcampos);
                while((parada == 0) && (fcampos.fim < TAMANHO)){
                    printf("Deseja incluir outro carro?\n");
                    printf("Digite S para sim e N para não\n");
                    scanf(" %c", &continuar);
                    if((continuar == 'S') || (continuar == 's')){
                        cadastrarCarro(&fcampos);
                    }else{
                        parada = 1;
                    }
                }
                break;
            case 2: 
                cadastrarCarro(&fguarus);
                while((parada == 0) && (fguarus.fim < TAMANHO)){
                    printf("Deseja incluir outro carro?\n");
                    printf("Digite S para sim e N para não\n");
                    scanf(" %c", &continuar);
                    if((continuar == 'S') || (continuar == 's')){
                        cadastrarCarro(&fguarus);
                    }else{
                        parada = 1;
                    }
                }
                break;
            case 3:
                const char *carroCampos = retiraCarro(&fcampos);
                if (carroCampos == NULL) {
                    printf("Sem carros aguardando em Campos\n");
                } else {
                    printf("Atravessando o carro: %s\n", carroCampos);
                }
            
                const char *carroGuarus = retiraCarro(&fguarus);
                if (carroGuarus == NULL) {
                    printf("Sem carros aguardando em Guarus\n");
                } else {
                    printf("Atravessando o carro: %s\n", carroGuarus);
                }
                break;
            case 4: 
                printf("Fila de campos:\n");
                imprimeFila(&fcampos);
                printf("Fila de guarus: \n");
                imprimeFila(&fguarus);
                break;
            case 5: 
                printf("Fim do programa!");
                parada = 1;
                return 0;
            default : printf("Essa escolha não existe!\n");
        }
        printf("\n");
    }
    return 0;
}
