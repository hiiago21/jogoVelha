#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "lib/estruturas.h"



int main(){
    // função correspondente para corrigir os erros de acentos
    setlocale(LC_ALL, "Portuguese");

    //função que inicia o jogo
    menuJogo();

    return 0;
}
