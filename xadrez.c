#include <stdio.h>
#include <stdlib.h>

// Imprimindo o Tabuleiro 8x8
void imprimirTabuleiro(char tabuleiro[8][8]);

int main() {
    // Declaração do tabuleiro 8x8
    char tabuleiro[8][8];
    int i, j;
    
    // Preenche o tabuleiro com casas vazias
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
    
    // Posiciona as peças nas suas casas iniciais (lado preto do tabuleiro)
    tabuleiro[0][0] = 'T'; // Torre
    tabuleiro[0][2] = 'B'; // Bispo
    tabuleiro[0][3] = 'Q'; // Rainha

    printf("--- Tabuleiro Inicial ---\n");
    imprimirTabuleiro(tabuleiro);
    
    // Movimentacao da Torre: 5 casas para a direita usando 'for'
    printf("\n>>> Movimentando a Torre 5 casas para a direita...\n");
    int linhaTorre = 0, colunaTorre = 0;
    
    for (int passo = 1; passo <= 5 && colunaTorre < 7; passo++) {
        tabuleiro[linhaTorre][colunaTorre] = ' '; // Limpa a posicao antiga
        colunaTorre++; // Move uma casa para a direita
        
        tabuleiro[linhaTorre][colunaTorre] = 'T';
        printf(" Passo %d: Torre se move para a posicao %c%d\n", passo, 'a' + colunaTorre, 8 - linhaTorre);
    }
    
    printf("\n--- Tabuleiro apos o movimento da Torre ---\n");
    imprimirTabuleiro(tabuleiro);

    // Movimentacao do Bispo: 5 casas na diagonal (para cima e a direita) usando 'do-while'
    printf("\n>>> Movimentando o Bispo 5 casas na diagonal (para cima e a direita)...\n");
    int linhaBispo = 0, colunaBispo = 2;
    int passosBispo = 5;

    do {
        tabuleiro[linhaBispo][colunaBispo] = ' '; // Limpa a posicao antiga
        linhaBispo++; // Move uma casa para baixo
        colunaBispo++; // Move uma casa para a direita
        
        if (linhaBispo < 8 && colunaBispo < 8) {
            tabuleiro[linhaBispo][colunaBispo] = 'B';
            printf(" Passo %d: Bispo se move para a posicao %c%d (cima, direita)\n", 6 - passosBispo, 'a' + colunaBispo, 8 - linhaBispo);
        } else {
            // Para o movimento se o proximo passo sair do tabuleiro
            linhaBispo--;
            colunaBispo--;
            tabuleiro[linhaBispo][colunaBispo] = 'B';
            break;
        }
        
        passosBispo--;
    } while (passosBispo > 0);

    printf("\n--- Tabuleiro apos o movimento do Bispo ---\n");
    imprimirTabuleiro(tabuleiro);
    
    // Movimentacao da Rainha: 6 casas para a esquerda usando 'while'
    printf("\n>>> Movimentando a Rainha 6 casas para a esquerda...\n");
    int linhaRainha = 0, colunaRainha = 3;
    int passosRainha = 6;
    
    while (passosRainha > 0 && colunaRainha > 0) {
        tabuleiro[linhaRainha][colunaRainha] = ' '; // Limpa a posicao antiga
        colunaRainha--; // Move uma casa para a esquerda
        
        tabuleiro[linhaRainha][colunaRainha] = 'Q';
        printf(" Passo %d: Rainha se move para a posicao %c%d\n", 7 - passosRainha, 'a' + colunaRainha, 8 - linhaRainha);
        
        passosRainha--;
    }
    
    printf("\n--- Tabuleiro Final ---\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

/**
 * @brief Imprime o tabuleiro na tela.
 * @param tabuleiro O array 2D que representa o tabuleiro.
 */
void imprimirTabuleiro(char tabuleiro[8][8]) {
    int i, j;
    
    printf(" ----------------------------------\n");
    
    for (i = 0; i < 8; i++) {
        printf("%d |", 8 - i);
        for (j = 0; j < 8; j++) {
            printf(" %c |", tabuleiro[i][j]);
        }
        printf("\n");
        printf(" ----------------------------------\n");
    }
    
    printf("  --a---b---c---d---e---f---g---h--\n");
}
