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
void mostra_fila(Fila* f);
void mostra_head(Fila* f);
void remove_head(Fila* f); // apenas no início

int main(){
    return 0;
}

void cria_fila(Fila* f){
    f->head = f->tail = NULL;
}

void insere(Fila* f, int n){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = n;
    novo->prox = f->head;

    if (esta_vazia(f))
        f->tail = novo;
    
    f->head = novo;
}

int esta_vazia(Fila* f){
    if (f->head == NULL)
        return 1;
    return 0;
}