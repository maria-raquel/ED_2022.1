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
int fator_de_balanceamento(No* a);
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

No* balanceia(No* a){
    int fb = fator_de_balanceamento(a);

    // Considerando que a árvore é verificada a cada inserção e remoção,
    // o fator de balanceamento nunca fica maior que módulo de 2
    // e o fator de balanceamento dos filhos nunca ficam maior que módulo de 1

    if (fb == -2){
        if (fator_de_balanceamento(a->d) == 1) 
            a->d = rotaciona_direita(a->d); // se for 1
        a = rotaciona_esquerda(a); // se for 1 ou -1
    }

    else if (fb == 2){
        if (fator_de_balanceamento(a->e) == -1) 
            a->e = rotaciona_esquerda(a->e); // se for -1
        a = rotaciona_direita(a); // se for -1 ou 1
    }

    return a;
}

No* cria_arvore(No* a){
    return NULL;
}

int fator_de_balanceamento(No* a){
    if (!a) return 0;
    return altura(a->e) - altura(a->d);
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