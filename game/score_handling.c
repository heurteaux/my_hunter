/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** score_handling.c
*/

#include <SFML/Graphics.h>
#include "../includes/engine.h"
#include "../includes/internal_functions.h"

void handle_score(engine_variables_t *en_var)
{
    char *base_text = "Score : ";

    sfText_setString(
        en_var->score_text, my_strcat(base_text, nbr_to_str(en_var->score)));
}
