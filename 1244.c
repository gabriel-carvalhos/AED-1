#include <stdio.h>
#include <string.h>

void sort(char palavras[][51], int);

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char palavras[50][51];
        int qtd = 0;
        
        while (1) {
            if (scanf("%s", palavras[qtd]) == 1) {
                qtd++;
            }
            
            char c = getchar();
            if (c == '\n' || c == EOF) break;
        }
        
        sort(palavras, qtd);
        
        for (int i = 0; i < qtd; i++) {
            printf("%s", palavras[i]);
            if (i < qtd - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}

void sort(char palavras[][51], int qtd) {
    char temp[51];
    
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            int tam1 = strlen(palavras[j]);
            int tam2 = strlen(palavras[j + 1]);
            
            if (tam1 < tam2) {
                strcpy(temp, palavras[j]);
                strcpy(palavras[j], palavras[j + 1]);
                strcpy(palavras[j + 1], temp);
            }
        }
    }
}