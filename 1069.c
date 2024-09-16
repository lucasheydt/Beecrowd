#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char entrada[1001];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", entrada);
        
        int diamantes = 0;
        char fila[1000];
        int frente = 0, fim = 0;

        for (int j = 0; j < strlen(entrada); j++) {
            if (entrada[j] == '<') {
                fila[fim++] = '<';
            } else if (entrada[j] == '>') {
                if (fim > frente) {
                    diamantes++;
                    frente++;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
