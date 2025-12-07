#include <stdio.h>
#include <stdlib.h>

void quick_sort(int p, int r, int v[]);
int separa(int p, int r, int v[]);
int busca_primeira_ocorrencia(int[], int, int);

int main() {
    int n, q, *marmores;
    int caso = 1;
    
    while (1) {
        scanf("%d %d", &n, &q);
        
        if (n == 0 && q == 0) {
            break;
        }
        
        marmores = (int *) malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &marmores[i]);
        }
        
        if (n > 0) {
            quick_sort(0, n - 1, marmores);
        }
        
        printf("CASE# %d:\n", caso++);

        for (int i = 0; i < q; i++) {
            int consulta;
            scanf("%d", &consulta);
            
            int posicao = busca_primeira_ocorrencia(marmores, n, consulta);
            
            if (posicao == -1) {
                printf("%d not found\n", consulta);
            } else {
                printf("%d found at %d\n", consulta, posicao + 1);
            }
        }
        
        free(marmores);
    }
}

void quick_sort(int p, int r, int v[]) {
    int j;
    while (p < r) {
        j = separa(p, r, v);
        if (j - p < r - j) {
            quick_sort(p, j - 1, v);
            p = j + 1;
        } else {
            quick_sort(j + 1, r, v);
            r = j - 1;
        }
    }
}

int separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;
    
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    
    v[r] = v[j];
    v[j] = c;
    
    return j;
}

int busca_primeira_ocorrencia(int arr[], int n, int x) {
    int esq = 0, dir = n - 1;
    int resultado = -1;
    
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (arr[meio] == x) {
            resultado = meio;
            dir = meio - 1;
        } else if (arr[meio] < x) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    
    return resultado;
}