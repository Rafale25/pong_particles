#include "my.h"

void put_square(t_framebuffer * fb, unsigned int x, unsigned int y, unsigned int width, unsigned int height, sfColor color)
{
    for (unsigned int dy = 0 ; dy < height ; ++dy)
        for (unsigned int dx = 0 ; dx < width ; ++dx)
            put_pixel(fb, x + dx, y + dy, color);
}

void draw_ball(t_framebuffer * fb, ball_t ball)
{
    put_square(fb, ball.pos.x, ball.pos.y, ball.size, ball.size, ball.color);
}

void draw_racket(t_framebuffer * fb, racket_t racket)
{
    put_square(fb, racket.pos.x, racket.pos.y, racket.size.x, racket.size.y, racket.color);
}
