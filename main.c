/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/

#include "includes/internal_functions.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

static int my_putstr(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++ ) {
        write(1, &str[i], 1);
    }
    return 0;
}

static int help_menu(int argc, char **argv)
{
    int fd = open("assets/help_text", O_RDONLY);
    char *buffer[10000] = {0};

    read(fd, buffer, 10000);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'h') {
            my_putstr((const char *)buffer);
        }
    }
    return 0;
}

bool is_help_menu_requested(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return true;
    return false;
}

int main(int argc, char **argv)
{
    if (is_help_menu_requested(argc, argv)) {
        help_menu(argc, argv);
        return 0;
    }
    engine_main();
    return 0;
}
