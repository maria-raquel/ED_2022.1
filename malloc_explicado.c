#include <stdio.h>
#include <stdlib.h>

// Testando alocacao dinamica

void main(){
    int *p;           // variavel que vai apontar para a memoria alocada
                      // p sera um ponteiro para inteiro

    printf("Valor de p antes da alocacao: %p\n", p);

    p = (int*) malloc(sizeof(int));        // alocando espaca para armazenar um inteiro

    // a funcao malloc retorna tipo void*, entao, por precaucao, fazemos o cast para o tipo que queremos

    printf("Valor de p depois da alocacao: %p\n", p);
    
    if (p==0){
        printf("Memoria nao alocada\n");
        return;
    }

    *p = 12;
    printf("-->*p = 12;\n");
    printf("Valor apontado por p: %d\n", *p);

    *p = 7;
    printf("-->*p = 7;\n");
    printf("Valor apontado por p: %d\n", *p);

    free(p);           // liberando o espaco alocado

    printf("-->free(p);\n");
    printf("Valor de p: %p\n", p);
    printf("O ponteiro continua existindo, mesmo após a liberacao da memoria\n");
    printf("Valor apontado por p: %d\n", *p);
    printf("Nao temos mais controle sobre o conteudo para o qual ele aponta\n");

    printf("-->*p = 10;\n");
    printf("Valor apontado por p: %d\n", *p);
}