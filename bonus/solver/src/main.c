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
    sfRenderWindow *window;

    if (!(*env) || !(*av) || ac != 2)
        return (84);
    control = create_ctrl(av[1]);
    if (!control)
        return (84);
    if (control->heigth > 100 || control->width > 100)
        return (printf("Taille max 100 x 100"));
    window = create_window(control->width * 10, control->heigth * 10, "DANTE", 0);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_clear(window, sfBlack);
    if (solver(control, window) == 1) {
        sfRenderWindow_destroy(window);
        return (84);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
