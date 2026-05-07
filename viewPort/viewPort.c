#include "viewPort.h"
#include "screen.h"

#define SCALE 4.0

int viewportX(float x)
{
    return (int)(x * SCALE + WIDTH / 2.0);
}

int viewportY(float y)
{
    return (int)(HEIGHT / 2.0 - y * SCALE);
}