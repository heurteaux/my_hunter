/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** internal_functions.h
*/

#pragma once
#include "../includes/structs/game_object.h"
#include <SFML/Graphics.h>

void engine_main(void);

void display_game_object_chain(sfRenderWindow *window, game_object *game_object_root);
