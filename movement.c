#include "my.h"

// static float get_incident_angle(ball_t ball)
// {
//     float angle = atanf(ball.vel.y / ball.vel.x);
//     return (angle * (180 / M_PI));
// }

void ball_move(ball_t *ball, particle_t *p_list)
{
    if (ball->pos.x < 0 || ball->pos.x > screen_width - ball->size) {
        ball->pos.x = screen_width/2;
        ball->pos.y = screen_height/2;
        ball->vel.y = 0;
    }

    if (ball->pos.y + ball->vel.y < 0 || ball->pos.y + ball->vel.y > screen_height - ball->size) {
        ball->vel.y *= -1;
        particle_t temp = {ball->pos.x + ball->size / 2, ball->pos.y + ball->size/2, 0, 0, 10, sfGreen};
        init_particle(p_list, temp, -M_PI, M_PI, 30);
    }

    ball->pos.x += ball->vel.x;
    ball->pos.y += ball->vel.y;
}

int ball_collide(ball_t *ball, racket_t racket)
{
    if (ball->pos.x + ball->size > racket.pos.x)
        if (ball->pos.x < racket.pos.x + racket.size.x)
            if (ball->pos.y < racket.pos.y + racket.size.y)
                if (ball->pos.y + ball->size > racket.pos.y) {
                    ball->color = racket.color;
                    // const float angle = get_incident_angle(*ball);
                    // ball->vel.x = cosf(angle) * 3.0f;
                    // ball->vel.y = sinf(angle) * 3.0f;
                    ball->vel.x *= -1;
                    ball->vel.y = (ball->pos.y - (racket.pos.y + racket.size.y / 2)) / 15;
                    return 1;
                }
    return 0;
}

void racket_move(racket_t *racket, sfKeyCode keyUp, sfKeyCode keyDown)
{
    if (sfKeyboard_isKeyPressed(keyUp) && racket->pos.y - 3 > 0)
        racket->pos.y -= 3;
    else if (sfKeyboard_isKeyPressed(keyDown) && racket->pos.y < screen_height - racket->size.y)
        racket->pos.y += 3;
}
