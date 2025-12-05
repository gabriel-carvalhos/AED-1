#include <stdio.h>
#include <stdlib.h>

int separa(int, int, int[]);
void quick_sort(int, int, int[]);

int main() {
    int n, x, pares[100000], impares[100000];
    int par, impar;
    par = impar = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares[par] = x;
            par++;
        } else {
            impares[impar] = x;
            impar++;
        }
    }

    quick_sort(0, par - 1, pares);
    quick_sort(0, impar - 1, impares);

    for (int i = 0; i < par; i++){
        printf("%d\n", pares[i]);
    }
    for (int i = impar - 1; i >= 0; i--){
        printf("%d\n", impares[i]);
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
