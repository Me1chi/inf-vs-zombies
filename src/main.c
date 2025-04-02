#include "plants.h"
#include "raylib.h"
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
        (Vector2) {0, 0},
        1,
        no,
        WHITE,
    };

    Projectile proj_arr[MAXPROJECTILES];

    for (int i = 0; i < MAXPROJECTILES; i++) {
        proj_arr[i] = base_proj;
    }

    ProjectileArray projectiles = {
        proj_arr,
        0,
    };

    Texture2D peashooter_texture = LoadTexture("../resources/textures/peashooter.png");

    Vector2 peashooter_pos = {
        1,
        3,
    };

    plants[0] = (Plant) {
        "Peashooter",
        peashooter_pos,
        10,
        50,
        medium,
        0,
        no_fire,
        peashooter_texture,
    };

    SetTargetFPS(60);

    Vector2 button_size = {
        SCREENWIDTH/2,
        SCREENHEIGHT/2,
    };

    Button my_button = {
        (Vector2) {SCREENWIDTH/2 - button_size.x/2, THEGAMEBELOWTHAT},
        button_size,
        textures.grass[1],
        "",
        BLUE,
        true
    };

    char map[MAXMAPROWS][MAXMAPCOLLUMS] = {
        {'P', 'G', 'G', 'G'},
        {'P', 'P', 'T', 'G'},
        {'G', 'T', 'P', 'G'},
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

        EndDrawing();

    }

    CloseWindow();

    printf("Hello, World!\n");

    return 0;
}
