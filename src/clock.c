#include "clock.h"
#include "game.h"
#include "raylib.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int timer(int how_many_seconds) {
    static float timer_accum = 0;

    int tick = 0;

    if (timer_accum >= how_many_seconds) {
        timer_accum = 0;
        tick = 1;
    } else {
        timer_accum += GetFrameTime();
    }

    return tick;
}

int composed_timer(int seconds_to_run, int seconds_running) {

    static int timer_on = 0;
    static float timer_accum = 0;
    int tick = 0;

    if (timer_on == 0) {
        timer_on = timer(seconds_to_run);
    } else if (seconds_running >= timer_accum) {
        timer_accum += GetFrameTime();
        tick = 1;
    } else {
        timer_accum = 0;
        timer_on = 0;
    }

    return tick;
}

int external_timer(int how_many_seconds, float *ext_accum) {
    int tick = 0;

    if ((*ext_accum) >= how_many_seconds) {
        *ext_accum = 0;
        tick = 1;
    } else {
        *ext_accum += GetFrameTime();
    }

    return tick;
}

int roll_a_dice(int sides) {
    srand(time(NULL));

    if (sides <= 0) {
        return 1;
    } else {
        return rand() % sides + 1;
    }
}
