#include <stdio.h>
#include <stdlib.h>

long long merge_sort(int, int, int[]);
long long intercala(int, int, int, int[]);

int main() {
    int n, *v;
    long long inversoes;
    
    while (1) {
        if (scanf("%d", &n) != 1) {
            break;
        }
        
        if (n == 0) {
            break;
        }
        
        v = (int *) malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            if (scanf("%d", &v[i]) != 1) {
                free(v);
                return 1;
            }
        }
        
        long long inversoes = merge_sort(0, n, v);
        
        if (inversoes % 2 == 1) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }

        free(v);
    }
    
    return 0;
}

long long merge_sort(int p, int r, int v[]) {
    long long inv_count = 0;
    if (p < r - 1) {
        int q = (p + r)/2;
        inv_count += merge_sort(p, q, v);
        inv_count += merge_sort(q, r, v);
        inv_count += intercala(p, q, r, v);
    }
    return inv_count;
}

long long intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;
    long long inv_count = 0;
    
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
            inv_count += (q - i);
        }
    }
    
    while (i < q) {
        w[k++] = v[i++];
    }
    
    while (j < r) {
        w[k++] = v[j++];
    }
    
    for (i = p; i < r; i++) {
        v[i] = w[i-p];
    }
    
    free(w);
    return inv_count;
}