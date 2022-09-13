#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{     // definindo um tipo Pessoa, usaremos apenas na questao 3
    char *nome;
    int idade;
} Pessoa;

int people_sorter(Pessoa *a, Pessoa *b);

int main(){

	// Questao 1: ler nome e idade de n pessoas e guardar os dados em um arquivo de texto
	
	FILE *file1; 
	file1 = fopen("fq1.txt", "w");

	if(!file1){
		puts("Arquivo nao aberto (q1)");
		return 0;
	}

	int n;
	printf("Digite a quantidade de pessoas: ");
	scanf("%d", &n);

	for (int i=0; i<n; i++) {
		char nome[30];
		int idade;

		printf("Digite o nome da %d pessoa: ", i+1);
		scanf("%s", nome);

		printf("Digite a idade da %d pessoa: ", i+1);
		scanf("%d", &idade);

		fprintf(file1, "%s - %d anos\n", nome, idade);
	}

	fclose(file1);

	// Questao 2: Mostrar o nome das pessoas com mais de 18 anos

	// disclaimer: nao estou fazendo da forma mais otimizada, simples ou bonitinha,
	// apenas de forma a estudar e exercitar mais o assunto objetivo da ativivade

	FILE *file2;
	file2 = fopen("fq1.txt", "r");

	if(!file2){
		puts("Arquivo nao aberto (q2)\n");
		return 0;
	}

	puts("Maiores de idade: ");
	while (!feof(file2)) {
		char nome[30];
		int idade;
		fscanf(file2, "%s - %d anos\n", nome, &idade);
		if (idade >= 18)
			puts(nome);
	}

	fclose(file2);

	// Questao 3: Ordenar os nomes e salvar em um novo arquivo, com as idades

	FILE *file3, *file4;

	file3 = fopen("fq1.txt", "r"); // arquivo com as informacoes das pessoas

	if (!file3) {
		puts("Arquivo nao aberto (q3, a1)\n");
		return 0;
	}

	Pessoa *people; // declarando um ponteiro para um array de Pessoas

	people = (Pessoa*) malloc (n * sizeof(Pessoa)); // alocando memoria

	if (!people){
		puts("Memoria nao alocada");
		return 0;
	}

	int i=0;
	while (!feof(file3)) { // salvando as informacoes de cada pessoa no array de Pessoas
		char nome[30];
		fscanf(file3, "%s - %d anos\n", nome, &people[i].idade);
		people[i].nome = (char*) malloc(sizeof(strlen(nome)) + sizeof(char)); 
		//lembrando que o sizeof nao considera '\0'
		strcpy(people[i].nome, nome);
		i++;
	}

	fclose(file3);

	/* Para ordenar os nomes, usaremos a funcao strcmp(str1, str2)

		Ela retorna:
			0 quando str1 = str2
    		< 0 se o valor na tabela ASCII do primeiro caractere divergente em 
		str1 for MENOR que o de str2 (str1 < str2)
    		> 0 se o valor na tabela ASCII do primeiro caractere divergente em 
		str1 for MAIOR que o de str27 (str1 > str2)
	*/

	int menor; // indice do nome "menor" na tabela ascii

	for (int i=0; i<n; i++){
		menor = i;
		for (int j=0; j<n; j++){ // percorre todos os elementos, para achar o menor
			if (strcmp(people[menor].nome, people[j].nome) > 0){
				continue;
			}
			if (strcmp(people[menor].nome, people[j].nome) < 0){
				menor = j;
				continue;
			}
			else // quando os nomes forem iguais, ordenaremos por idade
				if (people[menor].idade < people[j].idade)
					menor = j;
		}
		if (menor == i)
			continue;
		else {
			char* temp = people[i].nome; // variavel temporaria recebe conteudo no indice i
			people[i].nome = people[menor].nome; // indice i recebe o menor nome
			people[menor].nome = temp; // a antiga posicao do menor recebe temp
		}
	}

	file4 = fopen("fq3.txt", "w");

	for (int i=0; i<n; i++)
		fprintf(file4, "%s - %d anos\n", people[i].nome, people[i].idade);

	fclose(file4);

	return 0;
}