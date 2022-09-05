#include <math.h>
#include "ied.h"

/* Exercicios da Parte I do livro Introdução a 
 * Estruturas de Dados, de Celes, Cerqueira e Rangel
 */

/* Indica se um ponto (x,y) esta localizado dentro (retorna 1)
   ou fora (retorna 0) de um retangulo. 
   -> (x0,y0): vertice inferior esquerdo do retangulo
   -> (x1,y1): vertice superior direito do retangulo
   -> (x,y): ponto a ser testado
 */
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
    if (x0<=x && x<=x1 && y0<=y && y<=y1)
        return 1;
    else
        return 0;
}

/* Testa se um numero eh primo (retorna 1) ou nao (retorna 0)
   -> n: numero a ser testado 
 */
int primo(int n){
    if(n==0 || n==1) // pois 0 e 1 nao sao primos
        return 0;

    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)
            return 0;

    return 1;
}

/* Retorna o n-esimo termo da serie de Fibonacci
  -> n: numero da posicao do termo (1, 2, 3, ...)
*/
int fibonacci(int n){
    if (n==1 || n==2)
        return 1;
    
    int a=1, b=1, c;

    for(int i=3; i++<=n;)
        c=a+b, a=b, b=c;
    
    return c;
}

// Retorna a soma dos n primeiros numeros impares
int soma_impares(int n){
    return n*n; 
    // uma propriedade dos numeros impares que usamos aqui:
    // a soma dos n primeiros números impares eh o n-esimo quadrado perfeito
}

/* Retorna uma aproximacao do valor de pi, de acordo com a formula de Leibniz:
   Para n termos, a formula eh 4 vezes a soma de (-1) elevado a i dividido por
   i vezes 2 mais 1, i varia de 0 a n-1.
   -> n: numeros de termos da sequencia a serem calculados
 */
double pi(int n){
    double sum=0;
    for(double i=0; i<n; i++){
        if( (int)i % 2 == 0)
            sum += 1/(2*i+1);
        else
            sum -= 1/(2*i+1);
    }
    // O if e o else substituem o (-1) elevado a i na equacao, ja que C nao
    // possui nativamente um operador de potencializacao
   return 4*sum;
}

/* Calcula as raizes reais de uma equacao de segundo grau do tipo ax^2+bx+c=0
   e retorna o numero de raizes reais

   Se existirem raizes reais, elas serao armazanadas nas variaveis apontadas por x1 e x2

   Atente-se que, ao final da execucao da funcao, os valores armazenados em x1 e x2
   podem nao representar raizes validas, se a equacao tiver apenas uma ou nenhuma
   solucao real. Verifique o retorno da funcao para saber se eh o caso.

   -> a: coeficiente que multiplica x^2
   -> b: coeficiente que multiplica x
   -> c: parcela fixa da equacao
   -> x1: ponteiro que aponta para a variavel que armazenara a primeira raiz real
   -> x2: ponteiro que aponta para a variavel que armazenara a segunda raiz real
 */
int raizes(float a, float b, float c, float *x1, float *x2){
    float delta = b*b - 4*a*c;

    if(delta<0)
        return 0;
    
    else if(delta == 0){
        *x1 = -b/(2*a);
        return 1;
    }

    else{
        *x1 = (-b + sqrt(delta)) / (2*a);
        *x2 = (-b - sqrt(delta)) / (2*a);
        return 2;
    }
}

/* Calcula a area da superficie e o volume de uma esfera a partir de seu raio
   -> r: raio da esfera
   -> area: ponteiro que aponta para a variavel que armazenara a area
   -> volume: ponteiro que aponta para a variavel que armazenara o volume
 */
void calc_esfera(float r, float* area, float* volume){
    *area = 4*r*r;
    *volume = *area*r/3;
}

/* Retorna a quantidade de numeros negativos armazenados em um vetor
   -> n: tamanho do vetor
   -> vet: vetor
 */
int negativos(int n, float*vet){
    int counter = 0;
    for (int i=0; i<n; i++)
        if (vet[i]<0)
            counter++;
    return counter;
}

/* Retorna a quantidade de numeros pares armazenados em um vetor
   -> n: tamanho do vetor
   -> vet: vetor
 */
int pares(int n, int* vet){
    int counter = 0;
    for (int i=0; i<n; i++)
        if (vet[i]%2 == 0)
            counter++;
    return counter;
}

/* Inverte a ordem dos elementos de um vetor
   -> n: tamanho do vetor
   -> vet: vetor a ser invertido
 */
void inverte (int n, int* vet){
    for(int i=0, j=n-1, temp; i<j; i++, j--){
        temp = vet[i], vet[i] = vet[j], vet[j] = temp;
    }
}

/* Avalia um polinomio, ou seja, calcula p(x) a partir de um x dado
   Retorna o valor para p(x)
   -> poli: vetor com os coeficientes do polinomio
   por exemplo, para 3x^2 + 2x + 12, poli[] = {12,2,3}
   -> grau: grau do polinomio
   -> x: valor de x a ser substituido
 */
double avalia(double* poli, int grau, double x){
    double sum = 0;
    for (int i=0; i < grau+1; i++)
        sum += poli[i]*pow(x,i);
    return sum;
}

void deriva(double* poli, int grau, double* out){
    for (int i=1; i < grau+1; i++)
        out[i-1] = poli[i]*i;
}