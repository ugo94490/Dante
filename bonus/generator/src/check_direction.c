/*
** EPITECH PROJECT, 2019
** generator
** File description:
** check_direction.c
*/

#include "generator.h"

int choose_dir(int **maze, int x, int y, info_t *info)
{
    int direction = -1;
    char **tab = NULL;

    if (x + 2 < info->height)
        if (maze[x + 2][y] == 1)
            tab = tab_realloc(tab, strdup("1"));
    if (x - 2 >= 0)
        if (maze[x - 2][y] == 1)
            tab = tab_realloc(tab, strdup("2"));
    if (y + 2 < info->width)
        if (maze[x][y + 2] == 1)
            tab = tab_realloc(tab, strdup("3"));
    if (y - 2 >= 0)
        if (maze[x][y - 2] == 1)
            tab = tab_realloc(tab, strdup("4"));
    if (my_strlen_tab(tab) == 0)
        return (-1);
    direction = atoi(tab[rand() % my_strlen_tab(tab)]);
    my_free_tab(tab, 0);
    return (direction);
}

void which_way(link_t **link, info_t *info, int dir)
{
    if (dir == 1) {
        dir == 1 ? info->maze[(*link)->x + 1][(*link)->y] = 0,
    info->maze[(*link)->x + 2][(*link)->y] = 0 : 0;
        link_end(link, (*link)->x + 2, (*link)->y);
    }
    if (dir == 2) {
        dir == 2 ? info->maze[(*link)->x - 1][(*link)->y] = 0,
    info->maze[(*link)->x - 2][(*link)->y] = 0 : 0;
        link_end(link, (*link)->x - 2, (*link)->y);
    }
    if (dir == 3) {
        dir == 3 ? info->maze[(*link)->x][(*link)->y + 1] = 0,
    info->maze[(*link)->x][(*link)->y + 2] = 0 : 0;
        link_end(link, (*link)->x, (*link)->y + 2);
    }
    if (dir == 4) {
        dir == 4 ? info->maze[(*link)->x][(*link)->y - 1] = 0,
    info->maze[(*link)->x][(*link)->y - 2] = 0 : 0;
        link_end(link, (*link)->x, (*link)->y - 2);
    }
}

int check_one(link_t **link, info_t *info)
{
    int dir = choose_dir(info->maze, (*link)->x, (*link)->y, info);

    which_way(link, info, dir);
    if (dir == -1) {
        if (my_linklen(link) == 1)
            return (-2);
        if ((*link)->next == NULL) {
            (*link) = (*link)->prev;
            free((*link)->next);
            (*link)->next = NULL;
        } else if ((*link)->next != NULL && (*link)->prev == NULL) {
            (*link) = (*link)->next;
            free((*link)->prev);
        } else if ((*link)->next != NULL && (*link)->prev != NULL) {
            (*link) = (*link)->next;
            (*link)->prev->prev->next = (*link);
            (*link)->prev = (*link)->prev->prev;
        }
        return (-1);
    }
    return (0);
}
