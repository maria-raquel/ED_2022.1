///////////////////////////////////////////////////
////////////////// FILA SIMPLES ///////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#define N 5

typedef struct{
    int dados[N];
    int head; // índice do primeiro elemento
    int tail; // índice do último elemento
} Fila;

void cria_fila(Fila* f);
void insere(Fila* f, int n); // apenas no final
int esta_cheia(Fila* f);
int esta_vazia(Fila* f);
void menu(Fila* f);
void mostra_fila(Fila* f);
void mostra_head(Fila* f);
void remove_head(Fila* f); // apenas no início

int main(){
    Fila fila;
    cria_fila(&fila);
    menu(&fila);
    return 0;
}

void cria_fila(Fila* f){
    f->head = f->tail = -1;
}

void insere(Fila* f, int n){
    if (esta_vazia(f))
        f->head = f->tail = 0;
    else
        f->tail = (f->tail + 1)%N;
    
    f->dados[f->tail] = n;
}

int esta_cheia(Fila* f){
    if ((f->tail + 1)%N == (f->head)%N)
        return 1;
    return 0;
}

int esta_vazia(Fila* f){
    if (f->head == -1)
        return 1;
    return 0;
}

void menu(Fila* f){
    int escolha = 1;
    int elemento;

    do{
        puts("Digite o que deseja fazer:");
        puts("1: inserir elemento");
        puts("2: mostrar a fila");
        puts("3: mostrar o primeiro elemento");
        puts("4: remover o primeiro elemento");
        puts("-1: encerrar o programa");

        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            if (esta_cheia(f))
                puts("\nLista cheia!\n");
            else{
                puts("\nQue elemento deseja inserir?");
                scanf("%d", &elemento);
                insere(f, elemento);
                puts("Inserido!\n");
            }
            break;
        case 2:
            mostra_fila(f);
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

void mostra_fila(Fila* f){
    if (esta_vazia(f)){
        puts("\n(vazia)\n");
        return;
    }
    
    putchar('\n');
    putchar('(');
    for(int i = f->head; i != f->tail; i = (i+1)%N)
        printf("%d ", f->dados[i]);
    printf("%d)\n\n", f->dados[f->tail]);
}

void mostra_head(Fila* f){
    printf("\n(%d)\n\n", f->dados[f->head]);
}

void remove_head(Fila* f){
    if (f->head == f->tail)
        f->head = f->tail = -1;
    else
        f->head = (f->head + 1)%N;
}
