#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    int dado;
    struct cel* proximo;
} cel;

typedef struct  {
    cel** listas;
    int capacidade;
} vetor_listas;

cel* criar_no(int);
vetor_listas* criar_vetor_listas(int);
void inserir_na_lista(vetor_listas*, int, int);
void liberar_vetor_listas(vetor_listas*);
void imprimir_todas_listas(vetor_listas*);

int main() {
    int n, m, c, x;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);
        vetor_listas* v = criar_vetor_listas(m);

        for (int j = 0; j < c; j++) {
            scanf("%d", &x);
            inserir_na_lista(v, x % m, x);
        }

        imprimir_todas_listas(v);
        
        if (i < n - 1) {
            printf("\n");
        }
        
        liberar_vetor_listas(v);
    }
    
    return 0;
}

cel* criar_no(int valor) {
    cel* novo = (cel*)malloc(sizeof(cel));
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

vetor_listas* criar_vetor_listas(int capacidade) {
    vetor_listas* vetor = (vetor_listas*)malloc(sizeof(vetor_listas));
    vetor->capacidade = capacidade;
    
    // aloca o vetor de ponteiros
    vetor->listas = (cel**)calloc(capacidade, sizeof(cel*));
    
    return vetor;
}

void inserir_na_lista(vetor_listas* vetor, int indice, int valor) {   
    cel* novo = criar_no(valor);
    
    // se a lista está vazia
    if (vetor->listas[indice] == NULL) {
        vetor->listas[indice] = novo;
    } else {
        // encontra o último nó
        cel* atual = vetor->listas[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void imprimir_todas_listas(vetor_listas* vetor) {
    for (int i = 0; i < vetor->capacidade; i++) {
        printf("%d -> ", i);
        cel* atual = vetor->listas[i];
        
        while (atual != NULL) {
            printf("%d -> ", atual->dado);
            atual = atual->proximo;
        }
        printf("\\\n");
    }
}

void liberar_vetor_listas(vetor_listas* vetor) {
    for (int i = 0; i < vetor->capacidade; i++) {
        cel* atual = vetor->listas[i];
        while (atual != NULL) {
            cel* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(vetor->listas);
    free(vetor);
}