///////////////////////////////////////////////////
///////////////// LISTA ENCADEADA /////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// a lista é um ponteiro para o primeiro nó
// cada nó é do tipo a seguir
typedef struct No{
    int dado; // informação armazenada
    struct No *prox; // ponteiro para próximo nó
} No;

// FUNÇÕES IMPLEMENTADAS:
// Algumas são funções mais básicas, mais necessárias,
// outras são exercícios do livro Introdução a Estruturas de Dados, de Celes, Cerqueira e Rangel

// nas funções, ll é ponteiro para a lista
// quando quiser usar a lista (o ponteiro para o primeiro elemento) na função, usar *ll

void cria_lista(No** ll);
// faz o ponteiro lista ser nulo

int comprimento(No* l);
// retorna o comprimento da lista

void concatena(No** ll1, No** ll2);
// concatena duas listas, a lista 2 é adicionada ao fim da lista 1

No* copia(No* l);
// retorna um ponteiro para uma cópia da lista l

int igual(No* l1, No* l2);
// retorna 1 se as listas forem iguais, 0 se forem diferentes;

void insere_inicio(No** ll, int n);
void insere_fim(No** ll, int n);
// cria, preenche e insere o novo nó

void inverte(No** ll);
// inverte a lista, (1 2 3 4) vira (4 3 2 1)

void limpa_lista(No** ll);
// faz o ponteiro lista ser nulo e libera a memória alocada para cada nó

int maiores(No* l, int n);
// retorna quantos elementos da lista são maiores que n

void menu(No **ll);
void menu2(No **ll1, No** ll2);

void merge(No** ll1, No** ll2);
// junta as duas listas, intercalando os nós

void mostra_lista(No** ll);

void remove_inicio(No** ll);
void remove_fim(No** ll);
// remove da lista e dá free no nó

void remove_n(No** ll,int n);
// remove todas as instâncias de um elemento da lista

No* separa(No** ll, int n);
// separa uma lista em duas, depois da primeira ocorrencia de um elemento passado
// retorna o ponteiro para a segunda lista

No* ultimo(No* l);
// retorna um ponteiro para o último elemento da lista

int main(){
    No *lista1; 
    cria_lista(&lista1);
    puts("\n///// LISTA 1 /////\n");
    menu(&lista1);

    No *lista2;
    cria_lista(&lista2);
    puts("\n///// LISTA 2 /////\n");
    menu(&lista2);

    puts("\n///// LISTAS 1 E 2 /////\n");
    menu2(&lista1, &lista2);

    // para desalocar a memória

    if (lista1)
        limpa_lista(&lista1);
    
    if (lista2)
        limpa_lista(&lista2);

    return 0;
}

void cria_lista(No** ll){
    *ll = NULL;
    return;
}

int comprimento(No* l){
    int count = 0;

    for(No* aux = l; aux; aux = aux->prox)
        count++;

    return count;
}

void concatena(No** ll1, No** ll2){
    if (!(*ll1)){
        *ll1 = *ll2;
        return;
    }

    No* aux = (*ll1);
    for(; aux->prox; aux = aux->prox);
    
    aux->prox = (*ll2);
    (*ll2) = NULL;
}

No* copia(No* l){
    if(!l)
        return NULL;

    No* lista_nova = (No*)malloc(sizeof(No));
    lista_nova->dado = l->dado;

    No* ultima_nova = lista_nova;

    for(No* percorre_l = l->prox; percorre_l; percorre_l = percorre_l->prox){
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = percorre_l->dado;
        ultima_nova->prox = novo;
        ultima_nova = novo;
    }
    ultima_nova->prox = NULL;
    return lista_nova;
}

