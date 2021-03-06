/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** check_error.c
*/

#include "solver.h"

static const char *ERR_MSG = "Error: Invalid File\n";
static const uint8_t SIZE_MSG = 20;

static int valid_cols(char *buff)
{
    int cols = 0;

    for (cols = 0; buff[cols]; cols += 1)
        if (buff[cols] != EMPTY && buff[cols] != '\n' && buff[cols] != WALL)
            return (-1);
    return (cols);
}

static int check_each_lines(FILE *fs, char *buff, size_t len, int heigth)
{
    int cols = 0;
    int tmp = 0;
    int tmp_line = 0;

    getline(&buff, &len, fs);
    cols = valid_cols(buff);
    if (cols == -1 || cols == 0 || (buff[cols - 1] == '\n'\
    && tmp_line == heigth))
        return (-1);
    while (getline(&buff, &len, fs) != -1) {
        tmp_line += 1;
        tmp = valid_cols(buff);
        if (ctrl_lines(heigth, tmp_line, cols, buff) == -1)
            return (-1);
        if (heigth - 1 != tmp_line && (tmp == -1 || tmp != cols))
            return (-1);
    }
    if (ctrl_lines(heigth, tmp_line, cols, buff) == -1)
        return (-1);
    free(buff);
    return ((heigth == 1) ? cols + 1 : cols);
}

static int count_columns(char *path_maze, int heigth)
{
    FILE *fs = fopen(path_maze, "r");
    int cols = 0;
    char *buff = NULL;
    size_t len = 0;

    if (!fs || heigth == -1)
        return (-1);
    cols = check_each_lines(fs, buff, len, heigth);
    return (cols);
}

static int count_line(char *path_maze)
{
    FILE *fs = fopen(path_maze, "r");
    int nbr_line = 0;
    size_t len = 0;
    char *buff = NULL;

    if (!fs)
        return (-1);
    while (getline(&buff, &len, fs) != -1)
        nbr_line += 1;
    free(buff);
    fclose(fs);
    return (nbr_line);
}

ctrl_t *create_ctrl(char *path_maze)
{
    ctrl_t *control = malloc(sizeof(ctrl_t));

    if (!control)
        return (NULL);
    control->heigth = count_line(path_maze);
    control->width = count_columns(path_maze, control->heigth);
    if (control->heigth == -1 || control->width == -1) {
        write(2, ERR_MSG, SIZE_MSG);
        free(control);
        return (NULL);
    }
    control->maze = create_maze(path_maze, control->heigth, control->width);
    if (!control->maze)
        return (NULL);
    return (control);
}
