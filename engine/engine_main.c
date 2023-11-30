/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** engine_main.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../includes/engine.h"
#include "../includes/game.h"
#include "../includes/graphic.h"
#include "../includes/game_object.h"
#include "../includes/internal_functions.h"

void handle_displaying(sfRenderWindow *game_window, sfSprite *background,
    game_object_t *linked_list_head, engine_variables_t *en_var)
{
    sfRenderWindow_clear(game_window, sfBlack);
    sfRenderWindow_drawSprite(game_window, background, NULL);
    draw_game_objects(game_window, linked_list_head);
    sfRenderWindow_drawSprite(
        en_var->game_window, en_var->cursor_sprite, NULL);
    sfRenderWindow_drawText(en_var->game_window, en_var->score_text, NULL);
    sfRenderWindow_drawText(en_var->game_window, en_var->highscore_text, NULL);
    sfRenderWindow_display(en_var->game_window);
}

static void collision_check(sfEvent event, game_object_t *temp, int *score,
    game_object_t *linked_list_test)
{
    sfFloatRect spriteBounds;

    if (event.type == sfEvtMouseButtonPressed) {
        spriteBounds = sfSprite_getGlobalBounds(
            (sfSprite *) ((enemy_object_t *) temp->data)->sprite);
        if (event.mouseButton.x > spriteBounds.left
            && event.mouseButton.x < spriteBounds.left + spriteBounds.width
            && event.mouseButton.y > spriteBounds.top
            && event.mouseButton.y < spriteBounds.top + spriteBounds.height) {
            destroy_game_object(temp, linked_list_test);
            *score += 1;
        }
    }
}

void colision_detection(
    sfEvent event, game_object_t *linked_list_head, int *score)
{
    game_object_t *temp = linked_list_head;

    while (temp != NULL) {
        if (temp->type == ENEMY) {
            collision_check(event, temp, score, linked_list_head);
        }
        temp = temp->next;
    }
}

engine_variables_t *init_engine_var(void)
{
    engine_variables_t *en_var = malloc(sizeof(engine_variables_t));

    en_var->music = sfMusic_createFromFile("assets/music.ogg");
    en_var->clock = sfClock_create();
    en_var->game_window_video_mode = (sfVideoMode){1920, 1080, 16};
    en_var->game_window = sfRenderWindow_create(
        en_var->game_window_video_mode, "Hunter", sfClose, NULL);
    en_var->linked_list_game_objects = init_linked_list();
    en_var->background = get_background_sprite();
    en_var->cursor_texture =
        sfTexture_createFromFile("assets/cursor.png", NULL);
    en_var->cursor_sprite = sfSprite_create();
    sfSprite_setTexture(en_var->cursor_sprite, en_var->cursor_texture, true);
    sfRenderWindow_setMouseCursorVisible(en_var->game_window, false);
    sfRenderWindow_setFramerateLimit(en_var->game_window, 60);
    set_sprite_scale(en_var->background, en_var->game_window);
    sfMusic_setLoop(en_var->music, sfTrue);
    sfMusic_play(en_var->music);
    return en_var;
}

static void setup_engine_var(engine_variables_t *en_var)
{
    en_var->score_font = sfFont_createFromFile("assets/font.ttf");
    en_var->score_text = sfText_create();
    sfText_setFont(en_var->score_text, en_var->score_font);
    sfText_setCharacterSize(en_var->score_text, 50);
    sfText_setPosition(en_var->score_text, (sfVector2f){1500, 0});
    en_var->highscore_text = sfText_create();
    sfText_setFont(en_var->highscore_text, en_var->score_font);
    sfText_setCharacterSize(en_var->highscore_text, 50);
    sfText_setPosition(en_var->highscore_text, (sfVector2f){1333, 70});
    en_var->rate_increment = 0;
    en_var->speed_increment = 0;
    en_var->score = 0;
}

void engine_main(void)
{
    engine_variables_t *en_var = init_engine_var();

    setup_engine_var(en_var);
    while (sfRenderWindow_isOpen(en_var->game_window)) {
        en_var->time = sfClock_getElapsedTime(en_var->clock);
        game_behaviour(en_var);
        while (sfRenderWindow_pollEvent(
            en_var->game_window, &en_var->game_events)) {
            on_close_button_pressed(en_var->game_events, en_var->game_window);
            colision_detection(en_var->game_events,
                en_var->linked_list_game_objects, &en_var->score);
            handle_score(en_var);
        }
        display_and_mouse_pos(en_var);
    }
    sfRenderWindow_destroy(en_var->game_window);
}
