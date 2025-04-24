#include "buttons.h"
#include "game.h"
#include "raylib.h"
#include "structs.h"

Rectangle get_button_rect(Button button) {
    return (Rectangle){
        button.position.x,
        button.position.y,
        button.size.x,
        button.size.y,
    };
}

void draw_centralized_text(Button button, float text_scale) {

    float font_size = button.size.y * text_scale;

    Vector2 text_size =
        MeasureTextEx(GetFontDefault(), button.text, font_size, 3);

    button.position.x += button.size.x / 2.0 - text_size.x / 2.0;
    button.position.y += button.size.y / 2.0 - text_size.y / 2.0;

    DrawTextEx(GetFontDefault(), button.text, button.position, font_size, 3,
               button.text_color);
}

void button_draw(Button button, Color color, float text_scale) {

    Rectangle button_rec = {
        button.position.x,
        button.position.y,
        button.size.x,
        button.size.y,
    };

    float delta = SCREENWIDTH / BUTTONLINETHICKNESSDIV;

    // button highlight and click
    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, BLACK);

    button_rec.x += delta;
    button_rec.y += delta;
    button_rec.width -= 2 * delta;
    button_rec.height -= 2 * delta;

    DrawRectangleRounded(button_rec, STDBUTTONCURVE, 10, color);

    // button text drawing
    draw_centralized_text(button, text_scale);
}

void button_draw_texture(Button button, float text_scale) {

    Rectangle button_rect = get_button_rect(button);
    Rectangle rect_source = {
        0.0f,
        0.0f,
        button.texture.width,
        button.texture.height,
    };

    Vector2 origin = {0, 0};

    if (button.selected)
        DrawTexturePro(button.texture, rect_source, button_rect, origin, 0.0f,
                       GRAY);
    else
        DrawTexturePro(button.texture, rect_source, button_rect, origin, 0.0f,
                       WHITE);

    draw_centralized_text(button, text_scale);
}

void navigate_arrow_map(SmartMap *smart_map, int map_length, int map_heigth) {
    if (IsKeyPressed(KEY_LEFT) && smart_map->selected_col > 0) {
        smart_map->selected_col--;

    } else if (IsKeyPressed(KEY_RIGHT) &&
               smart_map->selected_col < map_length - 1) {
        smart_map->selected_col++;
    }

    if (IsKeyPressed(KEY_UP) && smart_map->selected_row > 0) {
        smart_map->selected_row--;

    } else if (IsKeyPressed(KEY_DOWN) &&
               smart_map->selected_row < map_heigth - 1) {
        smart_map->selected_row++;
    }
}
