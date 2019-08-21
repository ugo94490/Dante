/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main.c
*/

#include "solver.h"

int main(int ac, char **av, char **env)
{
    ctrl_t *control = NULL;

    if (!(*env) || !(*av) || ac != 2)
        return (84);
    control = create_ctrl(av[1]);
    if (!control)
        return (84);
    solver(control);
    return (0);
}
