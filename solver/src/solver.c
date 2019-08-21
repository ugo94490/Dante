/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver.c
*/

#include "solver.h"

static const char *NOWAY_MSG = "no solution found\n";

static int print_maze(char **maze)
{
    for (int i = 1; maze[i + 1] != NULL; i += 1)
        printf("%s", maze[i] + 1);
    return (0);
}

static uint8_t try_da_way(ctrl_t *control, int x, int y)
{
    if (x == control->width - 1  && y == control->heigth)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    control->cpy[y][x] = WRONG;
    if (control->cpy[y + 1][x] == EMPTY && try_da_way(control, x, y + 1) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->cpy[y][x + 1] == EMPTY && try_da_way(control, x + 1, y) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->cpy[y - 1][x] == EMPTY && try_da_way(control, x, y - 1) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->cpy[y][x - 1] == EMPTY && try_da_way(control, x - 1, y) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    return (1);
}

static int destroy_ctrl(ctrl_t *control)
{
    for (int i = 0; control->maze[i] != NULL; i += 1) {
        free(control->maze[i]);
        free(control->cpy[i]);
    }
    free(control->maze);
    free(control->cpy);
    free(control);
    return (0);
}

int8_t solver(ctrl_t *control)
{
    if (try_da_way(control, 1, 1) == 0)
        print_maze(control->maze);
    else
        printf(NOWAY_MSG);
    destroy_ctrl(control);
    return (0);
}
