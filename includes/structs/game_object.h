/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_object.h
*/

#pragma once
#include <SFML/Graphics.h>

enum game_object_type {
    ROOT,
    ENNEMY,
    BACKGROUND,
    PLAYER_CURSOR,
};

typedef struct game_object_t{
    enum game_object_type type;
    void *value;
    struct game_object_t *next;
    void (*display_game_object)(sfRenderWindow *game_window);
} game_object;
