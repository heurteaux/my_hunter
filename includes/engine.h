/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** engine.h
*/

#pragma once

#include <SFML/Audio.h>
#include "../includes/game_object.h"

typedef struct engine_variables_s {
    sfTime time;
    sfMusic *music;
    sfClock *clock;
    sfVideoMode game_window_video_mode;
    sfEvent game_events;
    sfRenderWindow *game_window;
    game_object_t *linked_list_game_objects;
    sfSprite *background;
    sfTexture *cursor_texture;
    sfSprite *cursor_sprite;
    sfVector2i mouse_pos;
    float speed_increment;
    float rate_increment;
    int score;
} engine_variables_t;

void animate_all_enemy(game_object_t *linked_list_head);

game_object_t *init_game_object(game_object_type_t type, void *data);

game_object_t *init_linked_list(void);

void linked_list_push(
    game_object_t *linked_list_head, void *data, game_object_type_t type);

void on_close_button_pressed(sfEvent game_events, sfRenderWindow *game_window);

void draw_game_objects(
    sfRenderWindow *game_window, game_object_t *linked_list_head);

void display_and_mouse_pos(engine_variables_t *en_var);

void destroy_enemy_object(enemy_object_t *enemy_object);
