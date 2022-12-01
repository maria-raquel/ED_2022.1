///////////////////////////////////////////////////
///////////////// FILA ENCADEADA //////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No* prox;
} No;

typedef struct Fila{
    No* head; // ponteiro para o primeiro elemento
    No* tail; // ponteiro para o último
} Fila;

void cria_fila(Fila* f);
void insere(Fila* f, int n); // apenas no final
int esta_vazia(Fila* f);
void menu(Fila* f);
void mostra_fila(No* no);
void mostra_head(Fila* f);
void remove_head(Fila* f); // apenas no início

int main(){
    Fila fila;
    cria_fila(&fila);
    menu(&fila);
    return 0;
}

void cria_fila(Fila* f){
    f->head = f->tail = NULL;
}

void insere(Fila* f, int n){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = n;
    novo->prox = NULL;

    if (esta_vazia(f)){
        f->head = novo;
        f->tail = novo;
        return;
    }
    
    f->tail->prox = novo;
    f->tail = novo;
}

int esta_vazia(Fila* f){
    if (f->head == NULL)
        return 1;
    return 0;
}

void menu(Fila* f){
    int escolha = 1;
    int elemento;

    do{
        puts("Digite o que deseja fazer:");
        puts("1: inserir elemento na fila");
        puts("2: mostrar a fila");
        puts("3: mostrar o próximo da fila");
        puts("4: remover o próximo da fila");
        puts("-1: encerrar o programa");

        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            puts("\nQue elemento deseja inserir?");
            scanf("%d", &elemento);
            insere(f, elemento);
            puts("Inserido!\n");
            break;
        case 2:
            if (esta_vazia(f))
                puts("\n(vazia)\n");
            else{
                printf("\n( ");
                mostra_fila(f->head);
                printf(")\n\n");
            }
            break;
        case 3:
            if (esta_vazia(f))
                puts("\nLista vazia!\n");
            else
                mostra_head(f);
            break;
        case 4:
            if (esta_vazia(f))
                puts("\nLista vazia!\n");
            else {
                remove_head(f);
                puts("Removido!\n");
            }
            break;
        case -1:
            return;
        default:
            puts("\nValor inválido!\n");
            break;
        }
    } while (escolha);
}

void mostra_fila(No* no){
    if (no){
        printf("%d ", no->dado);
        mostra_fila(no->prox);
    }
}

void mostra_head(Fila* f){
    printf("\n%d\n\n", f->head->dado);
}

void remove_head(Fila* f){
    if (esta_vazia(f))
        return;

    if (f->head == f->tail){
        free(f->head);
        f->head = f->tail = NULL;
        return;
    }

    No* aux = f->head;
    f->head = f->head->prox;
    free(aux);
}