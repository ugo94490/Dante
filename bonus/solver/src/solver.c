/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver.c
*/

#include "solver.h"

static const char *NOWAY_MSG = "no solution found";

static int clean_maze(char *maze_line)
{
    for (int j = 0; maze_line[j]; j += 1)
        if (maze_line[j] == WRONG)
            maze_line[j] = EMPTY;
    return (0);
}

int display(ctrl_t *control, sfRenderWindow *window, game_object **tab)
{
    sfVector2f pos;

    for (int i = 0; control->maze[i]; i++)
        for (int j = 0; control->maze[i][j]; j++) {
            pos.x = j * 10;
            pos.y = i * 10;
            if (control->maze[i][j] == GOOD) {
                sfSprite_setPosition(tab[3]->sprite, pos);
                sfRenderWindow_drawSprite(window, tab[3]->sprite, NULL);
            }
            if (control->maze[i][j] == WALL) {
                sfSprite_setPosition(tab[1]->sprite, pos);
                sfRenderWindow_drawSprite(window, tab[1]->sprite, NULL);
            }
            if (control->maze[i][j] == WRONG) {
                sfSprite_setPosition(tab[2]->sprite, pos);
                sfRenderWindow_drawSprite(window, tab[2]->sprite, NULL);
            }
            if (control->maze[i][j] == EMPTY) {
                sfSprite_setPosition(tab[0]->sprite, pos);
                sfRenderWindow_drawSprite(window, tab[0]->sprite, NULL);
            }
        }
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

static uint8_t try_da_way(ctrl_t *control, int x, int y, sfRenderWindow *window, game_object **tab)
{
    display(control, window, tab);
    sfRenderWindow_display(window);
    event(window);
    if (x == control->width - 1 && y == control->heigth)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    control->maze[y][x] = WRONG;
    if (control->maze[y][x + 1] == EMPTY && try_da_way(control, x + 1, y, window, tab) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y + 1][x] == EMPTY && try_da_way(control, x, y + 1, window, tab) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y][x - 1] == EMPTY && try_da_way(control, x - 1, y, window, tab) == 0)
        return ((control->maze[y][x] = GOOD) != 0 ? 0 : 0);
    if (control->maze[y - 1][x] == EMPTY && try_da_way(control, x, y - 1, window, tab) == 0)
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

game_object **init_sprite(void)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 0, 0};
    game_object **tab = malloc(sizeof(game_object *) * 4);

    tab[0] = create_object("blanc.png", pos, rect);
    tab[1] = create_object("noir.png", pos, rect);
    tab[2] = create_object("non.png", pos, rect);
    tab[3] = create_object("ok.png", pos, rect);
    return (tab);
}

int8_t solver(ctrl_t *control, sfRenderWindow *window)
{
    int solved = 0;
    game_object **tab = init_sprite();

    if (control->maze[1][1] == '*' && try_da_way(control, 1, 1, window, tab) == 0) {
        display(control, window, tab);
        sfRenderWindow_display(window);
//        print_maze(control->maze);
    } else {
        printf(NOWAY_MSG);
        solved = 1;
    }
    while (sfRenderWindow_isOpen(window))
        event(window);
    for (int i = 0; i < 4; i++)
        destroy_object(tab[i]);
    destroy_ctrl(control);
    return (solved);
}
