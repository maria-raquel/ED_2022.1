#include <stdio.h>

/* Exercicios da Parte I do livro Introdução a 
 * Estruturas de Dados, de Celes, Cerqueira e Rangel
 */

// Capitulo 1: funcoes simples
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);
int primo(int n);
int fibonacci(int n);
int soma_impares(int n);
double pi(int n);

int main(){
    printf("Teste funcao dentro_ret: %d\n", dentro_ret(2, 2, 3, 3, 2, 2));
    
    puts("Teste funcao primo:");
    for(int i=0; i<=20; i++)
        printf("%d é %d, ", i, primo(i));
    putchar('\n');

    puts("Sequencia de Fibonacci: ");
    for(int i=1; i <= 10; i++)
        printf("%d ", fibonacci(i));
    putchar('\n');

    puts("Soma dos numeros impares: ");
    for(int i=1; i <= 10; i++)
        printf("%d: %d, ", i, soma_impares(i));
    putchar('\n');

    puts("Aproximacoes de pi: ");
    for(int i=1; i <= 10; i++)
        printf("%d: %lf, ", i, pi(i));
    putchar('\n');    

    return 0;
}

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
   2 vezes i mais 1, i varia de 0 a n-1.
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
    /* O if e o else substituem o (-1) elevado a i na equacao, ja que C nao
       possui nativamente um operador de potencializacao
    */
   return 4*sum;
}