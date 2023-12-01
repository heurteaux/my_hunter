/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_over.c
*/

#include "../includes/engine.h"
#include <stdbool.h>

void game_over(engine_variables_t *en_var)
{
    sfText *game_over = sfText_create();

    sfText_setFont(game_over, en_var->score_font);
    sfText_setCharacterSize(game_over, 150);
    sfText_setPosition(game_over, (sfVector2f){425, 1080 / 2 - 100});
    sfText_setString(game_over, "GAME OVER !");
    sfText_setColor(game_over, sfRed);
    sfRenderWindow_setMouseCursorVisible(en_var->game_window, true);
    while (sfRenderWindow_isOpen(en_var->game_window)) {
        while (sfRenderWindow_pollEvent(
            en_var->game_window, &en_var->game_events)) {
            on_close_button_pressed(en_var->game_events, en_var->game_window);
        }
        sfRenderWindow_drawText(en_var->game_window, game_over, NULL);
        sfRenderWindow_display(en_var->game_window);
    }
}
