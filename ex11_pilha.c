#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
} No;

void cria_pilha(No** pp); 
void limpa_pilha(No** pp);
void menu(No** pp);
void mostra_pilha(No* p);
void mostra_pilha_ao_contrario(No* p);
void mostra_topo(No** pp);
void pop(No** pp); 
void push(No** pp, int n); 

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
        puts("( )");
        return;
    }

    printf("(%d)\n", (*pp)->dado);
}

void limpa_pilha(No** pp){
    if(!(*pp))
        return;
    
    No* aux = (*pp)->prox;
    free(*pp);
    (*pp) = NULL;
    limpa_pilha(&aux);
}

void menu(No** pp){
    puts("Digite o que deseja fazer: ");
    puts("  1: mostrar o topo da pilha");
    puts("  2: inserir um novo topo na pilha (push)");
    puts("  3: remover o topo da pilha (pop)");
    puts("  4: mostrar a pilha inteira");
    puts("  5: limpar a pilha");
    puts("  6: mostrar a pilha inteira ao contrário");
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
    
    case 4:
        puts("\nPilha:");
        printf("( ");
        mostra_pilha(*pp);
        printf(")\n\n");
        break;

    case 5:
        limpa_pilha(pp);
        puts("\nPilha limpa\n");
        break;

    case 6:
        puts("\nPilha ao contrário:");
        printf("( ");
        mostra_pilha_ao_contrario(*pp);
        printf(")\n\n");
        break;
    
    case -1:
        return;
    
    default:
        puts("\nValor invalido! Selecione um número entre 1 e 6\n");
        break;
    }
    menu(pp);
}

void mostra_pilha(No* p){
    if(!p)
        return;
    
    printf("%d ", p->dado);
    mostra_pilha(p->prox);
}

void mostra_pilha_ao_contrario(No* p){
    if (p){
        mostra_pilha_ao_contrario(p->prox);
        printf("%d ", p->dado);
    }
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