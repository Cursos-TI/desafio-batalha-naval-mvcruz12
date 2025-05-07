#include <stdio.h>

int main() {
    // Tamanho do tabuleiro e dos navios
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;

    // Matriz do tabuleiro inicializada com 0 (água)
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Navios (valor 3 representa parte do navio)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaNavioHorizontal = 2; // linha 2
    int colunaNavioHorizontal = 4; // coluna E

    int linhaNavioVertical = 5; // linha 5
    int colunaNavioVertical = 7; // coluna H

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

    // Imprime o cabeçalho das colunas (letras de A a J)

    printf("    ");

    for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) 
    {
        printf(" %c", 'A' + coluna);
    }
    printf("\n");

    // Linhas numeradas (0 a 9)
    
    for (int linha = 0; linha < tamanhoTabuleiro; linha++) 
    {
        printf(" %d  ", linha);
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) 
        {
            printf(" %d", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}