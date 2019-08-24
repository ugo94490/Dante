/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver.c
*/

#include "solver.h"

static const char *NOWAY_MSG = "no solution found\n";

static int clean_maze(char *maze_line)
{
    for (int j = 0; maze_line[j]; j += 1)
        if (maze_line[j] == '@')
            maze_line[j] = '*';
    return (0);
}

static int print_maze(char **maze)
{
    for (int i = 1; maze[i + 1] != NULL; i += 1) {
        clean_maze(maze[i]);
        printf("%s", maze[i] + 1);
    }
    return (0);
}

static uint8_t try_da_way(ctrl_t *control, int x, int y)
{
    if (x == control->width - 1 && y == control->heigth)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    control->maze[y][x] = WRONG;
    if (control->maze[y][x + 1] == EMPTY && try_da_way(control, x + 1, y) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y + 1][x] == EMPTY && try_da_way(control, x, y + 1) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y][x - 1] == EMPTY && try_da_way(control, x - 1, y) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y - 1][x] == EMPTY && try_da_way(control, x, y - 1) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    return (1);
}

static int destroy_ctrl(ctrl_t *control)
{
    for (int i = 0; control->maze[i] != NULL; i += 1)
        free(control->maze[i]);
    free(control->maze);
    free(control);
    return (0);
}

int8_t solver(ctrl_t *control)
{
    int solved = 0;

    if (control->maze[1][1] == '*' && try_da_way(control, 1, 1) == 0)
        print_maze(control->maze);
    else {
        printf(NOWAY_MSG);
        solved = 1;
    }
    destroy_ctrl(control);
    return (solved);
}
