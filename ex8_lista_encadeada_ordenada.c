#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* prox;
} No;

void cria(No** ll);
void insere(No** ll, int n);
void limpa(No** ll);
void menu(No** ll);
void mostra(No** ll);
void remove_(No** ll, int n);

int main(){
    No* lista;
    cria(&lista);
    menu(&lista);
    return 0;
}

void cria(No** ll){
    (*ll) = NULL; 
}

void insere(No** ll, int n){
    No* novo;
    novo = (No*)malloc(sizeof(No*));

    if(!novo){
        puts("\nNão inserido: memória insuficiente!\n");
        return;
    }

    novo->dado = n;

    // nó novo alocado e valor preenchido, falta preencher prox e adicioná-lo a lista

    if(!(*ll) || (*ll)->dado > n){ // para a lista vazia ou inserção no início
        novo->prox = (*ll); // se a lista estiver vazia, (*ll) é 0
        // se não, novo->prox aponta para o próximo da
        (*ll) = novo;
        puts("\nInserido!\n");
        return;
    }

    No* aux;
    aux = (*ll);

    for(; aux->prox && n > aux->prox->dado; aux = aux->prox);

    novo->prox = aux->prox;
    aux->prox = novo;
    puts("\nInserido!\n");
}

void limpa(No** ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux_free = (*ll);
    No* aux_prox = aux_free->prox;
    (*ll) = NULL;

    for(; aux_prox;){
        free(aux_free);
        aux_free = aux_prox;
        aux_prox = aux_prox->prox;
    }
    free(aux_free);

    puts("\nLista limpa!\n");
}

void mostra(No** ll){
    if (!(*ll)){
        puts("(vazia)");
        return;
    }

    printf("(");

    No* aux = *ll;
    for(; aux->prox; aux = aux->prox)
        printf("%d, ", aux->dado);

    printf("%d)\n", aux->dado);
}

void menu(No** ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: inserir elemento na lista");
    puts("3: remover elemento da lista");
    puts("4: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);

    int n = 0;
    int m = 0;

    switch (escolha) {
        case 1: puts("\nSua lista: ");
                mostra(ll);
                putchar('\n');
                break;

        case 2: puts("Que elemento deseja inserir? ");
                scanf("%d", &n);
                insere(ll, n);
                break;

        case 3: puts("Que elemento deseja remover? ");
                scanf("%d", &m);
                remove_(ll, m);
                break;

        case 4: limpa(ll);
                break;        

        case -1: return;

        default: puts("\nValor invalido! Selecione um número entre 1 e 4.\n");
                break;
        }
    menu(ll);
}

void remove_(No** ll, int n){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = *ll;

    if(!(*ll)->prox){ // lista unitária
        if((*ll)->dado == n){
            *ll = NULL;
            free(aux);
            puts("\nRemovido!\n");
            return;
        }
        printf("\n%d não está na lista!\n\n", n);
        return;
    }

    if(aux->dado == n){ // quando o elemento a ser removido é o primeiro
        *ll = (*ll)->prox;
        free(aux);
        puts("\nRemovido!\n");
        return;
    }

    for(; aux->prox; aux = aux->prox){
        if(aux->prox->dado == n)
            break;
        if(aux->prox->dado > n){
            printf("\n%d não está na lista!\n", n);
            return;
        }           
    }

    No* aux_free = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux_free);

    puts("\nRemovido!\n");
}