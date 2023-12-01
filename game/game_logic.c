/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_logic.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/engine.h"
#include "../includes/graphic.h"
#include "../includes/game.h"

sfSprite *get_background_sprite(void)
{
    sfTexture *texture =
        sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void move_all_enemy(
    game_object_t *linked_list_head, float speed_increment)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            ((enemy_object_t *) temp->data)->pos_y += 7 + speed_increment;
            ((enemy_object_t *) temp->data)->pos_x += 7 + speed_increment;
            ((enemy_object_t *) temp->data)->pos_x += 7 + speed_increment;
            sfSprite_setPosition(
                (sfSprite *) ((enemy_object_t *) temp->data)->sprite,
                (sfVector2f){(float) ((enemy_object_t *) temp->data)->pos_y,
                    (float) ((enemy_object_t *) temp->data)->pos_x});
        }
        temp = temp->next;
    }
}

void game_behaviour(engine_variables_t *en_var)
{
    double seconds = (double) en_var->time.microseconds / 1000000.0;
    enemy_object_t *new_enemy = malloc(sizeof(enemy_object_t) * 1);

    check_enemy_out(en_var->linked_list_game_objects, en_var);
    srand(en_var->time.microseconds);
    if (seconds > 0.6 - en_var->rate_increment && rand() % 3 == 0) {
        new_enemy->pos_y = rand() % 1080;
        new_enemy->pos_x = -100;
        new_enemy->rect = (sfIntRect){0, 0, 892 / 6, 94};
        new_enemy->sprite =
            get_enemy_sprite(new_enemy->pos_x, new_enemy->pos_y, new_enemy);
        linked_list_push(en_var->linked_list_game_objects, new_enemy, ENEMY);
        sfClock_restart(en_var->clock);
        new_enemy->clock = sfClock_create();
        en_var->rate_increment += 0.002;
        en_var->speed_increment += 0.001;
    }
    move_all_enemy(en_var->linked_list_game_objects, en_var->speed_increment);
    animate_all_enemy(en_var->linked_list_game_objects);
}
