// Exercício: Escrever um programa para gerar tabela ASCII usando uma única variável do tipo char

#include <stdio.h>

int main (){

    unsigned char ch = 0; 

    /* 
        A tabela ascii vai de 0 a 255 caracteres

        Para criar um loop que os imprime na tela, o codigo
        for(; ch < 256; ch++) entraria em loop infinito

        Isso ocorre porque o tipo char ocupa um byte de memoria,
        que consegue representar os numeros de 0 a 255.

        No for, ao chegar em ch = 255, ch eh impresso na tela e incrementado

        Porém, como dito, o tipo char não suporta o valor 256 (10000000 em binario)

        Nesse incremento, ch vai de 255 (11111111 em binário) para 0
        entrando novamente no loop

        Dessa forma, o teste logico ch < 256 sempre falhara

        O mesmo problema ocorreria se tentassemos for(; ch <= 255; ch++)

        Portanto, para imprimir todos os caracteres da tabela ascii, devemos
        imprimir os 254 primeiros caracteres, e imprimir ch = 255 fora do loop

     */ 

    for(; ch < 255; ch++){
        putchar(ch);
        putchar('\n');
    }

    putchar(ch);
    putchar('\n');

    return 0;
}
