#include <stdio.h>
#include <stdlib.h>

void intercala(int, int, int, int[]);
void merge_sort(int, int, int[]);

int main() {
    int nc, n, *h;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        h = (int *) malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        
        merge_sort(0, n, h);

        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", h[j]);
        }
        printf("\n");

        free(h);
    }
    
    return 0;
}

void merge_sort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        merge_sort(p, q, v);
        merge_sort(q, r, v);
        intercala(p, q, r, v);
    }
}

void intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r - p) * sizeof (int));
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
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
}
