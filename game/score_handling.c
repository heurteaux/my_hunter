/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** score_handling.c
*/

#include <SFML/Graphics.h>
#include "../includes/engine.h"
#include "../includes/internal_functions.h"
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>

static int get_highest_score(void)
{
    int fd = open("save/highscore", O_CREAT);
    char *buffer = malloc(sizeof(char) * 10000);

    memset(buffer, 0, 10000);
    read(fd, buffer, 10000);
    return my_getnbr(buffer);
}

static void save_score(int score)
{
    char *to_str = malloc(sizeof(char) * 10000);
    int fd;

    memset(to_str, 0, 10000);
    to_str = nbr_to_str(score);
    fd = open("save/highscore", O_WRONLY | O_CREAT, 0644);
    write(fd, to_str, my_strlen(to_str));
    close(fd);
}

void handle_score(engine_variables_t *en_var)
{
    char *base_text = "Score : ";
    char *highscore_base_text = "Highscore : ";
    int highest_score = get_highest_score();

    sfText_setString(
        en_var->score_text, my_strcat(base_text, nbr_to_str(en_var->score)));
    if (highest_score > 0)
        sfText_setString(en_var->highscore_text,
            my_strcat(highscore_base_text, nbr_to_str(highest_score)));
    else
        sfText_setString(
            en_var->highscore_text, "Highscore : 0 \n(skill issue)");
    if (en_var->score > highest_score) {
        save_score(en_var->score);
    }
}
