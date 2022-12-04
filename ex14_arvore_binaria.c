///////////////////////////////////////////////////
//////////// ÁRVORE BINÁRIA DE BUSCA //////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* e; // ponteiro para o filho da esquerda
    struct No* d; // ponteiro para o filho da direita
} No;

// Cria uma árvore vazia, deve ser atribuído a uma variável 
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

// limpa a árvore, desalocando a memória
No* limpa(No* a);

// remove o nó com o valor passado e rearranja os nós para manter a ordenação
No* remove_no(No* a, int n);

void menu(No* a);

int main(){
    No* arvore = cria_arvore();
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

void imprime_prefix(No* a){ // imprime <raiz sae sad>
    putchar('<');
    if (a){
        printf("%d ", a->dado); // trata a raiz
        imprime_prefix(a->e); // percorre subarvore a esquerda
        imprime_prefix(a->d); // percorre subarvore a direita
    }
    putchar('>');
}

void imprime_infix(No* a){ // imprime <sae raiz sad>
    putchar('<');
    if (a){
        imprime_infix(a->e); // percorre subarvore a esquerda
        printf("%d ", a->dado); // trata a raiz
        imprime_infix(a->d); // percorre subarvore a direita
    }
    putchar('>');
}

void imprime_posfix(No* a){ // imprime <sae sad raiz>
    putchar('<');
    if (a){
        imprime_posfix(a->e); // percorre subarvore a esquerda
        imprime_posfix(a->d); // percorre subarvore a direita
        printf("%d ", a->dado); // trata a raiz
    }
    putchar('>');
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

No* limpa(No* a){
    if(!a) return;
    limpa(a->e);
    limpa(a->d);
}

No* remove_no(No* a, int n){
    if (!a) return NULL;

    // procurando o nó que contem n

    else if (n < a->dado)
        a->e = remove_no(a->e, n);
    
    else if (n > a->dado)
        a->d = remove_no(a->d, n);

    else{ // encontramos o nó

        if (!(a->e) && !(a->d)){ // nó sem filhos
            free(a);
            a = NULL;
        }

        else if (!(a->d)){ // apenas filho da esquerda
            No* aux = a;
            a = a->e;
            free(aux);
        }

        else if (!(a->e)){ // apenas filho da direita
            No* aux = a;
            a = a->d;
            free(aux);
        }

        else{ // nó tem ambos filhos

            // encontramos o descendente mais a direita do filho a esquerda do nó
            // ele tem o valor mais alto menor que n na árvore
            No* aux = a->e;
            for(; aux->d; aux = aux->d);

            // trocamos os valores dos dois nós de lugar
            // isso mantém a ordenação da quando retirarmos n
            a->dado = aux->dado;
            aux->dado = n;

            // chamamos a função novamente
            // dessa vez, quando encontrarmos n na árvore, ele não terá filhos
            // e a remoção será feita
            a->e = remove_no(a->e, n); 
        }
    }
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
        puts("6: limpar a árvore");
        puts("7: remover um número da árvore");
        puts("-1: encerrar o programa");

        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            puts("que número?");
            scanf("%d", &n);
            a = insere(a, n);
            putchar('\n');
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
        case 6:
            limpa(a);
            puts("\nÁrvore limpa\n");
            break;
        case 7: 
            puts("Que número deseja remover?");
            scanf("%d", &n);
            a = remove_no(a, n);
            puts("Removido!");
            puts("ou não, ainda não verifiquei se n está na árvore, pode ser que dê problema isso aí\n");
            break;
        case -1:
            return;
        default:
            puts("\nValor inválido!\n");
            break;
        }
    } while (escolha);
}