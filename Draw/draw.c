#include <stdlib.h>
#include <math.h>
#include "draw.h"
#include "screen.h"

void desenhaLinha(int **tela, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;  // versão correta para algoritmo geral
    int e2;

    while (1)
    {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
        {
            tela[y0][x0] = 1;
        }

        if (x0 == x1 && y0 == y1)
            break;

        e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}