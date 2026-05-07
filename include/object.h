#ifndef OBJECT_H
#define OBJECT_H

typedef struct
{
    float x;
    float y;
} Vertice;

typedef struct
{
    int qtdVertices;
    Vertice *vertices;
} Objeto2D;

Objeto2D *carregarObjeto(const char *nomeArquivo);

void desenharObjeto(int **tela, Objeto2D *obj);

void liberarObjeto(Objeto2D *obj);

#endif