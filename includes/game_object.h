/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_object.h
*/

#pragma once

#include <SFML/Graphics.h>

typedef enum game_object_type_s {
    ENEMY,
    HEAD
} game_object_type_t;

typedef struct game_object_s {
    void *data;
    game_object_type_t type;
    struct game_object_s *next;
} game_object_t;

typedef struct enemy_object_s {
    sfSprite *sprite;
    int pos_x;
    int pos_y;
    sfIntRect rect;
    sfTime time;
    sfClock *clock;
    sfTexture *texture;
} enemy_object_t;

void destroy_game_object(
    game_object_t *game_object, game_object_t *linked_list_head);
