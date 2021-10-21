#include "my.h"

int main()
{
    sfRenderWindow* window;
    sfVideoMode mode = {screen_width, screen_height, 32};
    sfEvent event;

    t_framebuffer *fb;
    sfTexture* texture;
    sfSprite* sprite;

    window = sfRenderWindow_create(mode, "My window", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 120);
    fb = framebuffer_create(screen_width, screen_height);
    texture = sfTexture_create(screen_width, screen_height);
    sprite = sfSprite_create();

    struct ball ball;
    ball.pos.x = 200;
    ball.pos.y = screen_height / 2;
    ball.vel.x = 3.2f;
    ball.vel.y = -1.4f;
    ball.size = 20;
    ball.color = sfGreen;

    struct racket racket1;
    racket1.pos.x = 50;
    racket1.pos.y = screen_height / 2 - 25;
    racket1.size.x = 10;
    racket1.size.y = 80;
    racket1.color = sfBlue;

    struct racket racket2;
    racket2.pos.x = screen_width - 50;
    racket2.pos.y = screen_height / 2 - 25;
    racket2.size.x = 10;
    racket2.size.y = 80;
    racket2.color = sfRed;

    particle_t p_list[max_particles];

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        clear_screen(fb);

        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;

        ball_move(&ball, p_list);
        if (ball_collide(&ball, racket1)) {
            particle_t temp = {ball.pos.x + ball.size / 2, ball.pos.y + ball.size/2, 0, 0, 10, sfCyan};
            init_particle(p_list, temp, -M_PI_2, M_PI_2, 80);
        }

        if (ball_collide(&ball, racket2)) {
            particle_t temp = {ball.pos.x + ball.size / 2, ball.pos.y + ball.size / 2, 0, 0, 10, sfMagenta};
            init_particle(p_list, temp, -M_PI_2 + M_PI, M_PI_2 + M_PI, 80);
        }
        draw_ball(fb, ball);

        draw_racket(fb, racket1);
        racket_move(&racket1, sfKeyZ, sfKeyS);

        draw_racket(fb, racket2);
        racket_move(&racket2, sfKeyUp, sfKeyDown);

        particle_t temp = {ball.pos.x + ball.size / 2, ball.pos.y + ball.size/2, 0, 0, 8, ball.color};
        init_particle(p_list, temp, -M_PI, M_PI, 2);

        particle_update(p_list);
        for (int i = 0 ; i < max_particles ; ++i) {
            if (p_list[i].size > 0) {
                if (p_list[i].x > 0 && p_list[i].x < screen_width && p_list[i].y > 0 && p_list[i].y < screen_height) {

                    if (p_list[i].size > 0)
                        p_list[i].size -= 0.05;

                    put_square(fb, p_list[i].x, p_list[i].y, p_list[i].size, p_list[i].size, p_list[i].color);
                }
            }
        }
        sfTexture_updateFromPixels(texture, fb->pixels, screen_width, screen_height, 0, 0);
        sfSprite_setTexture(sprite, texture, sfFalse);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
    return 0;
}
