#include "buttons.h"
#include "raylib.h"
#include "structs.h"
#include "mainmenu.h"
#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Possible returns: 0: Main menu still, 1: The game starts, 2: Leaderboard, 3: The game closes
int main_menu(GameTextures textures, Button *menu_buttons) {
    
    BeginDrawing();

    ClearBackground(DARKGRAY);

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

int leaderboard(GameTextures textures/*AQUI vai precisar colocar um array dos top players*/) {

    //AQUI EU VO SIMULAR O ARRAY DOS TOP PLAYERS 
    TopPlayer top_players[MAXTOPPLAYERS] = {
        {"Grohe", 880},
        {"Suarez", 750},
        {"Geromel", 610},
        {"Kleber", 510},
        {"M. Moreno", 470},
    };

    BeginDrawing();
    
    Vector2 leaderboard_pos = {
        SCREENWIDTH/8,
        SCREENHEIGHT/8, 
    };

    Vector2 leaderboard_size = {
        SCREENWIDTH - 2*leaderboard_pos.x,
        SCREENHEIGHT - 2*leaderboard_pos.y,
    };

    Button leaderboard_button = {
        leaderboard_pos,
        leaderboard_size,
        textures.leaderboard,
        "",
        BLACK,
        false
    }; 

    button_draw_texture(leaderboard_button, 1);

    leaderboard_button.position.x *= 2.10;
    leaderboard_button.position.y *= 3.50;
    
    leaderboard_button.size.x *= 0.70;
    leaderboard_button.size.y *= 0.075;

    for (int i = 0; i < MAXTOPPLAYERS; i++) {
        strcpy(leaderboard_button.text, top_players[i].text);
        char score[16] = {0};
        sprintf(score, "    %4d", top_players[i].score);
        strcat(leaderboard_button.text, score);

        draw_centralized_text(leaderboard_button, 1);

        leaderboard_button.position.y += leaderboard_button.size.y;
    }

    EndDrawing();

    if (IsKeyPressed(KEY_M)) {
        return 0; 
    }

    return 2;
}


void game_screen_manage(int *screen_selector, GameTextures textures, Button *menu_buttons) {

    int screen_was = *screen_selector;

    // Function piece to test and open the menu
    if (*screen_selector == 0) {
        EndDrawing();
    }

    while (*screen_selector == 0) {
        *screen_selector = main_menu(textures, menu_buttons);
    }

    if (screen_was == 0 && *screen_selector != 0) {
        BeginDrawing();
    }

    // Piece to change from the game to the menu
    if (*screen_selector == 1 && IsKeyDown(KEY_TAB)) {
        *screen_selector = 0;
    }

    if (*screen_selector == 2) {
        EndDrawing();

        while (*screen_selector == 2) {
            *screen_selector = leaderboard(textures);
        }

        BeginDrawing();
    }

}




