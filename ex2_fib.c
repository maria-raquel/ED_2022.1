#include <stdio.h>

// funcao que retorna o enesimo elemento da sequencia de fibonacci

int fib(int);

int main(){
    printf("%d\n", fib(6));
    return 0;
}

int fib(int n){
    if (n==1 || n==2)
        return 1;
    
    int a=1, b=1, c;

    for(int i=3; i++<=n;)
        c=a+b, a=b, b=c;
    
    return c;
}