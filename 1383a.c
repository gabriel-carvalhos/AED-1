#include <stdio.h>

int verificarLinha(int m[][9], int);
int verificarColuna(int m[][9], int);
int verificarRegiao(int m[][9], int);

int main() {
    int m[9][9];
    int n, valido;

    scanf("%d", &n);
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &m[i][j]);
            }
        }

        printf("Instancia %d\n", k + 1);
    
        valido = 1;
        for (int i = 0; i < 9; i++) {
            if (!verificarLinha(m, i) || !verificarColuna(m, i) || !verificarRegiao(m, i)) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n"); 
        }
    }

    return 0;
}

int verificarLinha(int m[][9], int i) {
    int vistos[10] = {0};

    for (int j = 0; j < 9; j++) {
        if (vistos[m[i][j]] != 0) {
            return 0;
        }

        vistos[m[i][j]] = 1;
    }

    return 1;
}

int verificarColuna(int m[][9], int j) {
    int vistos[10] = {0};

    for (int i = 0; i < 9; i++) {
        if (vistos[m[i][j]] != 0) {
            return 0;
        }

        vistos[m[i][j]] = 1;
    }

    return 1;
}

int verificarRegiao(int m[][9], int r) {
    int vistos[10] = {0};
    int linha_inicial = (r / 3) * 3;
    int coluna_inicial = (r % 3) * 3;

    for (int i = linha_inicial; i <= linha_inicial + 2; i++) {
        for (int j = coluna_inicial; j <= coluna_inicial + 2; j++) {
            if (vistos[m[i][j]] != 0) {
                return 0;
            }

            vistos[m[i][j]] = 1;
        }
    }

    return 1;
}