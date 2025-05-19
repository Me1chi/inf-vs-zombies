#include "buttons.h"
#include "game.h"
#include "map.h"
#include "plants.h"
#include "plantsbar.h"
#include "raylib.h"
#include "structs.h"
#include "table.h"
#include "textures.h"
#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include "mainmenu.h"
#include "zombies.h"

int main(void) {

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "INF vs Zombies");

    int sun_stack = 100;
    int total_zombies = 20;

    int screen_selector = 0;

    SmartMap smart_map = initialize_smart_map(MAXMAPROWS, MAXMAPCOLLUMS);

    GameTextures textures = {0};
    PlantManager plant_manager = {0};
    Button menu_buttons[3] = {0};
    Zombie zombies[20] = {0};

    for (int i = 0; i < 20; i++) {
        zombies[i] = (Zombie){
            0,
            -10*SCREENHEIGHT,
            10*SCREENWIDTH,
            false,
        };
    }

    plant_manager_mapping(&plant_manager);
    load_general_textures(&textures);

    Texture2D background = LoadTexture("../resources/textures/background.png");

    Projectile base_proj = {
        (Vector2){-SCREENWIDTH, -SCREENHEIGHT},
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
        SCREENWIDTH / 8,
        SCREENHEIGHT / 6,
    };

    Button my_button = {
        (Vector2){SCREENWIDTH / 4 - button_size.x / 2,
                  THEGAMEBELOWTHAT - button_size.y / 1.5},
        button_size,
        textures.button,
        "",
        BLUE,
        false,
    };

    Button sunflower_button = {
        (Vector2){SCREENWIDTH / 4 + button_size.x / 2 + SMALLBLANKSPACE,
                  THEGAMEBELOWTHAT - button_size.y / 1.5},
        button_size,
        textures.button,
        "",
        BLUE,
        false,
    };

    Button sun_button = {
        (Vector2){SCREENWIDTH / 4 - 3 * button_size.x / 2,
                  THEGAMEBELOWTHAT - button_size.y / 1.5},
        button_size,
        textures.sun,
        "1000",
        BLACK,
        false,
    };

    plant_manager.plants_bar[0] = my_button;
    plant_manager.plants_bar[1] = sunflower_button;

    Vector2 main_menu_button_size = {SCREENWIDTH/2, SCREENHEIGHT/4};
    Vector2 main_menu_button_pos = {
        SCREENWIDTH/2 - main_menu_button_size.x/2,
        SCREENHEIGHT/3 - main_menu_button_size.y/2,
    };

    menu_buttons[0] = (Button) {
        main_menu_button_pos,
        main_menu_button_size,
        textures.menu_play_button,
        "",
        BLACK,
        true,
    };

    main_menu_button_pos.y += main_menu_button_size.y;
 
    menu_buttons[1] = (Button) {
        main_menu_button_pos,
        main_menu_button_size,
        textures.menu_leaderboard_button,
        "",
        BLACK,
        false,
    };

    main_menu_button_pos.y += main_menu_button_size.y;

    menu_buttons[2] = (Button) {
        main_menu_button_pos,
        main_menu_button_size,
        textures.menu_exit_button,
        "",
        BLACK,
        false,
    };

    while (!WindowShouldClose() && screen_selector != 3) {
        // Game update space
        all_plants_shoot(plant_manager.plants, &projectiles, &smart_map);
        update_plant_timer(&plant_manager);
        update_projectiles(&projectiles, &sun_stack);
        sprintf(sun_button.text, "%d", sun_stack);

        navigate_arrow_map(&smart_map, MAXMAPCOLLUMS, MAXMAPROWS);

        if (IsKeyPressed(KEY_SPACE))
            insert_selected_plant(&plant_manager, &smart_map, &sun_stack);

        select_plant_input(&plant_manager, sun_stack);

        screen_selector = zombies_walk(total_zombies, zombies, screen_selector);
        zombie_spawn(total_zombies, zombies);

        zombies_bite(&smart_map, zombies, total_zombies);
        zombies_damage_take(&projectiles, zombies, total_zombies);

        // Drawing space
        BeginDrawing();

        ClearBackground(DARKGRAY);

        // TESTING AREA ALERT TESTING THINGS HERE

        Rectangle source_back = {
            0,
            0,
            background.width,
            background.height,
        };

        Rectangle dest_back = {
            0,
            0,
            SCREENWIDTH,
            SCREENHEIGHT,
        };

        Vector2 origin_back = {
            0,
            0,
        };

        DrawTexturePro(background, source_back, dest_back, origin_back, 0.0,
                       WHITE);

        // END OF THE TESTING AREA FROM NOW THE PROGRAM IS WORKING PROPERLY
        draw_game_grid(smart_map, textures, plant_manager.plants);
        draw_projectiles(projectiles, textures);
        
        zombies_draw(textures, zombies, total_zombies);

        plant_button_draw_manager(plant_manager, textures, 0);
        plant_button_draw_manager(plant_manager, textures, 1);

        sun_stack_draw(sun_button);

        game_screen_manage(&screen_selector, textures, menu_buttons);

        EndDrawing();
    }

    CloseWindow();

    printf("Hello, World!\n");

    return 0;
}
