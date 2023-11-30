/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_object.c
*/

#include "../includes/game_object.h"
#include <stdlib.h>

game_object_t *init_game_object(game_object_type_t type, void *data)
{
    game_object_t *result = malloc(sizeof(game_object_t) * 1);

    result->next = NULL;
    result->data = data;
    result->type = type;
    return result;
}

void draw_game_objects(
    sfRenderWindow *game_window, game_object_t *linked_list_head)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            sfRenderWindow_drawSprite(game_window,
                (sfSprite *) ((enemy_object_t *) temp->data)->sprite, NULL);
        }
        temp = temp->next;
    }
}
