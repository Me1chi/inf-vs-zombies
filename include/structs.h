#pragma once
#include "raylib.h"
#include <stdbool.h>
#include "game.h"

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

    char name[50]; //Each plant will have a char associated. It's first letter. So it needs to be well chosen
    Vector2 position;
    int life_points;
    int cost;
    FireLoadDelay rate;
    float time_accum; // Stores the shooting time
    PlantDamageEffect effects;
    Texture2D texture;

} Plant;

typedef struct {
    Vector2 position;
    Vector2 size;
    Texture2D texture;
    char text[50];
    Color text_color;
    bool selected;

} Button;

typedef struct {
    Texture2D textures[HOWMANYTEXTURES];
    int counter;

} PlantTextures;

typedef struct {
    Texture2D textures[HOWMANYTEXTURES];
    int counter;

} ZombieTextures;

typedef struct {
    Texture2D logo;
    Texture2D button;
    Texture2D sun;
    Texture2D grass[2];
    Texture2D pea_projectile;

} GameTextures;

typedef struct {
    Vector2 position;
    int direction;
    PlantDamageEffect effect;
    Color filter;
    float rotation;

} Projectile;

typedef struct {
    Projectile *array;
    int counter;

} ProjectileArray;
