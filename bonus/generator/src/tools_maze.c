/*
** EPITECH PROJECT, 2019
** generator
** File description:
** tools_maze.c
*/

#include "generator.h"

int print_maze(info_t *info)
{
    for (int i = 0; i < info->height; i++) {
        for (int j = 0; j < info->width + 1; j++)
            convert_print(info, i, j);
    }
    return (0);
}

int draw(sfRenderWindow *window, info_t *info, game_object *blanc)
{
    sfVector2f pos = {0, 0};

    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width; j++) {
            pos.x = j * 10;
            pos.y = i * 10;
            if (info->maze[i][j] == 0) {
                sfSprite_setPosition(blanc->sprite, pos);
                sfRenderWindow_drawSprite(window, blanc->sprite, NULL);
            }
        }
    return (0);
}

int **generate_maze(int **maze, info_t *info, sfRenderWindow *window)
{
    link_t *link = init_link(0, 0);
    int j = 0;
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 10, 0, 0};
    game_object *blanc = create_object("blanc.png", pos, rect);

    maze[link->y][link->x] = 0;
    while (my_linklen(&link) != 0) {
        draw(window, info, blanc);
        event(window);
        if (check_one(&link, info) == -2)
            break;
        /*pos.x = link->x * 10;
        pos.y = link->y * 10;
        sfSprite_setPosition(blanc->sprite, pos);
        sfRenderWindow_drawSprite(window, blanc->sprite, NULL);*/
        sfRenderWindow_display(window);
        j++;
    }
    destroy_object(blanc);
    return (info->maze);
}

int **do_imperfect(info_t *info, sfRenderWindow *window)
{
    int count = 0;
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 10, 0, 0};
    game_object *blanc = create_object("blanc.png", pos, rect);

    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width; j++) {
            info->maze[i][j] == 1 ? count++ : 0;
            count % 8 == 0 ? info->maze[i][j] = 0, count++ : 0;
            draw(window, info, blanc);
            sfRenderWindow_display(window);
        }
    destroy_object(blanc);
    return (info->maze);
}

int create_maze(info_t *info, sfRenderWindow *window)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 10, 0, 0};
    game_object *blanc = create_object("blanc.png", pos, rect);

    info->maze = alloc_maze(info);
    info->maze = generate_maze(info->maze, info, window);
    if (info->height % 2 == 0 && info->width % 2 == 0) {
        info->maze[info->height - 2][info->width - 1] = 0;
        info->maze[info->height - 1][info->width - 1] = 0;
    }
    if (info->height % 2 == 0 && info->width % 2 != 0)
        info->maze[info->height - 1][info->width - 1] = 0;
    if (info->height % 2 != 0 && info->width % 2 == 0)
        info->maze[info->height - 1][info->width - 1] = 0;
    if (strcmp(info->type, "imperfect") == 0)
        info->maze = do_imperfect(info, window);
    else {
        draw(window, info, blanc);
        sfRenderWindow_display(window);
    }
    destroy_object(blanc);
    return (0);
}
