/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** game_logic.c
*/

#include <SFML/Graphics.h>
#include "../includes/game_object.h"
#include "../includes/graphic.h"
#include "../includes/engine.h"
#include <stdlib.h>

sfSprite *get_background_sprite(void)
{
    sfTexture *texture =
        sfTexture_createFromFile("assets/background.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void move_all_enemy(game_object_t *linked_list_head)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            ((enemy_object_t *) temp->data)->pos_y += 7;
            ((enemy_object_t *) temp->data)->pos_x += 7;
            ((enemy_object_t *) temp->data)->pos_x += 7;
            sfSprite_setPosition(
                (sfSprite *) ((enemy_object_t *) temp->data)->sprite,
                (sfVector2f){(float) ((enemy_object_t *) temp->data)->pos_y,
                    (float) ((enemy_object_t *) temp->data)->pos_x});
        }
        temp = temp->next;
    }
}

void game_behaviour(game_object_t *linked_list_head,
    __attribute__((unused)) sfEvent event, sfTime main_time, sfClock *clock)
{
    double seconds = (double) main_time.microseconds / 1000000.0;
    enemy_object_t *new_enemy = malloc(sizeof(enemy_object_t) * 1);

    srand(main_time.microseconds);
    if (seconds > 0.6 && rand() % 2 == 0) {
        new_enemy->pos_y = rand() % 1080;
        new_enemy->pos_x = -100;
        new_enemy->rect = (sfIntRect){0, 0, 892 / 6, 94};
        new_enemy->sprite =
            get_enemy_sprite(new_enemy->pos_x, new_enemy->pos_y);
        linked_list_push(linked_list_head, new_enemy, ENEMY);
        sfClock_restart(clock);
        new_enemy->clock = sfClock_create();
    }
    move_all_enemy(linked_list_head);
    animate_all_enemy(linked_list_head);
}
