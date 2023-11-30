/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** engine.c
*/

#include <SFML/Graphics.h>
#include "../includes/graphic.h"
#include "../includes/engine.h"

void on_close_button_pressed(sfEvent game_events, sfRenderWindow *game_window)
{
    if (game_events.type == sfEvtClosed)
        sfRenderWindow_close(game_window);
}

void display_and_mouse_pos(engine_variables_t *en_var)
{
    en_var->mouse_pos =
        sfMouse_getPositionRenderWindow(en_var->game_window);
    sfSprite_setPosition(en_var->cursor_sprite,
        (sfVector2f){(float) en_var->mouse_pos.x - 577 / 2 + 130,
            (float) en_var->mouse_pos.y - 270});
    handle_displaying(en_var->game_window, en_var->background,
        en_var->linked_list_game_objects, en_var);
}
