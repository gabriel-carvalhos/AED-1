#include <stdio.h>
#include <stdlib.h>

int separa(int, int, int[]);
void quick_sort(int, int, int[]);

int main() {
    int nc, n, *h;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        h = (int *) malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        
        quick_sort(0, n - 1, h);

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
