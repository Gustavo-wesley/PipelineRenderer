#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "screen.h"
#include "draw.h"
#include "transform.h"
#include "object.h"

int lerInt(const char *msg);

void modoTranslacao(int **tela, Objeto2D *obj);
void modoRotacao(int **tela, Objeto2D *obj);
void modoEscala(int **tela, Objeto2D *obj);

int main()
{
    int option = -1;

    int **tela = criaTela(WIDTH, HEIGHT);

    if (tela == NULL)
    {
        return 1;
    }

    Objeto2D *obj = NULL;

    do
    {
        limpaTerminal();

        printf("\n========== COMPUTACAO GRAFICA ==========\n");

        printf("\n1 - Carregar objeto");
        printf("\n2 - Desenhar objeto");
        printf("\n3 - Translacao");
        printf("\n4 - Rotacao");
        printf("\n5 - Escala");
        printf("\n0 - Sair");

        option = lerInt("\n\nOpcao: ");

        switch (option)
        {
            case 1:
            {
                char nomeArquivo[100];

                printf("\nDigite o caminho do arquivo: ");
                scanf("%s", nomeArquivo);

                getchar();

                if (obj != NULL)
                {
                    liberarObjeto(obj);
                }

                obj = carregarObjeto(nomeArquivo);

                if (obj != NULL)
                {
                    printf("\nObjeto carregado com sucesso!\n");
                }

                system("pause");

                break;
            }

            case 2:
            {
                if (obj == NULL)
                {
                    printf("\nNenhum objeto carregado!\n");
                    system("pause");
                    break;
                }

                limpaTela(tela);

                desenharObjeto(tela, obj);

                imprimeTela(tela);

                system("pause");

                break;
            }

            case 3:
            {
                modoTranslacao(tela, obj);
                break;
            }

            case 4:
            {
                modoRotacao(tela, obj);
                break;
            }

            case 5:
            {
                modoEscala(tela, obj);
                break;
            }

            case 0:
                break;

            default:
            {
                printf("\nOpcao invalida!\n");
                system("pause");
                break;
            }
        }

    } while(option != 0);

    liberarObjeto(obj);

    liberaTela(tela);

    return 0;
}

void modoTranslacao(int **tela, Objeto2D *obj)
{
    if (obj == NULL)
    {
        printf("\nNenhum objeto carregado!\n");
        system("pause");
        return;
    }

    char tecla;

    do
    {
        limpaTerminal();

        limpaTela(tela);

        desenharObjeto(tela, obj);

        imprimeTela(tela);

        printf("\n=== MODO TRANSLACAO ===\n");
        printf("\nW - Cima");
        printf("\nS - Baixo");
        printf("\nA - Esquerda");
        printf("\nD - Direita");
        printf("\nQ - Sair");

        tecla = _getch();

        switch(tecla)
        {
            case 'w':
            case 'W':
                translacao(obj, 0, 0.2);
                break;

            case 's':
            case 'S':
                translacao(obj, 0, -0.2);
                break;

            case 'a':
            case 'A':
                translacao(obj, -0.2, 0);
                break;

            case 'd':
            case 'D':
                translacao(obj, 0.2, 0);
                break;
        }

    } while(tecla != 'q' && tecla != 'Q');
}

void modoRotacao(int **tela, Objeto2D *obj)
{
    if (obj == NULL)
    {
        printf("\nNenhum objeto carregado!\n");
        system("pause");
        return;
    }

    char tecla;

    do
    {
        limpaTerminal();

        limpaTela(tela);

        desenharObjeto(tela, obj);

        imprimeTela(tela);

        printf("\n=== MODO ROTACAO ===\n");
        printf("\nA - Rotaciona esquerda");
        printf("\nD - Rotaciona direita");
        printf("\nQ - Sair");

        tecla = _getch();

        switch(tecla)
        {
            case 'a':
            case 'A':
                rotacao(obj, -5);
                break;

            case 'd':
            case 'D':
                rotacao(obj, 5);
                break;
        }

    } while(tecla != 'q' && tecla != 'Q');
}

void modoEscala(int **tela, Objeto2D *obj)
{
    if (obj == NULL)
    {
        printf("\nNenhum objeto carregado!\n");
        system("pause");
        return;
    }

    char tecla;

    do
    {
        limpaTerminal();

        limpaTela(tela);

        desenharObjeto(tela, obj);

        imprimeTela(tela);

        printf("\n=== MODO ESCALA ===\n");
        printf("\nW - Aumentar");
        printf("\nS - Diminuir");
        printf("\nQ - Sair");

        tecla = _getch();

        switch(tecla)
        {
            case 'w':
            case 'W':
                escala(obj, 1.1, 1.1);
                break;

            case 's':
            case 'S':
                escala(obj, 0.9, 0.9);
                break;
        }

    } while(tecla != 'q' && tecla != 'Q');
}

int lerInt(const char *msg)
{
    char buffer[100];

    int valor;

    char *end;

    while (1)
    {
        printf("%s", msg);

        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            printf("\nErro de leitura\n");
            continue;
        }

        valor = strtol(buffer, &end, 10);

        if (end == buffer || (*end != '\n' && *end != '\0'))
        {
            printf("\nEntrada invalida!\n");
            continue;
        }

        return valor;
    }
}