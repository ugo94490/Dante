/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "generator.h"

int main(int ac, char **av)
{
    info_t *info;
    sfRenderWindow *window;

    srand(time(0));
    if (check_error(ac, av) == 84)
        return (84);
    info = malloc(sizeof(info_t));
    init_info(info, av, ac);
    if (info->height > 100 || info->width > 100)
        return (printf("Taille max 100 x 100"));
    window = create_window(info->width * 10, info->height * 10, "DANTE", 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    create_maze(info, window);
    while (sfRenderWindow_isOpen(window))
        event(window);
    sfRenderWindow_destroy(window);
    free_all(info, ac);
    return (0);
}
