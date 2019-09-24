/*
** EPITECH PROJECT, 2019
** solver
** File description:
** ctrl_lines.c
*/

#include "solver.h"

static int check_end(int heigth, int tmp_line, int cols, char *buff)
{
    if (heigth - 1 == tmp_line && buff[cols - 1] == '\n')
        return (1);
    return (0);
}

int ctrl_lines(int heigth, int tmp_line, int cols, char *buff)
{
    if (check_end(heigth, tmp_line, cols, buff) == 1) {
        free(buff);
        return (-1);
    }
    return (0);
}