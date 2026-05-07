#ifndef SCREEN_H
#define SCREEN_H

#define HEIGHT 50
#define WIDTH 100

int **criaTela(int larg, int alt);
void imprimeTela(int **tela);
void limpaTela(int **tela);
void liberaTela(int **tela);
void limpaTerminal();

#endif