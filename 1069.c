#include <stdio.h>
#include <string.h>

int pop(char[1000], int);
int push(char[1000], int);

int main() {
    int n;
    char str[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int achados = 0, t = 0;
        char pilha[1000];

        scanf("%1000s", str);

        for (int j = 0; j < strlen(str); j++) {
            if (str[j] == '<') {
                t = push(pilha, t);
            } else if (str[j] == '>') {
                if (t > 0) {
                    t = pop(pilha, t);
                    achados++;
                }
            }
        }

        printf("%d\n", achados);
    }
}

int pop(char pilha[1000], int t) {
    t -= 1;
    char x = pilha[t];
    return t;
}

int push(char pilha[1000], int t) {
    pilha[t] = '(';
    t += 1;
    return t;
}