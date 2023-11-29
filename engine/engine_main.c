/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** engine_main.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/game_object.h"
#include "../includes/internal_functions.h"

void on_close_button_pressed(sfEvent game_events, sfRenderWindow *game_window)
{
    if (game_events.type == sfEvtClosed)
        sfRenderWindow_close(game_window);
}

sfSprite *get_background_sprite()
{
    sfTexture *texture =
        sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void set_sprite_scale(sfSprite *sprite, sfRenderWindow *game_window)
{
    float scale_x;
    float scale_y;
    float scale_factor;

    sfVector2u texture_size = sfTexture_getSize(sfSprite_getTexture(sprite));
    sfVector2u game_window_size = sfRenderWindow_getSize(game_window);

    scale_x = (float) game_window_size.x / (float) texture_size.x;
    scale_y = (float) game_window_size.y / (float) texture_size.y;
    scale_factor = (scale_x > scale_y) ? scale_x : scale_y;

    sfSprite_setScale(sprite, (sfVector2f){scale_factor, scale_factor});
}

game_object_t *init_linked_list()
{
    game_object_t *head = malloc(sizeof(game_object_t) * 1);
    head->next = NULL;
    head->type = HEAD;
    head->data = NULL;
    return head;
}

game_object_t *init_game_object(game_object_type_t type, void *data)
{
    game_object_t *result = malloc(sizeof(game_object_t) * 1);

    result->next = NULL;
    result->data = data;
    result->type = type;
    return result;
}

void linked_list_push(
    game_object_t *linked_list_head, void *data, game_object_type_t type)
{
    game_object_t *temp = linked_list_head;
    game_object_t *tail = init_game_object(type, data);

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = tail;
}

sfSprite *get_enemy_sprite(int x, int y)
{
    sfTexture *sprite_texture =
        sfTexture_createFromFile("assets/test_enemy.png", NULL);
    sfSprite *result = sfSprite_create();
    sfSprite_setTexture(result, sprite_texture, sfTrue);
    sfSprite_setPosition(result, (sfVector2f){(float) x, (float) y});
    return result;
}

void move_all_enemy(game_object_t *linked_list_head)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            ((enemy_object_t *) temp->data)->pos_y += 2;
            ((enemy_object_t *) temp->data)->pos_x += 2;
            sfSprite_setPosition(
                (sfSprite *) ((enemy_object_t *) temp->data)->sprite,
                (sfVector2f){(float) ((enemy_object_t *) temp->data)->pos_y,
                    (float) ((enemy_object_t *) temp->data)->pos_x});
        }
        temp = temp->next;
    }
}

void game_behaviour(game_object_t *linked_list_head,
    __attribute__((unused)) sfEvent event, sfTime main_time)
{
    double seconds = (double) main_time.microseconds / 1000000.0;
    enemy_object_t *new_enemy = malloc(sizeof(enemy_object_t) * 1);
    srand(time(NULL));

    if (seconds > 0.8 && rand() % 2 == 0) {
        new_enemy->pos_y = rand() % 1080;
        new_enemy->pos_x = -50;
        new_enemy->sprite =
            get_enemy_sprite(new_enemy->pos_y, new_enemy->pos_x);
        linked_list_push(linked_list_head, new_enemy, ENEMY);
    }
    move_all_enemy(linked_list_head);
}

void draw_game_objects(sfRenderWindow *game_window, game_object_t *linked_list_head)
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

void handle_displaying(sfRenderWindow *game_window, sfSprite *background, game_object_t *linked_list_head)
{
    sfRenderWindow_clear(game_window, sfBlack);
    sfRenderWindow_drawSprite(game_window, background, NULL);
    draw_game_objects(game_window, linked_list_head);
    sfRenderWindow_display(game_window);
}

void engine_main(void)
{
    sfTime time;
    sfClock *clock = sfClock_create();
    sfVideoMode game_window_video_mode = {1920, 1080, 16};
    sfEvent game_events;
    sfRenderWindow *game_window =
        sfRenderWindow_create(game_window_video_mode, "Hunter", sfClose, NULL);
    game_object_t *linked_list_game_objects = init_linked_list();
    sfSprite *background = get_background_sprite();

    sfRenderWindow_setFramerateLimit(game_window, 60);
    set_sprite_scale(background, game_window);
    while (sfRenderWindow_isOpen(game_window)) {
        time = sfClock_getElapsedTime(clock);
        while (sfRenderWindow_pollEvent(game_window, &game_events)) {
            game_behaviour(linked_list_game_objects, game_events, time);
            on_close_button_pressed(game_events, game_window);
        }
        handle_displaying(game_window, background, linked_list_game_objects);
    }
}
