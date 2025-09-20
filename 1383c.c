#include <stdio.h>
#include <stdlib.h>

int** criarMatriz(int, int);
void liberarMatriz(int**, int);
int verificarLinha(int**, int);
int verificarColuna(int**, int);
int verificarRegiao(int**, int);

int main() {
    int *n = (int *) malloc(sizeof(int));
    int *valido = (int *) malloc(sizeof(int));
    int **m;
    int *k = (int *) malloc(sizeof(int));
    int *i = (int *) malloc(sizeof(int));
    int *j = (int *) malloc(sizeof(int));

    scanf("%d", n);
    
    for (*k = 0; *k < *n; (*k)++) {
        m = criarMatriz(9, 9);
        
        for (*i = 0; *i < 9; (*i)++) {
            for (*j = 0; *j < 9; (*j)++) {
                scanf("%d", *(m + *i) + *j);
            }
        }

        printf("Instancia %d\n", *k + 1);
    
        *valido = 1;
        for (*i = 0; *i < 9; (*i)++) {
            if (!verificarLinha(m, *i) || !verificarColuna(m, *i) || !verificarRegiao(m, *i)) {
                *valido = 0;
                break;
            }
        }

        if (*valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n"); 
        }
        
        liberarMatriz(m, 9);
    }

    free(n);
    free(valido);
    free(k);
    free(i);
    free(j);

    return 0;
}

int** criarMatriz(int linhas, int colunas) {
    int** matriz = (int **) malloc(linhas * sizeof(int*));
    int *i = (int *) malloc(sizeof(int));

    for (*i = 0; *i < linhas; (*i)++) {
        *(matriz + *i) = (int*) malloc(colunas * sizeof(int));
    }
    
    free(i);
    return matriz;
}

void liberarMatriz(int** matriz, int linhas) {
    int *i = (int *) malloc(sizeof(int));
    
    for (*i = 0; *i < linhas; (*i)++) {
        free(*(matriz + *i));
    }

    free(matriz);
    free(i);
}

int verificarLinha(int** m, int i) {
    int* vistos = (int *) calloc(10, sizeof(int));
    int *j = (int *) malloc(sizeof(int));

    for (*j = 0; *j < 9; (*j)++) {
        int valor = *(*(m + i) + *j);
        if (*(vistos + valor) != 0) {
            free(vistos);
            free(j);
            return 0;
        }
        *(vistos + valor) = 1;
    }

    free(vistos);
    free(j);
    return 1;
}

int verificarColuna(int** m, int j) {
    int* vistos = (int *) calloc(10, sizeof(int));
    int *i = (int *) malloc(sizeof(int));

    for (*i = 0; *i < 9; (*i)++) {
        int valor = *(*(m + *i) + j);
        if (*(vistos + valor) != 0) {
            free(vistos);
            free(i);
            return 0;
        }
        *(vistos + valor) = 1;
    }

    free(vistos);
    free(i);
    return 1;
}

int verificarRegiao(int** m, int r) {
    int* vistos = (int *) calloc(10, sizeof(int));
    int *i = (int *) malloc(sizeof(int));
    int *j = (int *) malloc(sizeof(int));
    int linha_inicial = (r / 3) * 3;
    int coluna_inicial = (r % 3) * 3;

    for (*i = (r / 3) * 3; *i <= (r / 3) * 3 + 2; (*i)++) {
        for (*j = (r % 3) * 3; *j <= (r % 3) * 3 + 2; (*j)++) {
            int valor = *(*(m + *i) + *j);
            if (*(vistos + valor) != 0) {
                free(vistos);
                free(i);
                free(j);
                return 0;
            }
            *(vistos + valor) = 1;
        }
    }

    free(vistos);
    free(i);
    free(j);
    return 1;
}