#include <stdio.h>
#include <stdlib.h>

void heap_sort(int, int[]);
void insereHeap(int, int[]);
void sacodeHeap(int, int[]);

int main() {
    int nc, n, *h;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        h = (int *) malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        
        heap_sort(n, h);

        for (int j = 0; j < n; j++) {
            printf("%d ", h[j]);
        }
        printf("\n");

        free(h);
    }
    
    return 0;
}

void heap_sort(int n, int v[]) {
    int m;

    for (m = 1; m < n; m++) {
        insereHeap(m, v);
    }

    for (m = n; m > 1; m--) {
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        sacodeHeap(m - 1, v);
    }
}

void insereHeap(int m, int v[]) {
    int f = m + 1;

    while (f > 1 && v[f/2] < v[f]) {
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}

void sacodeHeap(int m, int v[]) {
    int t, f = 2;
    while (f <= m) {
        if (f < m && v[f] < v[f+1]) {
            ++f;
        }

        if (v[f/2] >= v[f]) {
            break;
        }

        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}