#include <stdio.h>
#define N 10

// LISTA SIMPLES

// definicao da lista
typedef struct{
    int vetor[N];
    int ctrl; // indice de ocupacao
    //representa o indice do ultimo elemento
    // N-1 se a lista esta cheia, -1 se esta vazia
} Lista;

// assinaturas
void cria_lista (Lista *l);
int insere_fim (Lista *l);
void limpa_lista (Lista *l);
int remove_fim (Lista *l);
int mostra_lista(Lista *l);
int menu(Lista *l);

// main
int main(){
    Lista lista;
    cria_lista(&lista);
    menu(&lista);
    return 0;
}

// implementacao das funcoes

void cria_lista (Lista *l){
    l->ctrl = -1;
}

int insere_fim (Lista *l){
    if (l->ctrl == N-1) // verificando se ha espaco na lista
        return 0;

    int insercao;
    puts("Que numero deseja inserir?");
    scanf("%d", &insercao);
    l->vetor[++(l->ctrl)] = insercao; // incrementa ctrl e insere o elemento no fim
    puts("Numero inserido");
    putchar('\n');
    return 1;
}

void limpa_lista (Lista *l){
    l->ctrl = -1;
    puts("Lista limpa");
    putchar('\n');
}

int remove_fim (Lista *l){
    if (l->ctrl == -1){ // verifica se a lista esta vazia
        return 0;
        puts("Lista vazia");
        putchar('\n');
    }
    l->ctrl--;
}

int mostra_lista(Lista *l){
    if (l->ctrl == -1){
        puts("Lista vazia");
        putchar('\n');
        return 0;
    }

    else for (int i=0; i <= l->ctrl-1; i++)    
        printf("%d, ", l->vetor[i]);

    printf("%d\n", l->vetor[l->ctrl]);
    putchar('\n');
}

int menu(Lista *l){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar lista");
    puts("2: inserir elemento na lista");
    puts("3: remover ultimo elemento da lista");
    puts("4: limpar a lista");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: mostra_lista(l);
                break;
        case 2: insere_fim(l);
                break;
        case 3: remove_fim(l);
                break;
        case 4: limpa_lista(l);
                break;
        case -1: return 0;
        default: puts("Valor invalido!");
                break;
    }
    
    menu(l);
}