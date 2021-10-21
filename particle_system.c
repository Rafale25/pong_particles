#include "my.h"

void particle_update(struct particle *p_list)
{
    for (int i = 0 ; i < max_particles ; ++i) {
        p_list[i].x += p_list[i].vel_x;
        p_list[i].y -= p_list[i].vel_y;
        p_list[i].vel_x *= 0.99;
        p_list[i].vel_y *= 0.99;
    }
}

void init_particle(particle_t *p_list, particle_t p, float min_angle, float max_angle, int count)
{
    static int i = 0;
    for (int j = 0 ; j < count ; ++j) {

        i = (i + 1) % max_particles;
        p_list[i].x = p.x;
        p_list[i].y = p.y;
        p_list[i].size = p.size;
        p_list[i].color = p.color;

        float const angle = float_rand(min_angle, max_angle);
        p_list[i].vel_x = cosf(angle) * float_rand(0, 1.2f);
        p_list[i].vel_y = sinf(angle) * float_rand(0, 1.2f);
    }
}
