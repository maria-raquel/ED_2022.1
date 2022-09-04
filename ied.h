
#ifndef IED_H
#define IED_H

/* Exercicios da Parte I do livro Introdução a 
 * Estruturas de Dados, de Celes, Cerqueira e Rangel
 */

// Capitulo 1: Funcoes simples
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y);
int primo(int n);
int fibonacci(int n);
int soma_impares(int n);
double pi(int n);

// Capitulo 2: Passagem de parametros por referencia
int raizes(float a, float b, float c, float* x1, float* x2);
void calc_esfera(float r, float* area, float* volume);

// Capitulo 3: Vetores
int negativos (int n, float*vet);
int pares(int n, int* vet);
void inverte (int n, int* vet);

#endif