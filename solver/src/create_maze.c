/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_maze.c
*/

#include "solver.h"

static uint8_t BORDERS = 2;

static char **create_borders(char **new_maze, int heigth, int width)
{
    new_maze =  malloc(sizeof(char *) * (heigth + BORDERS + 1));
    if (!new_maze)
        return (NULL);
    for (int i = 0; i < heigth + BORDERS; i += 1)
        new_maze[i] = malloc(sizeof(char) * (width + BORDERS));
    for (int i = 0; i < width; i += 1) {
        new_maze[0][i] = '#';
        new_maze[heigth + 1][i] = '#';
    }
    new_maze[0][width] = 0;
    new_maze[heigth + 1][width] = 0;
    new_maze[heigth + BORDERS] = NULL;
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
    for (int i = 1; i < heigth + 1; i += 1) {
        getline(&buff, &len, fs);
        sprintf(new_maze[i], "#%s", buff);
    }
    free(buff);
    fclose(fs);
    return (new_maze);
}
