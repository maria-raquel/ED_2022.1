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
int menu(No **ll);

void insere_inicio(No **ll, int n);
void insere_fim(No **ll, int n);
// cria, preenche e insere o novo nó

void remove_inicio(No **ll);
void remove_fim(No **ll);
// remove da lista e dá free no nó

int main(){
    No *lista; 
    cria_lista(&lista);
    return 0;
}

void cria_lista(No** ll){
    *ll = NULL;
    return;
}

void limpa_lista(No** ll){
    No* aux_free = *ll; // vai liberar a memoria de cada nó
    No* aux_proximo = *ll->prox; // vai salvar o endereço do próximo nó a ser liberado
    
    *ll = 0;

    for(; aux_proximo;){
        free(aux_free);
        aux_free = aux_proximo;
        aux_proximo = aux_proximo->prox
    }

    free(aux_free);
}

void insere_inicio(No**ll, int n){
    // ll é o endereço da lista, ou seja, é um ponteiro para um ponteiro para o primeiro nó

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = *ll;

    // inserindo o novo nó na lista;
    *ll = novo;
}

void insere_fim(No**ll, int n){
    // ll é o endereço da lista, ou seja, é um ponteiro para um ponteiro para o primeiro nó

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = NULL;

    // inserindo na lista
    No* aux = *ll;
    for (; aux->prox; aux = aux->prox);

    aux->prox = novo;
}

void remove_inicio(No **ll){
    No* aux = *ll;

    // removendo da lista
    *ll = (*ll)->prox;

    // excluindo o elemento
    free(aux);
}

void remove_fim(No **ll){
    No* aux = *ll;
    for(; aux->prox->prox; aux = aux->prox);
    // parando no elemento anterior ao que será removido

    free(aux->prox);
    aux->prox = NULL;
}

void mostra_lista(No** ll){
    printf("(");

    No* aux = *ll;
    for(; aux->prox; aux = aux->prox)
        printf("%d, ", aux->dado);

    prinf("%d)\n\n", aux->dado);
}

int menu(No **ll){
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

    switch (escolha) {
        case 1: puts("\nSua lista: ")
                mostra_lista(ll);
                break;

        case 2: puts("Que elemento deseja inserir? ");
                int n;
                scanf("%d", &n);
                insere_inicio(ll, n);
                puts("inserido!");
                break;

        case 3: puts("Que elemento deseja inserir? ");
                int n;
                scanf("%d", &n);
                insere_fim(ll, n);
                puts("inserido!");
                break;

        case 4: remove_inicio(ll);
                puts("removido!");
                break;        
        
        case 5: remove_fim(ll);
                puts("removido!");
                break;

        case 6: limpa_lista(ll);
                puts("lista limpa!");
                break;

        case -1: return 0;

        default: puts("Valor invalido!");
                break;
        }

    menu(ll);

    }
    