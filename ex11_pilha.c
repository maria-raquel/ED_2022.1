#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
} No;

void cria_pilha(No** pp); //ok
void limpa_pilha(No** pp);
void menu(No** pp);
void mostra_pilha(No** pp);
void mostra_topo(No** pp); //ok ?
void pop(No** pp); // ok ?
void push(No** pp, int n); // ok ?

int main(){
    No* pilha;
    cria_pilha(&pilha);
    menu(&pilha);
    return 0;
}

void cria_pilha(No** pp){
    (*pp) = NULL;
}

void mostra_topo(No** pp){
    if(!*pp){
        puts("(vazia)");
        return;
    }

    printf("(%d)\n", (*pp)->dado);
}

void menu(No** pp){
    puts("Digite o que deseja fazer: ");
    puts("  1: mostrar o topo da pilha");
    puts("  2: inserir um novo topo na pilha (push)");
    puts("  3: remover o topo da pilha (pop)");
    puts("  -1: encerrar");

    int escolha;
    scanf("%d", &escolha);
    int n=0;

    switch (escolha){

    case 1:
        puts("\nTopo da pilha:");
        mostra_topo(pp);
        putchar('\n');
        break;

    case 2:
        puts("\nQue número deseja inserir?");
        scanf("%d", &n);
        push(pp, n);
        break;
    
    case 3:
        pop(pp);
        break;
    
    case -1:
        return;
    
    default:
        puts("\nValor invalido! Selecione um número entre 1 e 3\n");
        break;
    }
    menu(pp);
}

void push(No** pp, int n){
    No* novo = (No*)malloc(sizeof(No));

    if(!novo){
        puts("\nMemória insuficiente!\n");
        return;
    }

    novo->dado = n;
    novo->prox = (*pp);
    (*pp) = novo;

    puts("\nInserido!\n");
}

void pop(No** pp){
    if(!(*pp)){
        puts("\nPilha vazia!\n");
        return;
    }

    No* aux = (*pp);
    (*pp) = (*pp)->prox;
    free(aux);

    puts("\nRemovido!\n");
}