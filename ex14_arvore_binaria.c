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

// Retorna a altura da árvore
int altura(No* a);

// Insere um número na árvore no local correto 
No* insere(No* a, int n);

// Limpa a árvore, desalocando a memória
No* limpa(No* a);

// Remove o nó com o valor passado e rearranja os nós para manter a ordenação
No* remove_no(No* a, int n);

// Retorna 1 se um n está na árvore e 0 se não
int esta_na_arvore(No* a, int n);

// Retorna o menor nível no qual um número se encontra na árvore
int nivel(No* a, int n);

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
    if(!a) return NULL;
    limpa(a->e);
    limpa(a->d);
    free(a);
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
            // isso mantem a ordenação quando retirarmos n
            a->dado = aux->dado;
            aux->dado = n;

            // chamamos a função novamente
            // dessa vez, quando encontrarmos n na árvore, ele não terá filhos e a remoção será feita
            a->e = remove_no(a->e, n); 
        }
    }
    return a;
}

int esta_na_arvore(No* a, int n){
    if (!a) return 0;
    if (n < a->dado) return esta_na_arvore(a->e, n);
    if (n > a->dado) return esta_na_arvore(a->d, n);
    return 1;
}

int nivel(No* a, int n){
    if (!a) return -1;
    if (n < a->dado) return nivel(a->e, n)+1;
    if (n > a->dado) return nivel(a->d,n)+1;
    return 0;
}

void menu(No* a){
    int escolha = 0;
    int n;

    do{
        puts("O que deseja fazer com a árvore?");
        puts("1: inserir um número");
        puts("2: imprimir prefix");
        puts("3: imprimir infix");
        puts("4: imprimir posfix");
        puts("5: calcular a altura da árvore");
        puts("6: limpar a árvore");
        puts("7: remover um número da árvore");
        puts("8: verificar se um número está na árvore");
        puts("9: mostrar o menor nível onde se encontra um número na árvore");
        puts("-1: encerrar o programa");

        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            puts("\nQue número?");
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
            a = limpa(a);
            puts("\nÁrvore limpa!\n");
            break;
        case 7: 
            puts("\nQue número?");
            scanf("%d", &n);
            if (esta_na_arvore(a, n)){
                a = remove_no(a, n);
                puts("Removido!\n");
            }
            else printf("%d não está na árvore!\n\n", n);
            break;
        case 8: 
            puts("Que número?");
            scanf("%d", &n);
            if (esta_na_arvore(a, n)) 
                printf("\n%d está na árvore!\n\n", n);
            else 
                printf("\n%d não está na árvore!\n\n", n);
            break;
        case 9:
            puts("Que número deseja verificar?");
            scanf("%d", &n);
            if (esta_na_arvore(a, n)) 
                printf("\n%d está no nível %d\n\n", n, nivel(a, n));
            else 
                printf("\n%d não está na árvore!\n\n", n);
            break;
        case -1:
            return;
        default:
            puts("\nValor inválido!\n");
            break;
        }
    } while (escolha);
}