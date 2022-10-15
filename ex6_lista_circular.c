#include <stdio.h>
#define N 10

// LISTA CIRCULAR

// definicao da struct
typedef struct{
    int dados[N];
    int c_inicio; // indice do primeiro elemento, -1 se a lista estiver vazia
    int c_fim; // indice do ultimo elemento, -1 se a lista estiver vazia
    } Lista;

// assinatura das funcoes
void criar_lista(Lista *l);
int esta_cheia(Lista *l);
int esta_vazia(Lista *l);
int inserir_fim(Lista *l);
int inserir_inicio(Lista *l);
void limpar_lista(Lista *l);
int mostrar_lista(Lista *l);
int remover_fim(Lista *l);
int remover_inicio(Lista *l);
int menu(Lista *l);

// main
int main(){
    Lista lista;
    criar_lista(&lista);
    menu(&lista);
    return 0;
}

// implementacao das funcoes
void criar_lista(Lista *l){
    l->c_inicio = -1;
    l->c_fim = -1;
}

int esta_cheia(Lista *l){
    if (l->c_fim == N-1 && l->c_inicio == 0)
        return 1;
    if (l->c_inicio + 1 == l->c_fim)
        return 1;
    return 0;
}

int esta_vazia(Lista *l){
    if (l->c_fim == l->c_inicio && l->c_fim == -1)
        return 1;
    return 0;
}

int inserir_fim(Lista *l){
    if (esta_cheia(l))
        return 0;

    puts("\nO que deseja inserir?");
    int insercao;
    scanf("%d", &insercao);
    putchar('\n');

    if (l->c_fim == N-1)
        l->c_fim = 0;
    else if (esta_vazia(l))
        l->c_fim = l->c_inicio = 0;
    else 
        l->c_fim++;    
    
    l->dados[l->c_fim] = insercao;

    return 1;
}

int inserir_inicio(Lista *l){
    if (esta_cheia(l))
        return 0;
    
    puts("\nO que deseja inserir?");
    int insercao;
    scanf("%d", &insercao);
    putchar('\n');

    if (l->c_inicio == 0)
        l->c_inicio = N-1;
    else if (esta_vazia(l))
        l->c_inicio = l->c_fim = 0;
    else
        l->c_inicio--;

    l->dados[l->c_inicio] = insercao;

    return 1;
}

void limpar_lista(Lista *l){
    l->c_fim = l->c_inicio = -1;
}

int mostrar_lista(Lista *l){
    if (esta_vazia(l)){
        puts("\nLista vazia\n");
        return 0;
    }

    puts("\nSua lista:");
    if (l->c_fim >= l->c_inicio){
        for (int i=l->c_inicio; i<l->c_fim; i++)
            printf("%d, ", l->dados[i]);
        printf("%d\n", l->dados[l->c_fim]);
        return 1;
    }

    for (int i=l->c_inicio; i<N-1; i++)
        printf("%d, ", l->dados[i]);
    for (int i=0; i<l->c_fim; i++)
        printf("%d, ", l->dados[i]);
    printf("%d\n", l->dados[l->c_fim]);

    putchar('\n');

    return 1;
}

int remover_fim(Lista *l){
    if (esta_vazia(l))
        return 0;

    if (l->c_fim == l->c_inicio){
        l->c_fim = l->c_inicio = -1;
        return 1;
    }

    if (l->c_fim == 0){
        l->c_fim = N-1;
        return 1;
    }

    l->c_fim--;
    return 1;
}

int remover_inicio(Lista *l){
    if (esta_vazia(l))
        return 0;

    if (l->c_fim == l->c_inicio){
        l->c_fim = l->c_inicio = -1;
        return 1;
    }

    if (l->c_inicio == N-1){
        l->c_inicio = 0;
        return 1;
    }
    
    else l->c_inicio++;
    return 1;
}

int menu(Lista *l){
    puts("Digite o que deseja fazer:");
    puts("1: mostrar lista");
    puts("2: inserir elemento no inicio");
    puts("3: inserir elemento no fim");
    puts("4: limpar a lista");
    puts("5: remover elemento no inicio");
    puts("6: remover elemento no fim");
    puts("-1: encerrar");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: mostrar_lista(l);
                break;
        case 2: inserir_inicio(l);
                break;
        case 3: inserir_fim(l);
                break;
        case 4: limpar_lista(l);
                break;
        case 5: remover_inicio(l);
                break;
        case 6: remover_fim(l);
                break;
        case -1: 
                return 0;
        default: puts("Valor invalido!");
                break;
    }
    
    menu(l);
}