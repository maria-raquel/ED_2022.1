#include <stdio.h>

/* Duas funcoes que retornam o n-esimo elemento da sequencia de Fibonacci
   Uma com passagem de parametro por valor, a outra por referencia
 */ 

int fib_por_valor(int n);
int fib_por_ref(int *p);

int main(){
    puts("Sequencia de Fibonacci, por valor: ");
    for(int i=1; i <= 10; i++)
        printf("%d ", fib_por_valor(i));
    putchar('\n');

    puts("Sequencia de Fibonacci, por referencia: ");
    for(int i=1; i <= 10; i++)
        printf("%d ", fib_por_ref(&i));
    putchar('\n');

    return 0;
}

int fib_por_valor(int n){
    if (n==1 || n==2)
        return 1;
    
    int a=1, b=1, c;

    for(int i=3; i++<=n;)
        c=a+b, a=b, b=c;
    
    return c;
}

int fib_por_ref(int *p){
    fib_por_valor(*p);
}