// nao finalizado

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int, int, int[]);
int separa(int, int, int[]);
int comparar(int, int);

int m;

int main() {
    int n, *numeros;
    
    while (1) {
        if (scanf("%d %d", &n, &m) != 2) {
            break;
        }
        
        if (n == 0 && m == 0) {
            printf("0 0\n");
            break;
        }
        
        printf("%d %d\n", n, m);
        
        numeros = (int *) malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &numeros[i]) != 1) {
                free(numeros);
                return 1;
            }
        }
        
        if (n > 0) {
            quick_sort(0, n - 1, numeros);
        }
        
        for (int i = 0; i < n; i++) {
            printf("%d\n", numeros[i]);
        }
        
        free(numeros);
    }
    
    return 0;
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
        if (comparar(v[k], c) <= 0) {
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

int comparar(int a, int b) {
    int mod_a = a % m;
    int mod_b = b % m;
    
    if (mod_a < 0) mod_a += m;
    if (mod_b < 0) mod_b += m;
    
    if (mod_a < mod_b) return -1;
    if (mod_a > mod_b) return 1;

    int a_par = (a % 2 == 0);
    int b_par = (b % 2 == 0);
    
    if (a_par != b_par) {
        return !a_par; 

        if (!a_par && b_par) return -1;
        if (a_par && !b_par) return 1;
    }
    
    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
}