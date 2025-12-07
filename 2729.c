#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cel {
    char palavra[21];
    struct cel *prox;
} cel;

typedef struct {
    cel *cabeca;
    int tamanho;
} lista;

cel* criar_no(const char *);
void inicializar_lista(lista *);
int palavra_existe(lista *, const char *);
void inserir_ordenado(lista *, const char *);
void imprimir_lista(lista *);
void liberar_lista(lista *);
void processar_lista_compras(const char *);

int main() {
    int n;
    char linha[20001];

    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    getchar();
    
    for (int i = 0; i < n; i++) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }
    
        linha[strcspn(linha, "\n")] = '\0';
    
        processar_lista_compras(linha);
    }
}

cel* criar_no(const char *palavra) {
    cel *novo = (cel*)malloc(sizeof(cel));
    
    strcpy(novo->palavra, palavra);
    novo->prox = NULL;
    return novo;
}

void inicializar_lista(lista *lista) {
    lista->cabeca = criar_no("");
    lista->cabeca->prox = NULL;
    lista->tamanho = 0;
}

int palavra_existe(lista *lista, const char *palavra) {
    cel *atual = lista->cabeca->prox;
    
    while (atual != NULL) {
        if (strcmp(atual->palavra, palavra) == 0) {
            return 1;
        }
        atual = atual->prox;
    }
    
    return 0;
}

void inserir_ordenado(lista *lista, const char *palavra) {
    if (palavra_existe(lista, palavra)) {
        return;
    }
    
    cel *novo = criar_no(palavra);
    cel *atual = lista->cabeca;
    
    while (atual->prox != NULL && strcmp(atual->prox->palavra, palavra) < 0) {
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
    lista->tamanho++;
}

void imprimir_lista(lista *lista) {
    cel *atual = lista->cabeca->prox;
    int primeiro = 1;
    
    while (atual != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%s", atual->palavra);
        atual = atual->prox;
        primeiro = 0;
    }
    printf("\n");
}

void liberar_lista(lista *lista) {
    cel *atual = lista->cabeca;
    
    while (atual != NULL) {
        cel *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

void processar_lista_compras(const char *linha) {
    lista lista;
    inicializar_lista(&lista);
    
    char palavra[21];
    int i = 0, j = 0;
    
    while (linha[i] != '\0') {
        if (linha[i] == ' ' || linha[i] == '\n') {
            if (j > 0) {
                palavra[j] = '\0';
                inserir_ordenado(&lista, palavra);
                j = 0;
            }
        } else {
            if (j < 20) {
                palavra[j] = linha[i];
                j++;
            }
        }
        i++;
    }
    
    if (j > 0) {
        palavra[j] = '\0';
        inserir_ordenado(&lista, palavra);
    }
    
    imprimir_lista(&lista);
    
    liberar_lista(&lista);
}