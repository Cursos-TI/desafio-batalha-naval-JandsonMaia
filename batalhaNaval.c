#include <stdio.h>

int main(){
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[10][10];
    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical
    
    int i, j;

    //Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
    //Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 5, coluna2 = 7; // navio vertical

    //Posiciona o navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linha1][coluna1 + i] = navio1[i];

    //Posiciona o navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    //Imprime o tabuleiro
    printf("Tabuleiro Batalha Naval\n\n");

    //(A até J)
    printf("   ");
    for (j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    //(1 até 10)
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
    return 0;
}
