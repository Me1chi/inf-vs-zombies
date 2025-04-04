#include "plants.h"
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "buttons.h"
#include "game.h"
#include "map.h"
#include "structs.h"
#include "table.h"
#include "clock.h"
#include "plantsbar.h"
#include "textures.h"

int main(void) {

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "INF vs Zombies");

    GameTextures textures = {0};
    load_general_textures(&textures);

    Plant plants[HOWMANYPLANTS] = {0};

    Projectile base_proj = {
        (Vector2) {-SCREENWIDTH, -SCREENHEIGHT},
        1,
        no,
        WHITE,
    };

    Projectile proj_arr[MAXPROJECTILES];

    ProjectileArray projectiles = {
        proj_arr,
        0,
    };

    for (int i = 0; i < MAXPROJECTILES; i++) {
        projectiles.array[i] = base_proj;
    }

    Texture2D peashooter_texture = LoadTexture("../resources/textures/peashooter.png");

    Texture sunflower_texture = LoadTexture("../resources/textures/sunflower.png");

    plants[0] = (Plant) {
        "Peashooter",
        10,
        50,
        medium,
        0,
        no_fire,
        peashooter_texture,
    };

    plants[1] = (Plant) {
        "Sunflower",
        10,
        50,
        slow,
        0,
        no_fire,
        sunflower_texture,
    };

    SetTargetFPS(60);

    Vector2 button_size = {
        SCREENWIDTH/8,
        SCREENHEIGHT/6,
    };

    Button my_button = {
        (Vector2) {SCREENWIDTH/4 - button_size.x/2, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.button,
        "",
        BLUE,
        true,
    };

    Button sunflower_button = {
        (Vector2) {SCREENWIDTH/4 + button_size.x/2 + SMALLBLANKSPACE, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.button,
        "",
        BLUE,
        true,
    };

    Button sun_button = {
        (Vector2) {SCREENWIDTH/4 - 3*button_size.x/2, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.sun,
        "1000",
        BLACK,
        false,
    };

    char map[MAXMAPROWS][MAXMAPCOLLUMS] = {
        {'P', 'S', 'G', 'G'},
        {'P', 'P', 'T', 'G'},
        {'S', 'T', 'P', 'G'},
    };

    while(!WindowShouldClose()) {
        // Game update space
        all_plants_shoot(plants, &projectiles);
        update_projectiles(&projectiles);

        // Drawing space
        BeginDrawing();

        ClearBackground(DARKGRAY);

        draw_game_grid(map, textures, plants);
        draw_projectiles(projectiles, textures);

        plant_button_draw(my_button, plants[0], textures);
        plant_button_draw(sunflower_button, plants[1], textures);

        sun_stack_draw(sun_button);

        EndDrawing();

    }

    CloseWindow();

    printf("Hello, World!\n");

    return 0;
}
