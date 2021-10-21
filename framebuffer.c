#include "my.h"

t_framebuffer * framebuffer_create(unsigned int width, unsigned int height)
{
    t_framebuffer * fb = NULL;
    fb = malloc(sizeof(t_framebuffer));
    fb->pixels = malloc(width * height * 32 / 8);
    fb->width = width;
    fb->height = height;
    return (fb);
}

void put_pixel(t_framebuffer * framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[(x * 4) + (y * framebuffer->width * 4)] = color.r;
    framebuffer->pixels[(x * 4) + (y * framebuffer->width * 4) + 1] = color.g;
    framebuffer->pixels[(x * 4) + (y * framebuffer->width * 4) + 2] = color.b;
    framebuffer->pixels[(x * 4) + (y * framebuffer->width * 4) + 3] = color.a;
}

void clear_screen(t_framebuffer * framebuffer)
{
    for (unsigned int y = 0 ; y < framebuffer->height ; y++)
        for (unsigned int x = 0 ; x < framebuffer->width ; x++)
            put_pixel(framebuffer, x, y, sfBlack);
}
