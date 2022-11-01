//////////////////////////////////////////////////////////
///////////////// CALCULADORA PÓS FIXADA /////////////////
/////////////// exemplo de uso da ED pilha ///////////////
////////// Maria Raquel Martinez - 202000025900 //////////
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 21

// Definição do tipo dos nós da pilha que armazenará os operandos da expressão a ser avaliada
typedef struct No{
    float valor;
    struct No *prox;
} No;

// Faz com que o ponteiro pilha seja nulo
void cria_pilha(No** pp);

// Retorna 1 se a pilha estiver vazia, 0 se não
int esta_vazia(No* pilha);

// Insere um elemento na pilha
void push(No** pp, float n);

// Remove um elemento da pilha
void pop(No** pp);

// Recebe o valor do operando lido a partir da expressão matemática e o insere na pilha
void se_operando(No** pp, float n);

// Recebe o caractere que representa o operador e realiza a operação
void se_operador(No** pp, char o);

// Retorna o topo da pilha
float topo(No* pilha);

int main(){
    char expressao[N];
    puts("-----------------> Calculadora Pós-Fixada <-----------------");
    puts("---> Só realiza operações com números inteiros de 0 a 9.");
    puts("---> As operações apenas de (+), (-), (*) e (/)");
    puts("---> Digite a expressão matemática a ser avaliada, sem espaços entre os caracteres: ");
    puts("---> Por exemplo, 123++ (1+2+3) ou 96-45+* ((9-6)*(4+5))");
    scanf("%s", expressao);

    No* pilha;
    cria_pilha(&pilha);

    for(int i=0; expressao[i]!='\0'; i++){

        // Como o valor de entrada é tipo char, para convertê-lo para float, subtraímos o valor numérico
        // do caractere 0 na tabela ASCII e fazemos o cast
        if(expressao[i] >= '0' && expressao[i] <= '9'){
            float n = (float)expressao[i] - 48;
            se_operando(&pilha, n);
        } 

        else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/')
            se_operador(&pilha, expressao[i]);
    }

    printf("Resultado: %.5f\n", topo(pilha));
    return;
}

void cria_pilha(No** pp){
    (*pp) = NULL;
}

int esta_vazia(No* p){
    if(!p)
        return 1;
    return 0;
}

void push(No** pp, float n){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo) return;
    novo->valor = n;
    novo->prox = (*pp);
    *pp = novo;
}

void pop(No** pp){
    if (!(*pp)) return;
    No* tchau = (*pp);
    (*pp) = (*pp)->prox;
    free(tchau);
}

float topo(No* pilha){
    // Se a pilha estiver vazia, consideramos que o operando é 0
    if (!pilha)
        return 0 ;
    return pilha->valor;
}

void se_operando(No** pp, float n){
    push(pp, n);
}

void se_operador(No** pp, char op){
    float n1, n2, resultado;

    // Se a pilha estiver vazia, consideraremos que o operando é 0
    if (esta_vazia(*pp))
        n1 = n2 = 0.0;

    else{
        n1 = topo(*pp);
        pop(pp);
        n2 = topo(*pp);
        pop(pp);
    }

    switch (op)
    {
    case '+':
        resultado = n2+n1;
        break;
    case '-':
        resultado = n2-n1;
        break;
    case '/':
        resultado = n2/n1;
        break;
    case '*':
        resultado = n2*n1;
        break;
    default:
        break;
    }

    push(pp, resultado);
}