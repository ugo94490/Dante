/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main.c
*/

#include "generator.h"

int main(int ac, char **av, char **env)
{
    if (!(*env) || ac < 2 || ac > 3)
        return (84);
    printf("%s\n", av[1]);
    return (0);
}
