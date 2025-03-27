#pragma once

#include "structs.h"

int timer(int how_many_seconds);

int composed_timer(int seconds_to_run, int seconds_running);

int external_timer(int how_many_seconds, float* ext_accum);
