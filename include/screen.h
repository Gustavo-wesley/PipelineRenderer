#ifndef SCREEN_H
#define SCREEN_H

static int nLinha = 50;
static int nColuna = 100;

int **criaTela(int larg, int alt);
void imprimeTela(int **tela);
void limpaTela(int **tela);

#endif