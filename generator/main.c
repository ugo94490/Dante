/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <time.h>
#include "generator.h"

int main(int ac, char **av)
{
    info_t *info;

    srand(time(0));
    if (check_error(ac, av) == 84)
        return (84);
    info = malloc(sizeof(info_t));
    init_info(info, av, ac);
    create_maze(info);
    print_maze(info);
    free_all(info, ac);
    return (0);
}
