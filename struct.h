#include "my.h"

#ifndef STRUCT
#define STRUCT

typedef struct framebuffer {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
    struct framebuffer * next;
} t_framebuffer;

typedef struct ball {
    sfVector2f pos;
    sfVector2f vel;
    int size;
    sfColor color;
} ball_t;

typedef struct racket {
    sfVector2f pos;
    sfVector2i size;
    sfColor color;
} racket_t;

typedef struct particle {
    float x;
    float y;
    float vel_x;
    float vel_y;
    float size;
    sfColor color;
} particle_t;

#endif
