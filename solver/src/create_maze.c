/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_maze.c
*/

#include "solver.h"

static const uint8_t BORDER_NBR = 2;

static char **create_borders(char **new_maze, int heigth, int width)
{
    new_maze =  malloc(sizeof(char *) * (heigth + BORDER_NBR + 1));
    if (!new_maze)
        return (NULL);
    for (int i = 0; i < heigth + BORDER_NBR; i += 1)
        new_maze[i] = malloc(sizeof(char) * (width + BORDER_NBR));
    for (int i = 0; i < width; i += 1) {
        new_maze[0][i] = BORDER;
        new_maze[heigth + 1][i] = BORDER;
    }
    new_maze[0][width] = 0;
    new_maze[heigth + 1][width] = 0;
    new_maze[heigth + BORDER_NBR] = NULL;
    return (new_maze);
}

char **create_maze(char *path_maze, int heigth, int width)
{
    FILE *fs = fopen(path_maze, "r");
    char **new_maze = NULL;
    size_t len = 0;
    char *buff = NULL;

    if (!fs)
        return (NULL);
    new_maze = create_borders(new_maze, heigth, width);
    if (!new_maze)
        return (NULL);
    for (int i = 1; i < heigth + 1; i += 1) {
        getline(&buff, &len, fs);
        sprintf(new_maze[i], "#%s", buff);
    }
    free(buff);
    fclose(fs);
    return (new_maze);
}
