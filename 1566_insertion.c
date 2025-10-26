#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int, int[]);

int main() {
    int nc, n, *h;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        h = (int *) malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        
        insertion_sort(n, h);

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

void insertion_sort(int n, int v[]) {
    int i, j, x;

    for (j = 1; j < n; j++) {
        x = v[j];
    
        for (i = j - 1; i >= 0 && v[i] > v[j]; i--) {
            v[i + 1] = v[i];  
        }

        v[i + 1] = x;
    }
}