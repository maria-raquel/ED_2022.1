#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* ant;
    struct No* prox;
} No;

void cria_lista(No** ll);
void insere_inicio(No **ll, int n);
void insere_fim(No **ll, int n);
void limpa_lista(No** ll);
void mostra_lista(No** ll);
void mostra_lista_ao_contrario(No** ll);
void menu(No **ll);
void remove_inicio(No **ll);
void remove_fim(No **ll);

int main(){
    No* lista;
    cria_lista(&lista);
    menu(&lista);
    return 0;
}

void cria_lista(No** ll){
    (*ll) = NULL;
}

void limpa_lista(No** ll){
    No* aux = (*ll);

    if((*ll)==NULL){
        puts("\nLista vazia!");
        return;
    }

    (*ll) = NULL;
    for(; aux->prox;){
        aux = aux->prox;
        free(aux->ant);
    }
    free(aux);

    puts("\nLista limpa!\n");
}

void insere_inicio(No **ll, int n){
    No* novo = (No*)malloc(sizeof(No));

    if(!novo){
        puts("\nNão inserido: memóra insuficiente!\n");
        return;
    }

    novo->ant = NULL;
    novo->dado = n;
    novo->prox = (*ll);

    if((*ll)!=NULL)
        (*ll)->ant = novo;

    (*ll) = novo;

    puts("\nInserido!\n");
}

void insere_fim(No **ll, int n){
    No* novo = (No*)malloc(sizeof(No));

    if(!novo){
        puts("\nNão inserido: memória insuficiente\n");
        return;
    }

    novo->dado = n;
    novo->prox = NULL;

    if(!(*ll)){
        novo->ant = NULL;
        (*ll) = novo;
        puts("\nInserido!\n");
        return; 
    }

    No* aux = (*ll);
    for(; aux->prox; aux = aux->prox);

    novo->ant = aux;
    aux->prox = novo;
    
    puts("\nInserido!\n");
}

void mostra_lista(No** ll){
    if(!(*ll)){
        puts("(vazia)");
        return;
    }

    No* aux = (*ll);
    putchar('(');
    for(; aux->prox; aux = aux->prox)
        printf("%d, ", aux->dado);
    printf("%d)\n", aux->dado);
}

void mostra_lista_ao_contrario(No** ll){
    if(!(*ll)){
        puts("(vazia)");
        return;
    }

    No* aux = (*ll);
    for(; aux->prox; aux = aux->prox);

    putchar('(');
    for(; aux->ant; aux = aux->ant)
        printf("%d, ", aux->dado);
    printf("%d)\n", aux->dado);
}

void menu(No **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: mostrar a lista ao contrário");
    puts("3: inserir elemento no início da lista");
    puts("4: inserir elemento no fim da lista");
    puts("5: remover elemento no início da lista");
    puts("6: remover elemento no fim da lista");
    puts("7: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);

    int n = 0;

    switch (escolha) {
        case 1: puts("\nSua lista: ");
                mostra_lista(ll);
                putchar('\n');
                break;

        case 2: puts("\nSua lista, ao contrário: ");
                mostra_lista_ao_contrario(ll);
                putchar('\n');
                break;

        case 3: puts("Que elemento deseja inserir? ");
                scanf("%d", &n);
                insere_inicio(ll, n);
                break;

        case 4: puts("Que elemento deseja inserir? ");
                scanf("%d", &n);
                insere_fim(ll, n);
                break;

        case 5: remove_inicio(ll);
                break;        
        
        case 6: remove_fim(ll);
                break;

        case 7: limpa_lista(ll);
                break;

        case -1: return;

        default: puts("\nValor invalido! Selecione um número entre 1 e 6.\n");
                break;
    }
    menu(ll);
}

void remove_inicio(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = (*ll);
    (*ll) = aux->prox;
    
    if(aux->prox)
        aux->prox->ant = NULL;

    free(aux);

    puts("\nRemovido!\n");
}

void remove_fim(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = (*ll);
    for(; aux->prox; aux = aux->prox);

    if(aux->ant)
        aux->ant->prox = NULL;
    else 
        (*ll) = NULL;
        
    free(aux);
    puts("\nRemovido!\n");
}
