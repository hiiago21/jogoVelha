#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "lib/estruturas.h"



int main(){
    // fun��o correspondente para corrigir os erros de acentos
    setlocale(LC_ALL, "Portuguese");

    //fun��o que inicia o jogo
    menuJogo();

    return 0;
}
