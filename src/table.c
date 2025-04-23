#include "table.h"
#include "plants.h"
#include "raylib.h"
#include "structs.h"
#include "game.h"
#include "buttons.h"
#include <stdbool.h>
#include <stdio.h>

SmartMap initialize_smart_map(int size_x, int size_y) {
    SmartMap smart_map = {0};

    smart_map.selected_row = 0;
    smart_map.selected_col = 0;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            smart_map.map[i][j] = 'G';
            smart_map.timer[i][j] = 0.0;
        }
    }

    return smart_map;
}

void draw_game_grid(SmartMap smart_map, GameTextures textures, Plant* plants) {

    char plant_code = '\0';
    int div_mod_ij = 0;
    Plant plant_to_draw;

    Vector2 starting_position = {
        BIGBLANKSPACE,
        THEGAMEBELOWTHAT + BIGBLANKSPACE
    };

    Vector2 tile_size = {3*PLANTSPRITESIZE, 3*PLANTSPRITESIZE};
    Vector2 plant_size = tile_size;

    float line_thickness = 2*SCREENWIDTH/BUTTONLINETHICKNESSDIV;

    Button tile = {
        starting_position,
        tile_size,
        textures.grass[div_mod_ij],
        "",
        BLACK,
        false,
    };

    Button plant_button = {
        starting_position,
        plant_size,
        textures.grass[div_mod_ij],
        "",
        BLACK,
        false,
    };

    for (int i = 0; i < MAXMAPROWS; i++) {
        for (int j = 0; j < MAXMAPCOLLUMS; j++) {

            bool draw_box = false;

            if (smart_map.selected_row == i && smart_map.selected_col == j) {
                draw_box = true;
            }

            div_mod_ij = (i + j)%2;

            tile.position.x = starting_position.x + j*plant_size.x;
            tile.position.y = starting_position.y + i*plant_size.y;

            tile.texture = textures.grass[div_mod_ij];

            button_draw_texture(tile, TEXTTOBUTTONSIZE);

            switch (smart_map.map[i][j]) {
                case 'G':


                    break;

                default:
                    if (parse_plant(smart_map.map[i][j], plants, &plant_to_draw) == 1) {
                        plant_button.texture = plant_to_draw.texture;
                    }

                    plant_button.position.x = tile.position.x;
                    plant_button.position.y = tile.position.y;

                    button_draw_texture(plant_button, TEXTTOBUTTONSIZE);

                    plant_button.texture = textures.grass[div_mod_ij];
                    break;
            }

            if (draw_box) {
                DrawRectangleLinesEx(get_button_rect(tile), line_thickness, BLACK);
            }
        }
    }

}
