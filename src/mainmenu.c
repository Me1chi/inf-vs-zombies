#include "buttons.h"
#include "raylib.h"
#include "structs.h"
#include "mainmenu.h"
#include "game.h"
#include <stdbool.h>

void game_screen_manage(int *screen_selector, GameTextures textures, Button *menu_buttons) {

    int screen_was = *screen_selector;

    if (*screen_selector == 0) {
        EndDrawing();
    }

    while (*screen_selector == 0) {
        *screen_selector = main_menu(textures, menu_buttons);
    }

    if (screen_was == 0 && *screen_selector != 0) {
        BeginDrawing();
    }

}

// Possible returns: 0: Main menu still, 1: The game starts, 2: Leaderboard, 3: The game closes
int main_menu(GameTextures textures, Button *menu_buttons) {
    
    BeginDrawing();

    // Background logic and drawing
    Button menu_background_button = {
        (Vector2) {0.0, 0.0},
        (Vector2) {SCREENWIDTH, SCREENHEIGHT},
        textures.menu_background,
        "",
        BLACK,
        false
    };

    button_draw_texture(menu_background_button, 1);   

    // Buttons logic and drawing
    // The menu_buttons array is assumed to have exactly 3 items. (BE SURE OF IT)
    
    for(int i = 0; i < MENUBUTTONSCOUNT; i++) {
        button_draw_texture(menu_buttons[i], 1);
    }

    if (menu_buttons[0].selected) {
        if (IsKeyPressed(KEY_DOWN)) {
            menu_buttons[1].selected = true;
            menu_buttons[0].selected = false;
        } else if (IsKeyPressed(KEY_ENTER)) {
            return 1;
        }
    } else if (menu_buttons[1].selected) {
        if (IsKeyPressed(KEY_UP)) {
            menu_buttons[0].selected = true;
            menu_buttons[1].selected = false;
        } else if (IsKeyPressed(KEY_DOWN)) {
            menu_buttons[2].selected = true;
            menu_buttons[1].selected = false;
        } else if (IsKeyPressed(KEY_ENTER)) {
            return 2;
        }
    } else if (menu_buttons[2].selected) {
        if (IsKeyPressed(KEY_UP)) {
            menu_buttons[1].selected = true;
            menu_buttons[2].selected = false;
        } else if (IsKeyPressed(KEY_ENTER)) {
            return 3;
        }
    }

    EndDrawing();

    return 0;
}


