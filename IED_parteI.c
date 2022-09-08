#include <stdio.h>
#include <math.h>
#include "ied.h"

int main(){
    puts("Teste da funcao dentro_ret: ");
    printf("Ponto (2,2), Retangulo [(2,2), (3,3)]: %d\n", dentro_ret(2, 2, 3, 3, 2, 2));
    putchar('\n');
    
    puts("Teste da funcao primo:");
    for(int i=0; i<=10; i++)
        printf("%d é %d, ", i, primo(i));
    putchar('\n');
    putchar('\n');

    puts("Teste da funcao fibonacci: ");
    puts("Sequencia de Fibonacci, 10 termos: ");
    for(int i=1; i <= 10; i++)
        printf("%d ", fibonacci(i));
    putchar('\n');
    putchar('\n');

    puts("Teste da funcao soma_impares: ");
    puts("Soma dos numeros impares: ");
    for(int i=1; i <= 10; i++)
        printf("%d: %d, ", i, soma_impares(i));
    putchar('\n');
    putchar('\n');

    puts("Teste da funcao pi: ");
    for(int i=1; i <= 10; i++)
        printf("%d: %lf, ", i, pi(i));
    putchar('\n');
    putchar('\n');

    float r1, r2;
    r1 = r2 = 0; 

    puts("Teste da funcao raizes: ");
    raizes(1,2,-3, &r1, &r2);
    printf("raiz 1 (se tiver): %f, raiz 2 (se tiver): %f\n", r1, r2);
    putchar('\n');

    float ar, vol, raio = 1;
    ar = vol = 0;
    calc_esfera(raio, &ar, &vol);
    puts("Teste da funcao raio: ");
    printf("raio: %f, area: %f, volume: %f\n", raio, ar, vol);
    putchar('\n');

    puts("Teste da funcao negativos: ");
    float array1[] = {-12.3, 0, 12, -1, 0.3};
    printf("Numeros negativos no array: %d\n", negativos(sizeof(array1)/sizeof(float), array1));
    putchar('\n');

    puts("Teste da funcao pares: ");
    int array2[] = {-12, 0, 12, -1, 3};
    printf("Numeros pares no array: %d\n", pares(sizeof(array2)/sizeof(int), array2));
    putchar('\n');

    puts("Teste da funcao inverte: ");
    int array3[] = {1,2,3,4,5,6};
    inverte(sizeof(array3)/sizeof(int), array3);
    for (int i=0; i < sizeof(array3)/sizeof(int); i++)
        printf("%d ", array3[i]);
    putchar('\n');
    putchar('\n');

    puts("Teste da funcao avalia: ");
    double array4[] = {1,2,3};
    printf("p(x) = %lf\n", avalia(array4, 2, 1));
    putchar('\n');

    puts("Teste da funcao deriva: ");
    double array5[] = {3,4,2,5,6}, array5_derivado[4] = {0};
    deriva(array5, sizeof(array5)/sizeof(double)-1, array5_derivado);
    for (int i=0; i < sizeof(array5_derivado)/sizeof(double); i++)
        printf("%lf ", array5_derivado[i]);
    putchar('\n');
    putchar('\n');

    puts("Teste da funcao conta_vogais: ");
    char frase[] = "aspas duplas";
    printf("vogais na frase: %d\n", conta_vogais(frase));
    putchar('\n');

    puts("Teste da funcao conta_char: ");
    char frase4[] = "salada com uvas", car = 'a';
    printf("tem %d %c's na frase\n", conta_char(frase4, car), car);
    putchar('\n');

    puts("Teste da funcao minusculo: ");
    char frase2[] = "AlgUma CoISa";
    minusculo(frase2);
    printf("%s\n", frase2);
    putchar('\n');

    puts("Teste da funcao shift_string: ");
    char frase3[] = "ZEBRAS?! zebras";
    shift_string(frase3);
    printf("%s\n", frase3);
    putchar('\n');

    puts("Teste da funcao string_oposta: ");
    char letras[] = "abc mn xyz ABC MN XYZ";
    string_oposta(letras);
    puts(letras);
    putchar('\n');

    puts("Teste da funcao roda_string: ");
    char palavra[] = "macacos";
    roda_string(palavra);
    puts(palavra);
    putchar('\n');

    puts("Teste das segundas versoes das funcoes minusculo, shift_string, string_oposta e roda_string: ");
    char frase2_v2[] = "AlgUma CoISa";
    puts(minusculo_v2(frase2_v2));
    char frase3_v2[] = "ZEBRAS?! zebras";
    puts(shift_string_v2(frase3_v2));
    char letras2[] = "abc mn XYZ";
    puts(string_oposta_v2(letras2));
    char frase4_v2[] = "soda";
    puts(roda_string_v2(frase4_v2));

    return 0;
}