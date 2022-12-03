///////////////////////////////////////////////////
///////////////// ÁRVORE BINÁRIA //////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

typedef struct No {
    int dado;
    struct No* e;
    struct No* d;
} No;

// Crua uma árvore vazia, deve ser atribuído a uma variável 
No* cria_arvore();

// Aloca o espaço, preenche os campos e retorna um ponteiro
// Deve ser atribuído a uma variável 
No* cria_no(int n, No* esquerda, No* direita);

// Funções de imprimir, com diferentes formas de percorrer a árvore
void imprime_prefix(No* a);
void imprime_infix(No* a); // percurso que imprime árvores ordenadas
void imprime_posfix(No* a); // percurso que limpa árvores

int main(){
    No* arvore = cria_arvore();
    return 0;
}

No* cria_arvore(){
    return NULL;
}

No* cria_no(int n, No* esquerda, No* direita){
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->dado = n;
    novo->e = esquerda;
    novo->d = direita;
    return novo;
}

void imprime_prefix(No* a){
    if (a){
        printf("%d ", a->dado); // trata a raiz
        imprime_prefix(a->e); // percorre subarvore a esquerda
        imprime_prefix(a->d); // percorre subarvore a direita
    }
}

void imprime_infix(No* a){
    if (a){
        imprime_infix(a->e); // percorre subarvore a esquerda
        printf("%d ", a->dado); // trata a raiz
        imprime_infix(a->d); // percorre subarvore a direita
    }
}

void imprime_posfix(No* a){
    if (a){
        imprime_posfix(a->e); // percorre subarvore a esquerda
        imprime_posfix(a->d); // percorre subarvore a direita
        printf("%d ", a->dado); // trata a raiz
    }
}