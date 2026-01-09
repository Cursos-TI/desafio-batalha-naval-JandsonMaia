#include <stdio.h>
#include <stdlib.h>


int main() {

    int tabuleiro[10][10];
    int i, j;

    // ================= TABULEIRO BASE =================
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // ================= MATRIZES DE HABILIDADE =================
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // ===== Cone (apontado para baixo) =====
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i <= 2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // ===== Cruz =====
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // ===== Octaedro (losango) =====
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ================= SOBREPOR HABILIDADES =================
    int origemConeL = 5, origemConeC = 2;
    int origemCruzL = 7, origemCruzC = 7;
    int origemOctL  = 3, origemOctC  = 5;

    // Função inline de sobreposição (manual)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {

            int l, c;

            // Cone
            l = origemConeL + i - 2;
            c = origemConeC + j - 2;
            if (cone[i][j] == 1 && l >= 0 && l < 10 && c >= 0 && c < 10) {
                if (tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }

            // Cruz
            l = origemCruzL + i - 2;
            c = origemCruzC + j - 2;
            if (cruz[i][j] == 1 && l >= 0 && l < 10 && c >= 0 && c < 10) {
                if (tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }

            // Octaedro
            l = origemOctL + i - 2;
            c = origemOctC + j - 2;
            if (octaedro[i][j] == 1 && l >= 0 && l < 10 && c >= 0 && c < 10) {
                if (tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }

    // ================= EXIBIÇÃO =================
    printf("Tabuleiro com Habilidades\n\n");
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
