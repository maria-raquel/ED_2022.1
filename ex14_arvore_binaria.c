///////////////////////////////////////////////////
///////////////// ÁRVORE BINÁRIA //////////////////
///////// definição e implementação da ED /////////
///////////////////////////////////////////////////

typedef struct No {
    int dado;
    struct No* e;
    struct No* d;
} No;

// aloca o espaço, preenche os campos e retorna um ponteiro
// deve ser atribuído a uma variável 
No* cria_no(int n, No* esquerda, No* direita);

int main(){
    No* arvore = cria_no(0,0,0);
    return 0;
}

No* cria_no(int n, No* esquerda, No* direita){
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->dado = n;
    novo->e = esquerda;
    novo->d = direita;
    return novo;
}