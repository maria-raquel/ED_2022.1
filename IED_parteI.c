#include <stdio.h>
#include <math.h>
#include "ied.h"

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

    float r1, r2;
    r1 = r2 = 0; 

    raizes(1,2,-3, &r1, &r2);
    printf("raiz 1 (se tiver): %f, raiz 2 (se tiver): %f\n", r1, r2);

    float ar, vol, raio = 1;
    ar = vol = 0;
    calc_esfera(raio, &ar, &vol);
    printf("raio: %f, area: %f, volume: %f\n", raio, ar, vol);

    float array1[] = {-12.3, 0, 12, -1, 0.3};
    printf("Numeros negativos no array: %d\n", negativos(sizeof(array1)/sizeof(float), array1));

    int array2[] = {-12, 0, 12, -1, 3};
    printf("Numeros pares no array: %d\n", pares(sizeof(array2)/sizeof(int), array2));

    int array3[] = {1,2,3,4,5,6};
    inverte(sizeof(array3)/sizeof(int), array3);
    for (int i=0; i < sizeof(array3)/sizeof(int); i++)
        printf("%d ", array3[i]);
    putchar('\n');


    return 0;
}
