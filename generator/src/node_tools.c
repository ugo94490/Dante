/*
** EPITECH PROJECT, 2019
** generator
** File description:
** node_tools.c
*/

#include "generator.h"

void link_end(link_t **start, int x, int y)
{
    link_t *new_node = malloc(sizeof(link_t));

    if (!new_node)
        return;
    if (*start == NULL) {
        new_node->x = x;
        new_node->y = y;
        new_node->next = NULL;
        new_node->prev = NULL;
        *start = new_node;
    } else {
        while ((*start)->next != NULL) {
            (*start) = (*start)->next;
        }
        new_node->prev = (*start);
        (*start)->next = new_node;
        new_node->x = x;
        new_node->y = y;
        new_node->next = NULL;
    }
}

link_t *init_link(int y, int x)
{
    link_t *link = malloc(sizeof(*link));

    link->x = x;
    link->y = y;
    link->next = NULL;
    link->prev = NULL;
    return (link);
}

int my_linklen(link_t **link)
{
    link_t *tmp = (*link);
    int i = 1;

    if (!tmp)
        return (0);
    while (tmp->prev != NULL)
        tmp = tmp->prev;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void add_link(link_t **link, int x, int y)
{
    (*link)->next = malloc(sizeof(link_t));
    (*link)->next->prev = (*link);
    (*link) = (*link)->next;
    (*link)->next = NULL;
    (*link)->x = x;
    (*link)->y = y;
}