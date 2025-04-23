#include "plants.h"
#include "raylib.h"
#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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

    int sun_stack = 50;

    SmartMap smart_map = initialize_smart_map(MAXMAPROWS, MAXMAPCOLLUMS);

    GameTextures textures = {0};
    PlantManager plant_manager = {0};

    plant_manager_mapping(&plant_manager);
    load_general_textures(&textures);

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

    SetTargetFPS(60);

    Vector2 button_size = {
        SCREENWIDTH/8,
        SCREENHEIGHT/6,
    };

    Button my_button = {
        (Vector2) {SCREENWIDTH/4 - button_size.x/2, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.button,
        "1",
        BLUE,
        false,
    };

    Button sunflower_button = {
        (Vector2) {SCREENWIDTH/4 + button_size.x/2 + SMALLBLANKSPACE, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.button,
        "2",
        BLUE,
        false,
    };

    Button sun_button = {
        (Vector2) {SCREENWIDTH/4 - 3*button_size.x/2, THEGAMEBELOWTHAT - button_size.y/1.5},
        button_size,
        textures.sun,
        "1000",
        BLACK,
        false,
    };

    plant_manager.plants_bar[0] = my_button;
    plant_manager.plants_bar[1] = sunflower_button;

    while(!WindowShouldClose()) {
        // Game update space
        all_plants_shoot(plant_manager.plants, &projectiles);
        update_projectiles(&projectiles);

        navigate_arrow_map(&smart_map, MAXMAPCOLLUMS, MAXMAPROWS);

        if (IsKeyPressed('P'))
            insert_selected_plant(&plant_manager, &smart_map);

        select_plant_input(&plant_manager);

        // Drawing space
        BeginDrawing();

        ClearBackground(DARKGRAY);

        draw_game_grid(smart_map, textures, plant_manager.plants);
        draw_projectiles(projectiles, textures);

        plant_button_draw_manager(plant_manager, textures, 0);
        plant_button_draw_manager(plant_manager, textures, 1);

        sun_stack_draw(sun_button);

        EndDrawing();

    }

    CloseWindow();

    printf("Hello, World!\n");

    return 0;
}
