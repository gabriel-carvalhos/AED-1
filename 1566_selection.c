#include <stdio.h>
#include <stdlib.h>

void selection_sort(int, int[]);

int main() {
    int nc, n, *h;

    scanf("%d", &nc);

    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        h = (int *) malloc(sizeof(int) * n);
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &h[j]);
        }
        
        selection_sort(n, h);

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

void selection_sort(int n, int v[]) {
    int min, temp;

    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }

        temp = v[min];
        v[min] = v[i];
        v[i] = temp;
    }
}