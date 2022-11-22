// Exercício: guardar dez nomes simples em um vetor de ponteiros alocado dinamicamente
//
// Regras:
//     alocar tudo dinamicamente
//     usar uma função para guardar os nomes
//     usar uma função para mostrar os nomes
//     lembrar de liberar a memória

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fill_name(char** names, int i);
void show_names(char** names);

int main(){
    char **list;

    // Alocando o vetor de ponteiros
    list = (char **) malloc(10*sizeof(char*));

    // Verificando se ocorreu a alocacao
    if (!list)
        return 0;

    // Preenchendo os nomes em cada posicao de list
    for (int i=0; i<10; i++)
        if (!fill_name(list, i)){              // Se a alocacao nao ocorrer,
            for(int j=0; j<i; j++)             // liberaremos a memoria das alocacoes anteriores
                free(list[j]);
            free(list);
            return 0;
        }

    // Mostrando os nomes guardados
    show_names(list);

    // Liberando a memoria
    for (int i=0; i<10; i++)
        free(list[i]);
    free(list);

    return 0;
}

int fill_name(char** names, int i){
    char name[100], *new_name;

    printf("Digite o %d nome: ", i+1);
    scanf("%s", name);

    new_name = (char *) malloc( (strlen(name)+1) * sizeof(char));
    if(!new_name)
        return 0;

    strcpy(new_name, name);
    names[i] = new_name;

    return 1;
}

void show_names(char** names){
    for (int i=0; i<10; i++)
        printf("%d: %s\n", i, names[i]);
}
