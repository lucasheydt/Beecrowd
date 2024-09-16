#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int sudoku[9][9];
        int valido = 1;

        // Leitura do Sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // Verificação de linhas e colunas
        for (int i = 0; i < 9 && valido; i++) {
            int numeros_linha[10] = {0};
            int numeros_coluna[10] = {0};

            for (int j = 0; j < 9; j++) {
                int num_linha = sudoku[i][j];
                int num_coluna = sudoku[j][i];

                if (numeros_linha[num_linha] != 0 || numeros_coluna[num_coluna] != 0) {
                    valido = 0;
                    break;
                }

                numeros_linha[num_linha] = 1;
                numeros_coluna[num_coluna] = 1;
            }
        }

        // Verificação de submatrizes 3x3
        for (int i = 0; i < 9 && valido; i += 3) {
            for (int j = 0; j < 9 && valido; j += 3) {
                int numeros[10] = {0};

                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int num = sudoku[i + x][j + y];

                        if (numeros[num] != 0) {
                            valido = 0;
                            break;
                        }

                        numeros[num] = 1;
                    }
                }
            }
        }

        // Impressão dos resultados
        printf("Instancia %d\n", instancia);
        if (valido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        
    }

    return 0;
}
