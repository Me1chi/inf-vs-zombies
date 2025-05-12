#pragma once
#include "game.h"
#include "raylib.h"
#include <stdbool.h>

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

    char name[50]; // Each plant will have a char associated. It's first letter.
                   // So it needs to be well chosen
    int life_points;
    int cost;
    FireLoadDelay rate;
    PlantDamageEffect effects;
    Texture2D texture;
    float timer_accum;

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
    Plant plants[HOWMANYPLANTS];
    Button plants_bar[HOWMANYPLANTS];

} PlantManager;

typedef struct {
    Texture2D textures[HOWMANYZOMBIES];
    int counter;

} ZombieTextures;

typedef struct {
    Texture2D logo;
    Texture2D button;
    Texture2D button_text;
    Texture2D sun;
    Texture2D grass[2];
    Texture2D pea_projectile;

    Texture2D menu_background;
    Texture2D menu_play_button;
    Texture2D menu_leaderboard_button;
    Texture2D menu_exit_button;
    Texture2D leaderboard;

} GameTextures;

typedef struct {
    Vector2 position;
    int direction;
    PlantDamageEffect effect;
    Color filter;
    float rotation;
    char text[50];

} Projectile;

typedef struct {
    Projectile *array;
    int counter;

} ProjectileArray;

typedef struct {
    char map[MAXMAPROWS][MAXMAPCOLLUMS];
    float timer[MAXMAPROWS][MAXMAPCOLLUMS];
    Plant selected_plant;
    int selected_row;
    int selected_col;

} SmartMap;

typedef struct {
    char text[10];
    int score;
} TopPlayer;

typedef struct {
    int life_points;
    int row;
    float coord_x;

    bool alive;
} Zombie;
