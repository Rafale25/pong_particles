#ifndef MY
#define MY

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"

extern const int screen_width;
extern const int screen_height;
extern const int max_particles;

t_framebuffer *framebuffer_create(unsigned int, unsigned int);
void put_pixel(t_framebuffer *, unsigned int, unsigned int, sfColor);
void put_square(t_framebuffer *, unsigned int, unsigned int, unsigned int, unsigned int, sfColor);
void clear_screen(t_framebuffer *);
void draw_ball(t_framebuffer *, ball_t);
void draw_racket(t_framebuffer *, racket_t);
void ball_move(ball_t *, particle_t *);
int ball_collide(ball_t *, racket_t);
void racket_move(racket_t *, sfKeyCode, sfKeyCode);
void init_particle(struct particle *, particle_t, float, float, int);
void particle_update(struct particle *);
float float_rand(float, float);

#endif
