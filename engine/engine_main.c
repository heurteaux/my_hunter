/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** engine_main.c
*/

#include <SFML/Graphics.h>
#include "../includes/structs/game_object.h"
#include "../includes/internal_functions.h"

const int FRAME_RATE = 60;

void on_close_button_pressed(sfEvent game_events, sfRenderWindow *game_window)
{
    if (game_events.type == sfEvtClosed)
        sfRenderWindow_close(game_window);
}

void engine_main(void)
{
    sfVideoMode game_window_video_mode = {1920, 1080, 16};
    sfEvent game_events;
    sfRenderWindow *game_window = sfRenderWindow_create(game_window_video_mode, "Hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game_window, FRAME_RATE);
    //void (*scene_function)(game_object *, sfEvent) = scene_01;
    game_object game_object_chain = (game_object){ROOT, NULL, NULL, NULL};

    while (sfRenderWindow_isOpen(game_window)) {
        while (sfRenderWindow_pollEvent(game_window, &game_events)) {
            //scene_function(&game_object_chain, game_events);
            on_close_button_pressed(game_events, game_window);
        }
        display_game_object_chain(game_window, &game_object_chain);
        sfRenderWindow_display(game_window);
    }
}
