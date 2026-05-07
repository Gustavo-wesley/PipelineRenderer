#include <stdio.h>
#include <stdlib.h>

#include "viewPort.h"
#include "object.h"
#include "draw.h"

Objeto2D *carregarObjeto(const char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        return NULL;
    }

    Objeto2D *obj = malloc(sizeof(Objeto2D));

    if (obj == NULL)
    {
        printf("\nErro de alocacao!\n");

        fclose(arq);
        return NULL;
    }

    // leitura da quantidade de vertices
    if (fscanf(arq, "%d", &obj->qtdVertices) != 1)
    {
        printf("\nErro ao ler quantidade de vertices!\n");

        free(obj);
        fclose(arq);

        return NULL;
    }

    obj->vertices = malloc(obj->qtdVertices * sizeof(Vertice));

    if (obj->vertices == NULL)
    {
        printf("\nErro de alocacao!\n");

        free(obj);
        fclose(arq);

        return NULL;
    }

    // leitura dos vertices
    for (int i = 0; i < obj->qtdVertices; i++)
    {
        if (fscanf(arq,
                   "%f %f",
                   &obj->vertices[i].x,
                   &obj->vertices[i].y) != 2)
        {
            printf("\nErro ao ler vertice %d!\n", i);

            free(obj->vertices);
            free(obj);

            fclose(arq);

            return NULL;
        }
    }

    fclose(arq);

    return obj;
}

void desenharObjeto(int **tela, Objeto2D *obj)
{
    if (obj == NULL)
        return;

    for (int i = 0; i < obj->qtdVertices; i++)
    {
        int prox = (i + 1) % obj->qtdVertices;

        desenhaLinha(
            tela,

            viewportX(obj->vertices[i].x),
            viewportY(obj->vertices[i].y),

            viewportX(obj->vertices[prox].x),
            viewportY(obj->vertices[prox].y)
        );
    }
}

void liberarObjeto(Objeto2D *obj)
{
    if (obj == NULL)
        return;

    free(obj->vertices);
    free(obj);
}