#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct cel {
    char x[100001];
    struct cel *seg;
} cel;

int insere(char[], cel *, int);

int main() {
    int c = 0;
    char joia[100001];

    cel *joias = malloc(sizeof(cel));
    joias->seg = NULL;

    while (scanf("%s", joia) != EOF) {
        c = insere(joia, joias, c);
    }

    printf("%d\n", c);
    
    cel *atual = joias->seg;
    while (atual != NULL) {
        cel *temp = atual;
        atual = atual->seg;
        free(temp);
    }
    free(joias);
    
    return 0;
}

int insere(char joia[], cel *lst, int c) {
    cel *anterior = lst;
    cel *atual = lst->seg;

    cel *nova = malloc(sizeof(cel));
    strcpy(nova->x, joia);

    while (atual != NULL && strcmp(atual->x, joia) != 0) {
        anterior = atual;
        atual = atual->seg;
    }
    
    if (atual != NULL) {
        free(nova);
        return c;
    }

    nova->seg = atual;
    anterior->seg = nova;
    return c + 1;
}
