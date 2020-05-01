#include "lib/estruturas.h"
#include "lib/utilidades.h"

//recebe a pontua��o dos jogadores para poder dar continuidade dos jogos sem zerar as pontua��es dos jogadores
void estruturaDoJogo(char *nomeDoJogadorUm, char *nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    /*
    * Matriz tabuleiro[3][3], cria uma matriz que serira como tabuleiro do jogo

    * Variavel itemPassado, guarda o item X ou O, que servira para substituir na matriz dependendo de quem for o turno

    * Variavel posicaoJogada, guarda o numero que foi passado pelo usuario, o qual representa uma posi��o
    * no tabuleiro, este sera testado na fun��o posicaoJogada

    * Variavel turnoDoJogador, pode ser 1 ou 2 , define quem ira jogar
    * Variavel statusDoJogo, serve para controlar se tem ganhador ou n�o no jogo, quem altera ela � a fun��o confereTabuleiro

    * Variavel rodada, guarda em que rodada o jogo esta podendo chegar no m�ximo a 8

    * Variavel selecao, guarda a escolha do usuario para reiniciar o jogo, ir para o menu ou sair
    */
    char tabuleiro[3][3], itemPassado;
    int posicaoJogada=0, turnoDoJogador=1, statusDoJogo=0, rodada =0, selecao=0;
    int jogadaValida= 0;
    limpaTela();

    //chaama a fun��o para criar um tabuleiro
    criaTabuleiro(tabuleiro);

    while(rodada < 9 && statusDoJogo == 0){
        //limpa a tela do console para ficar mais legivel o jogo
        limpaTela();

        //mostra as instru��es do game para os jogadores informando que se usa o teclado num�rico para jogar
        instrucoesdeJogo(nomeDoJogadorUm,nomeDoJogadorDois,rodada,pontuacaoJogadorUm, pontuacaoJogadorDois);

        //chama a fun��o para mostrar o tabuleiro
        mostraTabuleiro(tabuleiro);
        printf("\n");

    jogadaValida = 0;

        //while para controlar se a jogada for valida testando se a posi��o est� vazia e se foi uma posi��o real
       while(jogadaValida == 0) {
        if(turnoDoJogador == 1){
            printf("Jogador %s, Escolha aonde ir� inserir o X:", nomeDoJogadorUm );
            scanf("%d", &posicaoJogada);
            itemPassado = 'X';
        }
        else{
            printf("Jogador %s, Escolha aonde ir� inserir a O:", nomeDoJogadorDois );
            scanf("%d", &posicaoJogada);
            itemPassado = 'O';
        }

    //chama a fun��o que fara os testes de jogada valida e ira alterar a matriz
     jogadaValida = posicaoJogadas(posicaoJogada, &tabuleiro, itemPassado, jogadaValida);

       }

    //estes if-else fazem o controle de turnos dos jogadores
    if(turnoDoJogador == 1){
            turnoDoJogador = 2;
    }

    else{
        turnoDoJogador =1;
    }

    //incrementa a variavel para se ter no maximo 9 rodadas possiveis
    rodada++;

    //estes if-else chamam a fun��o para testar o tabuleiro verificando se h� ganhadores
    //tamb�m incrementa a pontua��o do jogador ganhador, assim ficando salva se quiserem continuar jogando
    //alem de encerrar o jogo na variavel statusDoJogo
    if(confereTabuleiro(tabuleiro) == 1){
        printf("Jogador %s venceu!!!", nomeDoJogadorUm);
        statusDoJogo++;
        pontuacaoJogadorUm++;
    }
    else if (confereTabuleiro(tabuleiro) == 2){
        printf("Jogador %s venceu!!!", nomeDoJogadorDois);
        statusDoJogo++;
        pontuacaoJogadorDois++;
    }
    else if (rodada == 9){
        printf("Empate!!!");
    }

    }

    //este mostrar tabuleiro serve para mostrar o tabuleiro vencedor
    printf("\n");
    mostraTabuleiro(tabuleiro);
    printf("\n");

    printf("Fim de Jogo!\n");

    // aqui pedimos aos jogadores que informem o que desejam fazer
    // se quiserem continuar jogando as pontua��es ser�o salvas
    printf("O que deseja Fazer?\n");
    printf("1- Continuar Jogando\n");
    printf("2- Retornar menu principal\n");
    printf("3- Sair\n");
    scanf("%d", &selecao);

    if(selecao == 3){
        printf("At� mais!");
    }
    else if(selecao == 1){
            //chama fun��o agora setando a pontua��o atual dos jogadores
        estruturaDoJogo(nomeDoJogadorUm, nomeDoJogadorDois, pontuacaoJogadorUm, pontuacaoJogadorDois);
    }
    else if(selecao == 2){
        menuJogo();
    }
}


void menuJogo(){

    /*
    *Variavel opcaoEscolhida, guarda a escolha do usuario para iniciar o jogo, ir para sobre ou sair

    * Vetores nomeDoJogadorUm e nomeDoJogadorDois, guardam os nomes dos jogadores
    * com ela j� disponiveis

    *
    */
    int opcaoEscolhida = 0;
    char nomeDoJogadorUm[15], nomeDoJogadorDois[15];

    // while para que o usuario escolha o que deseja efetuar no jogo
    while(opcaoEscolhida < 1 || opcaoEscolhida > 3){
    void limpaTela();

    printf("Bem-Vindo ao Jogo da Velha\n\n\n");
    printf("Escolha uma da op��es a baixo");
    printf("\n1- Jogar");
    printf("\n2- Sobre");
    printf("\n3- Sair");
    printf("\nDigite da op��o e aperte Enter:");
    scanf("%d", &opcaoEscolhida);

    // op��o 1 serve para iniciar o jogo
    // op��o 2 tras inform��o dos desenvolvedores, instru��es de jogo e pede uma nova escolha
    // op��o 3 sai do jogo
    switch(opcaoEscolhida){
        case 1:
            printf("Digite o nome do Jogador 1:");
            scanf("%s",&nomeDoJogadorUm);
            printf("Digite o nome do Jogador 2:");
            scanf("%s", &nomeDoJogadorDois);
            //chama a fun��o estuturaDoJogo setando como 0 as pontua��es dos jogadores
            estruturaDoJogo(nomeDoJogadorUm,nomeDoJogadorDois,0,0);
        break;

        case 2:
            printf("\n\nJogo desenvolvido por:\nHiago Silva da Silva\nLeonardo Oliveira de Farias\nGabriel Luis Mendes\n"
                   "Jogo desenvolvido para o trabalho de Praticas de Programa��o 2020/01\n"
                   "Jogo da Velha, para efetuar as escolhas de 'X' ou 'O', utilize o teclado num�rico.\n\n");
                   printf("O que deseja fazer\n 1 - Menu Inicial \n 2 - Sair \n Escolha e aperte Enter: ");
                   int opcao;
                   scanf("%d", &opcao);
                   if(opcao ==1){
                        limpaTela();
                        menuJogo();
                   }else{
                   break;
                   }
        break;

        case 3:
            printf("\n\nAt� mais!\n\n");
        break;
    }
 }
}

