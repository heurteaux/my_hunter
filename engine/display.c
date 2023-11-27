/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** display.c
*/

#include <SFML/Graphics.h>
#include "../includes/structs/game_object.h"

void display_game_object_chain(sfRenderWindow *window, game_object *game_object_root)
{
    game_object *current_game_object = game_object_root->next;

    while (current_game_object != NULL) {
        current_game_object->display_game_object(window);
        current_game_object = current_game_object->next;
    }
}
