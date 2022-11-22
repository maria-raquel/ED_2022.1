///////////////////////////////////////////////////////////
///////////////// AVALIADOR DE EXPRESSÕES /////////////////
/////////////// exemplo de uso da ED pilha ////////////////
/////////// Maria Raquel Martinez - 20200025900 ///////////
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 21

// Definição do tipo dos nós da pilha que armazenará os caracteres da expressão a ser avaliada
typedef struct No{
    char caractere;
    struct No *prox;
} No;

// Faz com que o ponteiro pilha seja nulo
void cria_pilha(No** pp);

// Retorna 1 se a pilha estiver vazia, 0 se não
int esta_vazia(No* pilha);

// Insere um elemento na pilha
void push(No** pp, char c);

// Remove um elemento da pilha
void pop(No** pp);

// Retorna o topo da pilha
char topo(No* pilha);

int main(){
    char expressao[N];
    No* pilha;
    cria_pilha(&pilha);

    puts("-----------------> Avaliador de Expressões <-----------------");
    puts("---> Avalia se uma expressão matemática cheia de chaves, colchetes e parenteses está devidamente pontuada");
    puts("---> Ou seja, se você abriu e fechou bonitinho tudo que era pra abrir e fechar");
    puts("---> Digite a expressão a ser avaliada, sem espaços entre os caracteres: ");
    puts("---> Por exemplo, ({12+[24/3]}*2)/6");
    scanf("%s", expressao);

    // Todo caractere que abre - (, {, [ - é empilhado
    // Todo que fecha - ), }, ] - é comparado com o topo da pilha
    // Se eles combinam, o que abre é desempilhado, 
    // Se não combinam é porque a expressão está errada
    // Se a pilha, ao fim da avaliação, estiver vazia, a expressão está correta
    // Se não estiver, a expressão está errada

    for(int i=0; expressao[i]!='\0'; i++){

        switch (expressao[i]){
            case '(':
                push(&pilha, expressao[i]);
                break;

            case '{':
                push(&pilha, expressao[i]);
                break;

            case '[':
                push(&pilha, expressao[i]);
                break;

            case ')':
                if (topo(pilha) == '(')
                    pop(&pilha);
                else {
                    puts("Expressão errada :(");
                    return 0;
                }
                break;

            case '}':
                if (topo(pilha) == '{')
                    pop(&pilha);
                else {
                    puts("Expressão errada :{");
                    return 0;
                }
                break;

            case ']':
                if (topo(pilha) == '[')
                    pop(&pilha);
                else {
                    puts("Expressão errada :[");
                    return 0;
                }
                break;
                
            default:
                break;
        }
    }

    if (esta_vazia(pilha)){
        puts("Expressão correta :) :} :]");
        return 0;
    }

    else 
        puts("Expressão errada :( :{ :[");

    return 0;
}

void cria_pilha(No** pp){
    (*pp) = NULL;
}

int esta_vazia(No* p){
    if(!p)
        return 1;
    return 0;
}

void push(No** pp, char c){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo) return;
    novo->caractere = c;
    novo->prox = (*pp);
    *pp = novo;
}

void pop(No** pp){
    if (!(*pp)) return;
    No* tchau = (*pp);
    (*pp) = (*pp)->prox;
    free(tchau);
}

char topo(No* pilha){
    if (!pilha)
        return 0;
    return pilha->caractere;
}