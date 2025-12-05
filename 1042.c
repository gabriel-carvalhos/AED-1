#include <stdio.h>
#include <stdlib.h>

void selection_sort(int, int[]);

int main() {
    int v[3], ordenado[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &v[i]);
        ordenado[i] = v[i];
    }

    selection_sort(3, ordenado);

    for (int i = 0; i < 3; i++){
        printf("%d\n", ordenado[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++){
        printf("%d\n", v[i]);
    }
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