/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game.h
*/

#pragma once

#include "../includes/game_object.h"

void game_behaviour(game_object_t *linked_list_head,
    __attribute__((unused)) sfEvent event, sfTime main_time, sfClock *clock);

sfSprite *get_background_sprite(void);
