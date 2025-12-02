#include <stdio.h>
#include <stdlib.h>

int main() {
    int v, t;
    while (scanf("%d %d", &v, &t) != EOF) {
        printf("%d\n", v * (t * 2));
    }
}