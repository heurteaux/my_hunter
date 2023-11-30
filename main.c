/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/

#include <fcntl.h>
#include "includes/internal_functions.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

const char *HELP_MENU_TEXT_FILE_PATH = "assets/help_message";

static int my_putstr(char const *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++ ) {
        write(1, &str[i], 1);
    }
    return 0;
}

static char *get_file_content(const char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer;
    struct stat file_infos;

    if (fd == (-1))
        exit(84);
    stat(file_path, &file_infos);
    buffer = malloc(sizeof(char) * (file_infos.st_size + 1));
    for (int i = 0; i < (file_infos.st_size + 1); i++) {
        buffer[i] = 0;
    }
    read(fd, buffer, file_infos.st_size);
    return buffer;
}

static int help_menu(int argc, char **argv)
{
    char *file_content;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'h') {
            file_content = get_file_content(HELP_MENU_TEXT_FILE_PATH);
            my_putstr(file_content);
            free(file_content);
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
