/*
** EPITECH PROJECT, 2019
** generator
** File description:
** check_error.c
*/

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_nbr(char *str)
{
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) == 0)
            return (84);
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac != 4 && ac != 3)
        return (84);
    if (check_nbr(av[1]) == 84 || check_nbr(av[2]) == 84)
        return (84);
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
        return (84);
    if (ac == 4)
        if (strcmp(av[3], "perfect") != 0)
            return (84);
    return (0);
}