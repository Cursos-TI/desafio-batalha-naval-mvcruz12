#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

// Função para aplicar uma forma geométrica no tabuleiro
void aplicarForma(int tabuleiro[TAM][TAM], int forma[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + (i - offset);
            int coluna = origemColuna + (j - offset);

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (forma[i][j] == 5) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // FORMAS GEOMÉTRICAS 
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Cone (3 linhas, triângulo invertido)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(j - 2) <= i) {
                cone[i][j] = 5;
            }
        }
    }

    // Cruz (3 linhas: 0, 1, 2)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 1 || j == 2) {
                cruz[i][j] = 5;
            }
        }
    }

    // Octaedro (3 linhas: 0, 1, 2)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 1) + abs(j - 2) <= 1) {
                octaedro[i][j] = 5;
            }
        }
    }

    // Posicionando as formas no tabuleiro 
    aplicarForma(tabuleiro, cone, 2, 2);        // Cone no topo
    aplicarForma(tabuleiro, cruz, 5, 5);        // Cruz no centro
    aplicarForma(tabuleiro, octaedro, 8, 8);    // Octaedro abaixo

    // Tamanho do tabuleiro e dos navios
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
   

    // Navios (valor 3 representa parte do navio)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaNavioHorizontal = 1; // linha 2
    int colunaNavioHorizontal = 7; // coluna H

    int linhaNavioVertical = 3; // linha 5
    int colunaNavioVertical = 9; // coluna J

    int linhaNavioDiagonal1 = 6; // linha 6
    int colunaNavioDiagonal1 = 0; // coluna A

    int linhaNavioDiagonal2 = 8; // linha 2
    int colunaNavioDiagonal2 = 4; // coluna E

    // Variável de controle para laços e verificação de sobreposição

    int i;
    int sobreposicao = 0;

    // Posiciona navio horizontal
    if (colunaNavioHorizontal + tamanhoNavio <= tamanhoTabuleiro) 
    {
        for (i = 0; i < tamanhoNavio; i++) 
        {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != 0) 
            {
                sobreposicao = 1;  // Se estiver ocupada, marca sobreposição
                break;
            }
        }
        if (sobreposicao == 0) 
        {
            for (i = 0; i < tamanhoNavio; i++) 
            {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = navioHorizontal[i];
            }
        }
    }

    // Reinicia a verificação de sobreposição
    sobreposicao = 0;

    // Posiciona navio vertical
    if (linhaNavioVertical + tamanhoNavio <= tamanhoTabuleiro) 
    {
        for (i = 0; i < tamanhoNavio; i++) 
        {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0) 
            {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao  == 0) 
        {
            for (i = 0; i < tamanhoNavio; i++) 
            {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = navioVertical[i];
            }
        }
    }

    // Posiciona o navio diagonal 1

    if (linhaNavioDiagonal1 + tamanhoNavio <= tamanhoTabuleiro &&
        colunaNavioDiagonal1 + tamanhoNavio <= tamanhoTabuleiro) 
    {
        sobreposicao = 0;
    
        // Verifica sobreposição apenas nas posições da diagonal
        for (int i = 0; i < tamanhoNavio; i++) 
        {
            if (tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] != 0) 
            {
                sobreposicao = 1;
                break;
            }
        }
    
        // Se não há sobreposição, posiciona o navio na diagonal
        if (sobreposicao == 0) 
        {
            for (int i = 0; i < tamanhoNavio; i++) 
            {
                tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = navioDiagonal1[i];
            }
        }
    }

    // Posiciona o navio diagonal 2

    if (linhaNavioDiagonal2 - (tamanhoNavio - 1) >= 0 &&
    colunaNavioDiagonal2 + tamanhoNavio <= tamanhoTabuleiro) 
    {
        sobreposicao = 0;
    
        // Verifica sobreposição apenas nas posições da diagonal
        for (int i = 0; i < tamanhoNavio; i++) 
        {
            if (tabuleiro[linhaNavioDiagonal2 - i][colunaNavioDiagonal2 + i] != 0) 
            {
                sobreposicao = 1;
                break;
            }
        }
    
        // Se não há sobreposição, posiciona o navio na diagonal
        if (sobreposicao == 0) 
        {
            for (int i = 0; i < tamanhoNavio; i++) 
            {
                tabuleiro[linhaNavioDiagonal2 - i][colunaNavioDiagonal2 + i] = navioDiagonal2[i];
            }
        }
    }

    // === Imprime o tabuleiro ===
    printf("\nTabuleiro com formas geométricas (cone, cruz, octaedro):\n\n");

    printf("    ");
    for (int coluna = 0; coluna < TAM; coluna++) {
        printf(" %c", 'A' + coluna);
    }
    printf("\n");

    for (int linha = 0; linha < TAM; linha++) {
        printf(" %2d ", linha);
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}