int igual(No* l1, No* l2){
    if (!l1 && !l2) // se as duas forem vazias
        return 1;

    if (!l1 || !l2) // se uma for vazia e a outra não
        return 0;

    No *aux1, *aux2;
    aux1 = l1;
    aux2 = l2;

    while (aux1 && aux2){
        if (aux1->dado != aux2->dado)
            return 0;
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    // se ambos auxs forem nulos, a lista inteira foi percorrida
    // se um não for nulo, uma das listas é maior que a outra, portanto não são iguais
    if (!aux1 && !aux2)
        return 1;
    else
        return 0;
}

void insere_inicio(No**ll, int n){
    // ll é o endereço da lista, ou seja, é um ponteiro para um ponteiro para o primeiro nó

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    if(!novo){
        puts("\nNão iserido: memória insuficiente!\n");
        return;
    }

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = *ll;

    // inserindo o novo nó na lista;
    *ll = novo;

    puts("\nInserido!\n");
}

void insere_fim(No**ll, int n){
    if(!(*ll)){
        insere_inicio(ll, n);
        return;
    }

    // criando o novo nó
    No* novo;
    novo = (No*) malloc(sizeof(No));
    
    if(!novo){
        puts("\nNão iserido: memória insuficiente!\n");
        return;
    }

    // preenchendo o novo nó
    novo->dado = n;
    novo->prox = NULL;

    // inserindo na lista
    No* aux = *ll;
    for (; aux->prox; aux = aux->prox);
    
    aux->prox = novo;

    puts("\nInserido!\n");
}

void inverte(No** ll){
    if(!(*ll))
        return;

    No *aux, *aux_ante, *aux_prox;
    aux = (*ll);
    aux_prox = aux->prox;
    aux_ante = NULL;

    while(aux_prox){
        aux->prox = aux_ante;
        aux_ante = aux;
        aux = aux_prox;
        aux_prox = aux->prox;
    }

    aux->prox = aux_ante;
    (*ll) = aux;
}

void limpa_lista(No** ll){
    if(!(*ll)){
        return;
    }

    No* aux_free = *ll; // vai liberar a memoria de cada nó
    No* aux_proximo = (*ll)->prox; // vai salvar o endereço do próximo nó a ser liberado
    
    *ll = 0;

    for(; aux_proximo;){
        free(aux_free);
        aux_free = aux_proximo;
        aux_proximo = aux_proximo->prox;
    }

    free(aux_free);
}

int maiores(No* l, int n){
    int count = 0;

    for(No* aux = l; aux; aux = aux->prox)
        if (aux->dado > n)
            count++;
    
    return count;
}

void menu(No **ll){
    int escolha;
    do{
        puts("Digite o que deseja fazer:");
        puts("1: mostrar a lista");
        puts("2: inserir elemento no início da lista");
        puts("3: inserir elemento no fim da lista");
        puts("4: remover elemento no início da lista");
        puts("5: remover elemento no fim da lista");
        puts("6: limpar a lista");
        puts("7: mostrar o comprimento da lista");
        puts("8: quantos elementos são maiores que um número dado");
        puts("9: remover todos as instâncias de um número dado");
        puts("10: mostrar o último elemento da lista");
        puts("11: separar a lista em duas");
        puts("12: inverter a lista");
        puts("13: copiar a lista");
        puts("0: encerrar");

        scanf("%d", &escolha);

        int n = 0;
        No* aux = NULL;

        switch (escolha) {
            case 1: puts("\nSua lista: ");
                    mostra_lista(ll);
                    putchar('\n');
                    break;

            case 2: puts("Que elemento deseja inserir? ");
                    scanf("%d", &n);
                    insere_inicio(ll, n);
                    break;

            case 3: puts("Que elemento deseja inserir? ");
                    scanf("%d", &n);
                    insere_fim(ll, n);
                    break;

            case 4: remove_inicio(ll);
                    break;        
            
            case 5: remove_fim(ll);
                    break;

            case 6: limpa_lista(ll);
                    puts("\nLista limpa!\n");
                    break;
            
            case 7: printf("\nComprimento: %d\n\n", comprimento(*ll));
                    break;

            case 8: puts("Que número? ");
                    scanf("%d", &n);
                    printf("\n%d elementos são maiores que %d\n\n", maiores(*ll, n), n);
                    break;
            
            case 9: puts("Que número? ");
                    scanf("%d", &n);
                    remove_n(ll, n);
                    break;

            case 10: aux = ultimo(*ll);
                     if (!aux){
                        puts("\nLista vazia!\n");
                        break;
                     }
                     printf("\nÚltimo elemento: %d\n\n", aux->dado);
                     break;

            case 11: puts("Depois de que elemento? ");
                     scanf("%d", &n);
                     aux = separa(ll, n);
                     puts("Primeira lista:");
                     mostra_lista(ll);
                     puts("Segunda lista:");
                     mostra_lista(&aux);
                     putchar('\n');
                     limpa_lista(&aux); // pra desalocar a memória
                     break;

            case 12: puts("\nLista invertida: ");
                     inverte(ll);
                     mostra_lista(ll);
                     putchar('\n');
                     break;
            
            case 13: puts("\nLista original: ");
                     mostra_lista(ll);
                     puts("\nCópia: ");
                     aux = copia(*ll);
                     mostra_lista(aux);
                     limpa_lista(&aux);
                     putchar('\n');
                     break;

            case 0: return;

            default: puts("\nValor inválido! Selecione um número entre 1 e 13.\n");
                    break;
        }
    } while (escolha);
}

void menu2(No **ll1, No** ll2){
    int escolha = 1;
    do{
        puts("Digite o que deseja fazer com as duas listas:");
        puts("1: mostrar as listas");
        puts("2: concatenar as listas");
        puts("3: mergir as listas");
        puts("4: verificar se as listas são iguais");
        puts("0: encerrar");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1: puts("\nLista 1: ");
                    mostra_lista(ll1);
                    puts("\nLista 2: ");
                    mostra_lista(ll2);
                    putchar('\n');
                    break;

            case 2: puts("\nListas concatenadas: ");
                    concatena(ll1, ll2);
                    mostra_lista(ll1);
                    putchar('\n');
                    break;

            case 3: merge(ll1, ll2);
                    puts("\nListas mergidas: ");
                    mostra_lista(ll1);
                    putchar('\n');
                    break;
            
            case 4: if (igual(*ll1, *ll2))
                        puts("\nAs listas são iguais!\n");
                    else
                        puts("\nAs listas são diferentes!\n");                    
                    break;

            case 0: return;

            default: puts("\nValor inválido! Selecione um número entre 1 e 3.\n");
                    break;
        }
    } while (escolha);
}

