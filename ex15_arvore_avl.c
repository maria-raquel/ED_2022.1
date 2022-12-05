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

No* insere_no(No* a, int n);
No* remove_no(No* a, int n);
No* cria_arvore(No* a);

int main(){
    return 0;
}