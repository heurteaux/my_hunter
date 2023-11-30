/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** animate.c
*/

#include <SFML/Graphics.h>
#include "../includes/game_object.h"

static void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value) {
        rect->left = 0;
        return;
    }
    rect->left += offset;
}

static void animate(sfIntRect *rect, sfTime time, sfClock *clock)
{
    double seconds = (double) time.microseconds / 1000000.0;

    if (seconds > 0.2) {
        move_rect(rect, 892 / 6, 892 - (892 / 6));
        sfClock_restart(clock);
    }
}

void animate_all_enemy(game_object_t *linked_list_head)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            ((enemy_object_t *) temp->data)->time =
                sfClock_getElapsedTime(((enemy_object_t *) temp->data)->clock);
            animate(&((enemy_object_t *) temp->data)->rect,
                ((enemy_object_t *) temp->data)->time,
                ((enemy_object_t *) temp->data)->clock);
            sfSprite_setTextureRect(((enemy_object_t *) temp->data)->sprite,
                ((enemy_object_t *) temp->data)->rect);
        }
        temp = temp->next;
    }
}
