#pragma once
#include <raylib.h>

typedef enum {
    grass,
    tomb,
} Tile;

typedef enum {
    no,
    fire,
    freeze,
    double_shot,
    gen_sun,
    explode,
    chew,

} PlantDamageEffect;

typedef enum {
    no_fire = -1,
    very_slow = 15,
    slow = 8,
    medium = 4,
    fast = 2,
    fire_once = 0,

} FireLoadDelay;

typedef struct {

    char* name; //Each plant will have a char associated. It's first letter. So it needs to be well chosen
    Vector2 position;
    int life_points;
    FireLoadDelay rate;
    PlantDamageEffect effects;

} Plant;
