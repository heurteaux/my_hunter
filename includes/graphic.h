/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** graphic.h
*/

#pragma once

#include <SFML/Graphics.h>
#include "game_object.h"
#include "engine.h"

void set_sprite_scale(sfSprite *sprite, sfRenderWindow *game_window);

sfSprite *get_enemy_sprite(int x, int y, enemy_object_t *new_enemy);

void handle_displaying(sfRenderWindow *game_window, sfSprite *background,
    game_object_t *linked_list_head, engine_variables_t *en_var);
