#include <stdio.h>
#include <stdlib.h>

void selection_sort(int, int[]);

int main() {
    int n, m, sem_troca, *v, *v_ordenado;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        sem_troca = 0;
        scanf("%d", &m);
        v = malloc(sizeof(int) * m);
        v_ordenado = malloc(sizeof(int) * m);

        for (int j = 0; j < m; j++) {
            scanf("%d", &v[j]);
            v_ordenado[j] = v[j];
        }

        selection_sort(m, v_ordenado);

        for(int j = 0; j < m; j++) {
            if (v_ordenado[j] == v[j]) {
                sem_troca++;
            }
        }
        
        printf("%d\n", sem_troca);
        free(v);
    }
    
    return 0;
}

void selection_sort(int n, int v[]) {
    int max, temp;

    for (int i = 0; i < n - 1; i++) {
        max = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[max]) {
                max = j;
            }
        }

        temp = v[max];
        v[max] = v[i];
        v[i] = temp;
    }
}