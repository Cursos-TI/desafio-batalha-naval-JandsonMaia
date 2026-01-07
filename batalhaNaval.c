#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ===== Navio 1 - Horizontal =====
    int linha1 = 1, coluna1 = 2;
    for (i = 0; i < 3; i++) {
        if (coluna1 + i < 10 && tabuleiro[linha1][coluna1 + i] == 0) {
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    }

    // ===== Navio 2 - Vertical =====
    int linha2 = 4, coluna2 = 6;
    for (i = 0; i < 3; i++) {
        if (linha2 + i < 10 && tabuleiro[linha2 + i][coluna2] == 0) {
            tabuleiro[linha2 + i][coluna2] = 3;
        }
    }

    // ===== Navio 3 - Diagonal principal (\) =====
    int linha3 = 0, coluna3 = 0;
    for (i = 0; i < 3; i++) {
        if (linha3 + i < 10 && coluna3 + i < 10 &&
            tabuleiro[linha3 + i][coluna3 + i] == 0) {
            tabuleiro[linha3 + i][coluna3 + i] = 3;
        }
    }

    // ===== Navio 4 - Diagonal secundária (/) =====
    int linha4 = 0, coluna4 = 9;
    for (i = 0; i < 3; i++) {
        if (linha4 + i < 10 && coluna4 - i >= 0 &&
            tabuleiro[linha4 + i][coluna4 - i] == 0) {
            tabuleiro[linha4 + i][coluna4 - i] = 3;
        }
    }

    /// ===== EXIBE O TABULEIRO =====
    printf("Tabuleiro Batalha Naval\n\n");

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
