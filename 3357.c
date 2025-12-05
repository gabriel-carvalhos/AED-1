#include <stdio.h>
#include <string.h>

int main() {
    int n;
    float l, q;
    char nomes[10][13];
    
    scanf("%d", &n);
    scanf("%f", &l);
    scanf("%f", &q);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", nomes[i]);
    }
    
    int completas = (int) (l / q);

    float resto = l - (completas * q);

    int ultima_pessoa = completas % n;
    
    if (resto > 0) {
        printf("%s %.1f\n", nomes[ultima_pessoa], resto);
    } else {
        int pessoa_anterior = (ultima_pessoa - 1 + n) % n;
        printf("%s %.1f\n", nomes[pessoa_anterior], q);
    }
}