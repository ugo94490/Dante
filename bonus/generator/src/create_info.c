/*
** EPITECH PROJECT, 2019
** generator
** File description:
** create_maze.c
*/

#include "generator.h"

int **alloc_maze(info_t *info)
{
    int **maze = malloc(sizeof(int *) * (info->height + 1));

    for (int i = 0; i < info->height; i++)
        maze[i] = malloc(sizeof(int) * (info->width + 1));
    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width; j++) {
            maze[i][j] = 1;
            maze[i][info->width] = -1;
        }
    maze[info->height] = NULL;
    return (maze);
}

void init_info(info_t *info, char **av, int ac)
{
    int value_1 = 0;
    int value_2 = 0;

    info->width = atoi(av[1]);
    info->height = atoi(av[2]);
    info->x = 0;
    info->y = 0;
    info->prev_x = 0;
    info->prev_y = 0;
    if (info->width % 2 == 1)
        value_1 = info->width / 2 + 1;
    if (info->height % 2 == 1)
        value_2 = info->height / 2 + 1;
    info->total = value_1 * value_2;
    if (ac == 4)
        info->type = strdup(av[3]);
    else
        info->type = strdup("imperfect");
}