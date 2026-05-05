#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "screen.h"
#include "draw.h"

int main()
{
    int **tela;

    tela = criaTela(nColuna, nLinha);

    desenhaLinha(tela, 10, 10, 80, 8);//Oct0
    desenhaLinha(tela, 81, 15, 90, 2);//Oct1
    desenhaLinha(tela, 78, 18, 70, 12);//Oct2
    desenhaLinha(tela, 65, 25, 5, 22);//Oct3
    desenhaLinha(tela, 75, 27, 5, 32);//Oct4
    desenhaLinha(tela, 13, 35, 9, 42);//Oct5
    desenhaLinha(tela, 20, 38, 27, 47);//Oct6
    desenhaLinha(tela, 10, 15, 80, 23);//Oct7

    imprimeTela(tela);

    limpaTela(tela);
    
    return 0;
}