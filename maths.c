#include "my.h"

float float_rand(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * ( max - min ));
}
