/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator.c
*/

#include "generator.h"

int convert_print(info_t *info, int i, int j)
{
    if (info->maze[i][j] == 0)
        printf("*");
    if (info->maze[i][j] == 1)
        printf("X");
    if (i != info->height - 1)
        if (info->maze[i][j] == -1)
            printf("\n");
    return (0);
}

int go_rand(link_t **link)
{
    int pos = 0;
    int len = 0;

    len = my_linklen(link);
    pos = rand() % len;
    return (pos);
}

int free_all(info_t *info, int ac)
{
    for (int i = 0; info->maze[i]; i++)
        free(info->maze[i]);
    free(info->maze);
    if (ac == 4)
        free(info->type);
    free(info);
    return (0);
}