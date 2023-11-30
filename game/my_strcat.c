/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** task02
*/

#include <memory.h>
#include <stdlib.h>
#include "../includes/internal_functions.h"

char *my_strcat(char *dest, char const *src)
{
    char *result = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 2);
    int i = 0;
    int n = 0;

    memset(result, 0, my_strlen(dest) + my_strlen(src) + 2);
    my_strcpy(result, dest);
    while (result[i] != '\0') {
        i++;
    }
    while (src[n] != '\0') {
        result[n + i] = src[n];
        n++;
    }
    result[n + i + 1] = '\0';
    return result;
}
