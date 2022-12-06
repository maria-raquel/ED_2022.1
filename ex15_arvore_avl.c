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
No* cria_arvore();
int fator_de_balanceamento(No* a);
void imprime_ordenado(No* a);
void imprime_prefix(No* a);
No* insere_no(No* a, int n);
void menu(No* a);
No* remove_no(No* a, int n);
No* rotaciona_direita(No* a);
No* rotaciona_esquerda(No* a);

int main(){
    No* arvore = cria_arvore();
    menu(arvore);
    return 0;
}

int altura(No* a){
    if (!a) return -1;

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
    // e o fator de balanceamento dos filhos nunca fica maior que módulo de 1

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

No* cria_arvore(){
    return NULL;
}

int fator_de_balanceamento(No* a){
    if (!a) return 0;
    return altura(a->e) - altura(a->d);
}

void imprime_ordenado(No* a){
    if(!a) return;
    imprime_ordenado(a->e);
    printf("%d ", a->dado);
    imprime_ordenado(a->d);
}

void imprime_prefix(No* a){ 
    putchar('<');
    if (a){
        printf("%d", a->dado); 
        imprime_prefix(a->e); 
        imprime_prefix(a->d); 
    }
    putchar('>');
}

No* insere_no(No* a, int n){
    if (!a){
        No* novo = (No*) malloc(sizeof(No));
        if (!novo) return NULL;
        novo->d = novo->e = NULL;
        novo->dado = n;
        a = novo;
    }

    else if (n < a->dado)
        a->e = insere_no(a->e, n);
    else 
        a->d = insere_no(a->d, n);
    
    return balanceia(a);
}

void menu(No* a){
    int escolha, n;

    do{
        puts("O que deseja fazer com a árvore?");
        puts("1: inserir um número");
        puts("2: imprimir ordenadamente");
        puts("3: imprimir prefix");
        puts("4: remover um número");
        puts("-1: encerrar");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            puts("Que número?");
            scanf("%d", &n);
            a = insere_no(a, n);
            break;
        case 2: 
            putchar('\n');
            imprime_ordenado(a);
            printf("\n\n");
            break;
        case 3:
            putchar('\n');
            imprime_prefix(a);
            printf("\n\n");
            break;
        case 4:
            puts("Que número?");
            scanf("%d", &n);
            a = remove_no(a, n);
            break;
        case -1:
            return;
        default:
            break;
        }
    } while (escolha != -1);
}

No* remove_no(No* a, int n){
    if (!a) return NULL;

    if (n < a->dado)
        a->e = remove_no(a->e, n);

    else if (n > a->dado)
        a->d = remove_no(a->d, n);

    else {
        if (!(a->e) && !(a->d)){
            free(a);
            a = NULL;
        }

        else if (!(a->d)){
            No* aux = a;
            a = a->e;
            free(aux);
        }

        else if (!(a->e)){
            No* aux = a;
            a = a->d;
            free(aux);
        }

        else {
            No* aux = a->e;
            for (; aux->d; aux = aux->d);
            a->dado = aux->dado;
            aux->dado = n;
            a->e = remove_no(a->e, n);
        }
    }
    return balanceia(a);
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