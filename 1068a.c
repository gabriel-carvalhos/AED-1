#include <stdio.h>
#include <string.h>

int pop(char[1000], int);
int push(char[1000], int);

int main() {
    char exp[1001];

    while(scanf("%1000s", exp) != EOF){
        char pilha[1000];
        int t = 0, valido = 1;

        for (int i = 0; i < strlen(exp); i++) {
            if (exp[i] == '(') {
                t = push(pilha, t);
            } else if (exp[i] == ')') {
                if (t > 0) {
                    t = pop(pilha, t);
                    continue;
                }

                valido = 0;
                break;
            }
        }
    
        if (t == 0 && valido == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
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