/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** sprites.c
*/

#include <SFML/Graphics.h>

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

sfSprite *get_enemy_sprite(int x, int y)
{
    sfTexture *sprite_texture =
        sfTexture_createFromFile("assets/nyan_cat.png", NULL);
    sfSprite *result = sfSprite_create();

    sfSprite_setTexture(result, sprite_texture, sfTrue);
    sfSprite_setPosition(result, (sfVector2f){(float) x, (float) y});
    return result;
}
