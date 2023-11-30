/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** linked_list.c
*/

#include "../includes/game_object.h"
#include "../includes/engine.h"
#include <stdlib.h>

game_object_t *init_linked_list(void)
{
    game_object_t *head = malloc(sizeof(game_object_t) * 1);

    head->next = NULL;
    head->type = HEAD;
    head->data = NULL;
    return head;
}

void linked_list_push(
    game_object_t *linked_list_head, void *data, game_object_type_t type)
{
    game_object_t *temp = linked_list_head;
    game_object_t *tail = init_game_object(type, data);

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = tail;
}
