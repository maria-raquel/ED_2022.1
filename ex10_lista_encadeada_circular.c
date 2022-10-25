#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
} No;

void cria_lista(No** ll);
void insere_inicio(No **ll, int n);
void insere_fim(No **ll, int n);
void limpa_lista(No** ll);
void mostra_lista(No** ll);
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


void insere_inicio(No **ll, int n){
    No* novo = (No*)malloc(sizeof(No));

    if(!novo){
        puts("\nNão inserido: memória insuficiente!\n");
        return;
    }

    novo->dado = n;

    if(!(*ll)){
        novo->prox = novo;
        (*ll) = novo;
        puts("\nInserido!\n");
        return;
    }
        
    novo->prox = (*ll);

    No* aux = (*ll);
    for(; aux->prox != (*ll); aux = aux->prox);
    aux->prox = novo;
    (*ll) = novo; // unica diferença entre a insere_fim e insere_inicio
    puts("\nInserido!\n");
}

void insere_fim(No **ll, int n){
    No* novo = (No*)malloc(sizeof(No));
    
    if(!novo){
        puts("\nNão inserido: Memória Insuficiente\n");
        return;
    }

    novo->dado = n;

    if(!(*ll)){
        novo->prox = novo;
        (*ll) = novo;
        puts("\nInserido\n");
        return;
    }

    novo->prox = (*ll);

    No* aux = (*ll);
    for(; aux->prox != (*ll); aux = aux->prox);
    aux->prox = novo;
    puts("\nInserido\n");
}

void limpa_lista(No** ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux_1no = (*ll);

    (*ll) = NULL;

    if (aux_1no->prox != aux_1no){
        No* aux_anda = aux_1no->prox;
        No* aux_free = aux_1no->prox;

        for(; aux_anda->prox != aux_1no;){
            aux_anda = aux_anda->prox;
            free(aux_free);
            aux_free = aux_anda;
        }
        free(aux_free);
    }
    
    free(aux_1no);
    puts("\nLista limpa!\n");
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
                break;

        case -1: return;

        default: puts("\nValor invalido! Selecione um número entre 1 e 6.\n");
                break;
    }
    menu(ll);
}

void mostra_lista(No** ll){
    if (!(*ll)){
        puts("(vazia)");
        return;
    }

    No* aux = (*ll);
    putchar('(');
    for(; aux->prox != (*ll); aux = aux->prox)
        printf("%d, ", aux->dado);
    printf("%d)\n", aux->dado);
}

void remove_inicio(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux_ultimo_no = (*ll);

    if((*ll)->prox == (*ll)){
        (*ll) = NULL;
        free(aux_ultimo_no);
        puts("\nRemovido!\n");
        return;
    }

    No* aux_1_no = (*ll);
    for(; aux_ultimo_no->prox != (*ll); aux_ultimo_no = aux_ultimo_no->prox);
    aux_ultimo_no->prox = aux_1_no->prox;
    (*ll) = aux_1_no->prox;
    free(aux_1_no);
    puts("\nRemovido!\n");
}

void remove_fim(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = (*ll);

    if(aux->prox == (*ll)){
        (*ll) = NULL;
        free(aux);
        puts("\nRemovido!\n");
        return;
    }

    for(; aux->prox->prox != (*ll); aux = aux->prox);
    No* aux_free = aux->prox;
    aux->prox = (*ll);
    free(aux_free);
}