/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** nbr_to_str.c
*/

#include <unistd.h>
#include <memory.h>
#include <stdlib.h>

static const int ZERO = 48;

static int get_diviseur(int len)
{
    int a = 1;

    for (int i = 0; i < len - 1; i++)
        a *= 10;
    return a;
}

void for_positive(int nb, int arg_length, long result_holder, char *result)
{
    for (int i = 0; i < arg_length; i++) {
        result_holder = nb / get_diviseur(arg_length - i) % 10 + 48;
        result[i] = result_holder;
    }
}

void for_negative(long nb, int arg_length, long result_holder, char *result)
{
    for (int i = 0; i < arg_length; i++) {
        result_holder = (nb * (-1)) / get_diviseur(arg_length - i) % 10 + 48;
        result[i + 1] = result_holder;
    }
}

static int int_length(int a)
{
    int div_res = a;
    int counter = 0;

    if (a < 0) {
        while (div_res != 0) {
            div_res = (div_res / 10);
            counter++;
        }
    } else {
        while (div_res != 0) {
            div_res = div_res / 10;
            counter++;
        }
    }
    return counter;
}

char *nbr_to_str(int nb_origin)
{
    int arg_length = int_length(nb_origin);
    long result_holder = 0;
    long nb = nb_origin;
    char *result = malloc(sizeof(char) * arg_length + 2);

    memset(result, 0, arg_length + 2);
    if (nb == 0) {
        result[0] = ZERO;
        return result;
    }
    if (nb > 0) {
        for_positive(nb, arg_length, result_holder, result);
    } else if (nb < 0) {
        result[0] = '-';
        for_negative(nb, arg_length, result_holder, result);
    }
    return result;
}
