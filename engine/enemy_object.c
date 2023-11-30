/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** enemy_object.c
*/

#include "../includes/game_object.h"
#include <stdlib.h>

void destroy_enemy_object(enemy_object_t *enemy_object)
{
    sfTexture_destroy(enemy_object->texture);
    sfSprite_destroy(enemy_object->sprite);
    sfClock_destroy(enemy_object->clock);
    free(enemy_object);
}
