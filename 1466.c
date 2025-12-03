#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int x;
    struct no *esq;
    struct no *dir;
} no;

typedef struct cel {
    no *x;
    struct cel *seg;
} cel;

void push(cel *, no *);
cel* cria_fila();
int fila_vazia(cel* ff);
no* remove_fila(cel *ff);
no* cria_no(int x);
no* insere(no* raiz, int x);
void percorre_nivel(no* raiz);
void libera_arvore(no* raiz);

int main() {
    int c, n, valor;
    no* raiz;
    
    scanf("%d", &c);
    
    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        raiz = NULL;
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = insere(raiz, valor);
        }
        
        printf("Case %d:\n", i);
        percorre_nivel(raiz);
        printf("\n\n");
        
        libera_arvore(raiz);
    }
    
    return 0;
}

void push(cel *ff, no* x) {
    cel *anterior, *nova;
    anterior = ff;
    nova = malloc(sizeof(cel));
    nova->x = x;

    while (anterior->seg != ff) {
        anterior = anterior->seg;
    }

    anterior->seg = nova;
    nova->seg = ff;
}

cel* cria_fila() {
    cel* ff = (cel*)malloc(sizeof(cel));
    ff->seg = ff;
    ff->x = NULL;
    return ff;
}

int fila_vazia(cel* ff) {
    return ff->seg == ff;
}

no* remove_fila(cel *ff) {
    if (ff->seg != ff) {
        cel *p = ff->seg;
        no* no = p->x;
        ff->seg = p->seg;
        free(p);
        return no;
    }
    return NULL;
}

no* cria_no(int x) {
    no* novo = (no*)malloc(sizeof(no));
    novo->x = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

no* insere(no* raiz, int x) {
    if (raiz == NULL) {
        return cria_no(x);
    }
    
    if (x < raiz->x) {
        raiz->esq = insere(raiz->esq, x);
    } else {
        raiz->dir = insere(raiz->dir, x);
    }
    
    return raiz;
}

void percorre_nivel(no* raiz) {
    if (raiz == NULL) return;
    
    cel* ff = cria_fila();
    
    push(ff, raiz);
    
    int primeiro = 1;
    
    while (!fila_vazia(ff)) {
        no* atual = remove_fila(ff);
        
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->x);
        primeiro = 0;
        
        if (atual->esq != NULL) {
            push(ff, atual->esq);
        }
        if (atual->dir != NULL) {
            push(ff, atual->dir);
        }
    }
    
    while (!fila_vazia(ff)) {
        remove_fila(ff);
    }
    free(ff);
}

void libera_arvore(no* raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->esq);
        libera_arvore(raiz->dir);
        free(raiz);
    }
}