/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** check_enemy_out.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "../includes/engine.h"
#include "../includes/game_object.h"

static void inner_cond(engine_variables_t *en_var, game_object_t *temp,
    game_object_t *linked_list_head)
{
    if (sfSprite_getPosition(
            (sfSprite *) ((enemy_object_t *) temp->data)->sprite)
            .y
        >= 1080) {
        en_var->life -= 1;
        destroy_game_object(temp, linked_list_head);
    }
}

void check_enemy_out(
    game_object_t *linked_list_head, engine_variables_t *en_var)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            inner_cond(en_var, temp, linked_list_head);
        }
        temp = temp->next;
    }
}
