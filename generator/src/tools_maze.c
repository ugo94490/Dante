/*
** EPITECH PROJECT, 2019
** generator
** File description:
** tools_maze.c
*/

#include "generator.h"

int print_maze(info_t *info)
{
    for (int i = 0; i < info->height; i++) {
        for (int j = 0; j < info->width + 1; j++)
            convert_print(info, i, j);
    }
    return (0);
}

int **generate_maze(int **maze, info_t *info)
{
    link_t *link = init_link(0, 0);
    int j = 0;

    maze[link->y][link->x] = 0;
    while (my_linklen(&link) != 0) {
        if (check_one(&link, info) == -2)
            break;
        j++;
    }
    return (info->maze);
}

int **do_imperfect(info_t *info)
{
    int count = 0;

    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width; j++) {
            info->maze[i][j] == 1 ? count++ : 0;
            count % 8 == 0 ? info->maze[i][j] = 0, count++ : 0;
        }
    return (info->maze);
}

int create_maze(info_t *info)
{
    info->maze = alloc_maze(info);
    info->maze = generate_maze(info->maze, info);
    if (info->height % 2 == 0 && info->width % 2 == 0) {
        info->maze[info->height - 2][info->width - 1] = 0;
        info->maze[info->height - 1][info->width - 1] = 0;
    }
    if (info->height % 2 == 0 && info->width % 2 != 0)
        info->maze[info->height - 1][info->width - 1] = 0;
    if (info->height % 2 != 0 && info->width % 2 == 0)
        info->maze[info->height - 1][info->width - 1] = 0;
    if (strcmp(info->type, "imperfect") == 0)
        info->maze = do_imperfect(info);
    return (0);
}
