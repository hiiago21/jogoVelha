#include "lib/utilidades.h"

int confereTabuleiro(char tabuleiro[3][3]){

        int linha, coluna;

        //return = 1, X ganhou
        //return = 2, O ganhou
        // returna = 0, segue o jogo

        // ganha com linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X'
               && tabuleiro[linha][0] == tabuleiro[linha][1]
               && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }
            else if(tabuleiro[linha][0] == 'O'
                    && tabuleiro[linha][0] == tabuleiro[linha][1]
                    && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //ganha com colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X'
               && tabuleiro[0][coluna] == tabuleiro[1][coluna]
               && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O'
                     && tabuleiro[0][coluna] == tabuleiro[1][coluna]
                     && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //ganha com diagonal
        if(tabuleiro[0][0] != '-'
           && tabuleiro[0][0] == tabuleiro[1][1]
           && tabuleiro[1][1] == tabuleiro[2][2]){

            if(tabuleiro[0][0] == 'X'){
               return 1;
            }else{
               return 2;
            }
        }

        //ganha com diagonal contaria
        if(tabuleiro[0][2] != '-'
           && tabuleiro[0][2] == tabuleiro[1][1]
           && tabuleiro[1][1] == tabuleiro[2][0]){

            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
               return 2;
            }
        }

        return 0;
}

//for para criar uma matriz e preenchendo ela de '-', para poder efetuar um teste de posição vazia ou não
void criaTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;
    for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<3; coluna++){
            tabuleiro[linha][coluna]= '-';
        }
    }
}

// passa as instruções do game para os usuarios
//e mostra o nome do jogador e sua pontuação
void instrucoesdeJogo(char *nomeDoJogadorUm, char *nomeDoJogadorDois, int rodada, int pontuacaoJogadorUm, int pontuacaoJogadorDois){
    printf("\n\n  | 7 | 8 | 9 |  \n");
    printf("  | 4 | 5 | 6 |  \n");
    printf("  | 1 | 2 | 3 |  ");

    printf("\nJogador %s , sera X.\n", nomeDoJogadorUm);
    printf("E o jogador %s , sera O.\n", nomeDoJogadorDois);
    printf("\n\n");
    printf("Rodada numero: %d\n\n", rodada);
    printf("\nPontuação: %s %d X %d %s \n\n", nomeDoJogadorUm, pontuacaoJogadorUm, pontuacaoJogadorDois ,nomeDoJogadorDois);
}

// função que serve para limpar a tela dos usuarios, deixando mais legível
void limpaTela() {
    system("CLS");
}

//função que usa um for para mostrar o tabuleiro
void mostraTabuleiro(char tabuleiro[3][3]){
    int linha, coluna;
    for(linha=0; linha<3; linha++){
        for(coluna=0; coluna<3; coluna++){
            printf("  %c", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

// função que serve para testar a posição jogada se foi valida
// testa se a posição da matriz esta vazia e inseri X ou O, dependendo do turno de quem for,
//por isto recebe a posição jogada pelo usuario e qual era o item marcado
//seu retorno serve para informar que a jogada foi valida
int posicaoJogadas(int posicaoJogada, char tabuleiro[3][3], char itemPassado, int jogadaValida){

        switch(posicaoJogada){
            case 1:
            if(tabuleiro[2][0] == '-'){
            jogadaValida = 1;
            tabuleiro[2][0] = itemPassado;
            break;
            }
            else{
            break;
            }

            case 2:
            if(tabuleiro[2][1] == '-'){
            tabuleiro[2][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
                };

            case 3:
            if(tabuleiro[2][2] == '-'){
            tabuleiro[2][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 4:
            if(tabuleiro[1][0] == '-'){
            tabuleiro[1][0] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 5:
            if(tabuleiro[1][1] == '-'){
            tabuleiro[1][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 6:
            if(tabuleiro[1][2] == '-'){
            tabuleiro[1][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 7:
            if(tabuleiro[0][0] == '-'){
            tabuleiro[0][0] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 8:
            if(tabuleiro[0][1] == '-'){
            tabuleiro[0][1] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };

             case 9:
            if(tabuleiro[0][2] == '-'){
            tabuleiro[0][2] = itemPassado;
            jogadaValida = 1;
            break;
            }
            else{
                break;
            };
        }

        return jogadaValida;
}

