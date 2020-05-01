#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

int confereTabuleiro(char tabuleiro[3][3]);
void criaTabuleiro(char tabuleiro[3][3]);
void instrucoesdeJogo(char *nomeDoJogadorUm, char *nomeDoJogadorDois, int rodada, int pontuacaoJogadorUm, int pontuacaoJogadorDois);
void limpaTela();
void mostraTabuleiro(char tabuleiro[3][3]);
int posicaoJogadas(int posicaoJogada, char tabuleiro[3][3], char itemPassado, int jogadaValida);


#endif // UTILIDADES_H_INCLUDED
