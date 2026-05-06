#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int **criaTela(int larg, int alt){
  int **tela, i, j;
  tela = (int **) malloc(alt * sizeof(int *));
  for(i=0; i<alt; i++) {
    tela[i] = (int *) malloc(larg * sizeof(int));
    for(j=0; j<larg; j++) tela[i][j] = 0;
  }
  return tela;
}

void imprimeTela(int **tela){
  int i, j;
  printf("--+----------------------------------------------------------------------------------------------------+\n");
  for(i=0; i<nLinha; i++) {
    printf("%2d|", i);
    for(j=0; j<nColuna; j++)
      if(tela[i][j]) printf("*");
      else printf(" ");
    printf("|\n");
  }  printf("--+----------------------------------------------------------------------------------------------------+\n");
}

void limpaTela(int **tela)
{
  for(int i = 0; i < nColuna; i++)
  {
    for(int j = 0; j < nLinha; j++)
    {
      tela[i][j] = 0;
    }
  }
}

void limpaTerminal()
{
  system("cls");
}