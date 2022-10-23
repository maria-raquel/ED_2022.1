#include <stdio.h>
#include <stdlib.h>

// a lista é um ponteiro para o primeiro nó
// cada nó é do tipo a seguir
typedef struct no{
    int dado; // informação armazenada
    struct no *prox; // ponteiro para próximo nó
} No;

// nas funções, ll é ponteiro para a lista
// quando quiser usar a lista (o ponteiro para o primeiro elemento) na função, usar *ll

void cria_lista(No** ll);
// faz o ponteiro lista ser nulo

void limpa_lista(No** ll);
// faz o ponteiro lista ser nulo e libera a memória alocada para cada nó

void mostra_lista(No** ll);
void menu(No **ll);

void insere_inicio(No **ll, int n);
void insere_fim(No **ll, int n);
// cria, preenche e insere o novo nó

void remove_inicio(No **ll);
void remove_fim(No **ll);
// remove da lista e dá free no nó

int main(){
    No *lista; 
    cria_lista(&lista);
    menu(&lista);
    return 0;
}

void cria_lista(No** ll){
    *ll = NULL;
    return;
}

void limpa_lista(No** ll){
    No* aux_free = *ll; // vai liberar a memoria de cada nó
    No* aux_proximo = (*ll)->prox; // vai salvar o endereço do próximo nó a ser liberado
    
    *ll = 0;

    for(; aux_proximo;){
        free(aux_free);
        aux_free = aux_proximo;
        aux_proximo = aux_proximo->prox;
    }

    free(aux_free);
}

void insere_inicio(No**ll, int n){
    // ll é o endereço da lista, ou seja, é um ponteiro para um ponteiro para o primeiro nó

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    if(!novo){
        puts("\nNão iserido: memória insuficiente!\n");
        return;
    }

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = *ll;

    // inserindo o novo nó na lista;
    *ll = novo;

    puts("\nInserido!\n");
}

void insere_fim(No**ll, int n){
    if(!(*ll)){
        insere_inicio(ll, n);
        return;
    }

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    if(!novo){
        puts("\nNão iserido: memória insuficiente!\n");
        return;
    }

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = NULL;

    // inserindo na lista
    No* aux = *ll;
    for (; aux->prox; aux = aux->prox);
    
    aux->prox = novo;

    puts("\nInserido!\n");
}

void remove_inicio(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = *ll;

    // removendo da lista
    *ll = (*ll)->prox;

    // excluindo o elemento
    free(aux);

    puts("\nRemovido!\n");
}

void remove_fim(No **ll){
    if(!(*ll)){
        puts("\nLista vazia\n");
        return;
    }

    if(!(*ll)->prox){
        remove_inicio(ll);
        return;
    }
    
    No* aux = *ll;
    for(; aux->prox->prox; aux = aux->prox);
    // parando no elemento anterior ao que será removido

    free(aux->prox);
    aux->prox = NULL;
    puts("\nRemovido!\n");
}

void mostra_lista(No** ll){
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

void menu(No **ll){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar a lista");
    puts("2: inserir elemento no início da lista");
    puts("3: inserir elemento no fim da lista");
    puts("4: remover elemento no início da lista");
    puts("5: remover elemento no fim da lista");
    puts("6: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);

    int n = 0;

    switch (escolha) {
        case 1: puts("\nSua lista: ");
                mostra_lista(ll);
                putchar('\n');
                break;

        case 2: puts("Que elemento deseja inserir? ");
                scanf("%d", &n);
                insere_inicio(ll, n);
                break;

        case 3: puts("Que elemento deseja inserir? ");
                scanf("%d", &n);
                insere_fim(ll, n);
                break;

        case 4: remove_inicio(ll);
                break;        
        
        case 5: remove_fim(ll);
                break;

        case 6: limpa_lista(ll);
                puts("lista limpa!\n");
                break;

        case -1: return;

        default: puts("\nValor invalido! Selecione um número entre 1 e 6.\n");
                break;
    }
    menu(ll);
}
