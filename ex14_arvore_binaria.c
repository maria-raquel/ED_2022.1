///////////////////////////////////////////////////
//////////// ÁRVORE BINÁRIA DE BUSCA //////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* e;
    struct No* d;
} No;

// Crua uma árvore vazia, deve ser atribuído a uma variável 
No* cria_arvore();

// Aloca o espaço, preenche os campos e retorna um ponteiro
// Deve ser atribuído a uma variável 
No* cria_no(int n, No* esquerda, No* direita);

// Funções de imprimir, com diferentes formas de percorrer a árvore
void imprime_prefix(No* a);
void imprime_infix(No* a); // percurso que imprime árvores ordenadas
void imprime_posfix(No* a); // percurso que limpa árvores

// retorna a altura da árvore
int altura(No* a);

// insere um número na árvore no local correto 
No* insere(No* a, int n);

void menu(No* a);

int main(){
    No* arvore = cria_arvore();
    // arvore = insere(arvore, 7);
    // arvore = insere(arvore, 4);
    // arvore = insere(arvore, 17);
    // arvore = insere(arvore, 78);
    // arvore = insere(arvore, 1);
    // arvore = insere(arvore, 3);
    // imprime_infix()
    menu(arvore);
    return 0;
}

No* cria_arvore(){
    return 0;
}

No* cria_no(int n, No* esquerda, No* direita){
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->dado = n;
    novo->e = esquerda;
    novo->d = direita;

    return novo;
}

void imprime_prefix(No* a){
    if (a){
        printf("%d ", a->dado); // trata a raiz
        imprime_prefix(a->e); // percorre subarvore a esquerda
        imprime_prefix(a->d); // percorre subarvore a direita
    }
}

void imprime_infix(No* a){
    if (a){
        imprime_infix(a->e); // percorre subarvore a esquerda
        printf("%d ", a->dado); // trata a raiz
        imprime_infix(a->d); // percorre subarvore a direita
    }
}

void imprime_posfix(No* a){
    if (a){
        imprime_posfix(a->e); // percorre subarvore a esquerda
        imprime_posfix(a->d); // percorre subarvore a direita
        printf("%d ", a->dado); // trata a raiz
    }
}

int altura(No* raiz){
    if (!raiz) return 0;

    int a, b;
    a = altura(raiz->e);
    b = altura(raiz->d);

    if (a>b) return a+1;
    else return b+1;
}

No* insere(No* a, int n){
    if (!a)
        a = cria_no(n,0,0);
    else if (n < a->dado)
        a->e = insere(a->e, n);
    else a->d = insere(a->d, n);
    return a;
}

void menu(No* a){
    int escolha = 0;
    int n;

    do{
        puts("O que deseja fazer com a árvore?");
        puts("1: inserir elemento");
        puts("2: imprimir prefix");
        puts("3: imprimir infix");
        puts("4: imprimir posfix");
        puts("5: calcular a altura da árvore");
        puts("-1: encerrar o programa");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            puts("que número?");
            scanf("%d", &n);
            a = insere(a, n);
            break;
        case 2: 
            printf("\n");
            imprime_prefix(a);
            printf("\n\n");
            break;
        case 3: 
            printf("\n");
            imprime_infix(a);
            printf("\n\n");
            break;
        case 4: 
            printf("\n");
            imprime_posfix(a);
            printf("\n\n");
            break;
        case 5:
            printf("\nAltura da árvore: %d\n\n", altura(a));
            break;
        case -1:
            return;
        default:
            puts("\nValor inválido!\n");
            break;
        }
    } while (escolha);
}