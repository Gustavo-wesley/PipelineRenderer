#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>

#include "transform.h"

void translacao(Objeto2D *obj, float tx, float ty)
{
    if (obj == NULL)
        return;

    for (int i = 0; i < obj->qtdVertices; i++)
    {
        obj->vertices[i].x += tx;
        obj->vertices[i].y += ty;
    }
}

void escala(Objeto2D *obj, float sx, float sy)
{
    if (obj == NULL)
        return;

    for (int i = 0; i < obj->qtdVertices; i++)
    {
        obj->vertices[i].x *= sx;
        obj->vertices[i].y *= sy;
    }
}

void rotacao(Objeto2D *obj, float angulo)
{
    if (obj == NULL)
        return;

    float rad = angulo * M_PI / 180.0;

    float cosA = cos(rad);
    float sinA = sin(rad);

    for (int i = 0; i < obj->qtdVertices; i++)
    {
        float x = obj->vertices[i].x;
        float y = obj->vertices[i].y;

        obj->vertices[i].x = x * cosA - y * sinA;

        obj->vertices[i].y = x * sinA + y * cosA;
    }
}