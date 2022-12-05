///////////////////////////////////////////////////
/////////////////// ÁRVORE AVL ////////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No* e;
    struct No* d;
    int dado;
} No;

int altura(No* a);
No* balanceia(No* a);
No* cria_arvore(No* a);
No* rotaciona_direita(No* a);
No* rotaciona_esquerda(No* a);

No* insere_no(No* a, int n);
No* remove_no(No* a, int n);
void imprime_ordenado(No* a);
void imprime_linearmente(No* a);
int altura(No* a);

int main(){
    return 0;
}

int altura(No* a){
    if (!a) return 0;

    int altura_e, altura_d;
    altura_e = altura(a->e);
    altura_d = altura(a->d);

    if (altura_e > altura_d) return altura_e + 1;
    else return altura_d + 1;
}

No* cria_arvore(No* a){
    return NULL;
}

No* rotaciona_direita(No* a){
    No* aux = a->e;
    a->e = aux->d;
    aux->d = a;
    a = aux;
    return a;
}

No* rotaciona_esquerda(No* a){
    No* aux = a->d;
    a->d = aux->e;
    aux->e = a;
    a = aux;
    return a;
}