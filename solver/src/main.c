/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main.c
*/

#include "solver.h"

int main(int ac, char **av, char **env)
{
    if (!(*env) || ac != 2)
        return (84);
    printf("%s\n", av[1]);
    return (0);
}
