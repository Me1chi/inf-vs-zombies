#include "clock.h"
#include "game.h"
#include "raylib.h"
#include "structs.h"

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
