#include <stdio.h>
#include <stdlib.h>

#include "screen.h"

int **criaTela(int larg, int alt)
{
    int **tela;

    tela = (int **) malloc(alt * sizeof(int *));

    if (tela == NULL)
    {
        printf("\nErro de alocacao da tela!\n");
        return NULL;
    }

    for (int i = 0; i < alt; i++)
    {
        tela[i] = (int *) malloc(larg * sizeof(int));

        if (tela[i] == NULL)
        {
            printf("\nErro de alocacao da tela!\n");

            for (int j = 0; j < i; j++)
            {
                free(tela[j]);
            }

            free(tela);

            return NULL;
        }

        for (int j = 0; j < larg; j++)
        {
            tela[i][j] = 0;
        }
    }

    return tela;
}

void imprimeTela(int **tela)
{
    printf("--+");

    for (int i = 0; i < WIDTH; i++)
    {
        printf("-");
    }

    printf("+\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        printf("%2d|", i);

        for (int j = 0; j < WIDTH; j++)
        {
            if (tela[i][j])
                printf("*");
            else
                printf(" ");
        }

        printf("|\n");
    }

    printf("--+");

    for (int i = 0; i < WIDTH; i++)
    {
        printf("-");
    }

    printf("+\n");
}

void limpaTela(int **tela)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            tela[i][j] = 0;
        }
    }
}

void liberaTela(int **tela)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        free(tela[i]);
    }

    free(tela);
}

void limpaTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}