void merge(No** ll1, No** ll2){
    if (!(*ll1)){
        (*ll1) = (*ll2);
        return;
    }

    if (!(*ll2))
        return;
    
    No *aux1, *aux2, *aux1_prox, *aux2_prox;
    aux1 = (*ll1);
    aux2 = (*ll2);
    
    for(int i=3; ;i++){
        if (i%2 && aux1 && aux2){ // se estamos numa iteração ímpar, ou seja, adicionando um nó de l1
            aux1_prox = aux1->prox;
            aux1->prox = aux2;
            aux1 = aux1_prox;
            continue;
        }
        if (!(i%2) && aux2 && aux1){ // se estamos numa iteração par, ou seja, adicionando um nó de l2
            aux2_prox = aux2->prox;
            aux2->prox = aux1;
            aux2 = aux2_prox;
            continue;
        }

        else
            break;
    }

    (*ll2) = NULL;
}

void mostra_lista(No** ll){
    if (!(*ll)){
        puts("(vazia)");
        return;
    }

    printf("(");

    No* aux = *ll;
    for(; aux->prox; aux = aux->prox)
        printf("%d, ", aux->dado);

    printf("%d)\n", aux->dado);
}

void remove_inicio(No **ll){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    No* aux = *ll;

    // removendo da lista
    *ll = (*ll)->prox;

    // excluindo o elemento
    free(aux);

    puts("\nRemovido!\n");
}

void remove_fim(No **ll){
    if(!(*ll)){
        puts("\nLista vazia\n");
        return;
    }

    if(!(*ll)->prox){
        remove_inicio(ll);
        return;
    }
    
    No* aux = *ll;
    for(; aux->prox->prox; aux = aux->prox);
    // parando no elemento anterior ao que será removido

    free(aux->prox);
    aux->prox = NULL;
    puts("\nRemovido!\n");
}

void remove_n(No** ll,int n){
    if (!(*ll)){
        puts("\nLista vazia!\n");
        return;
    }

    // caso o primeiro elemento seja n,
    // retiramos até que seja diferente de n
    No* aux = (*ll);
    for (; aux && aux->dado == n;){
        (*ll) = aux->prox;
        free(aux);
        aux = (*ll);
    }

    // se o loop anterior limpar a lista inteira (todos os elementos são n)
    if(!(*ll)){
        puts("\nRemovidos!\n");
        return;
    }

    for(; aux && aux->prox; aux = aux->prox){
        // usamos o loop para remover instâncias seguidas de n
        for (; aux && aux->prox && aux->prox->dado == n;){
            No* remove = aux->prox;
            aux->prox = remove->prox;
            free(remove);
        }
    }
    
    puts("\nRemovidos!\n");
}

No* separa(No** ll, int n){
    if(!(*ll)){
        puts("\nLista vazia!\n");
        return NULL;
    }

    No* lista_nova = (*ll);

    for(; lista_nova && lista_nova->dado != n; lista_nova = lista_nova->prox);

    if (!lista_nova)
        return lista_nova;
    // se o elemento n não tá na lista, a primeira fica inalterada
    // a segunda é retornada vazia

    No* aux = lista_nova;
    lista_nova = lista_nova->prox;

    aux->prox = NULL;
    return lista_nova;    
}

No* ultimo(No* l){
    No* ultimo = (l);
    if (ultimo)
        for(; ultimo->prox; ultimo = ultimo->prox);
    return ultimo;
}
