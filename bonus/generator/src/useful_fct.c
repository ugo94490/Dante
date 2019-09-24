/*
** EPITECH PROJECT, 2019
** useful_fct.c
** File description:
** useful_fct.c
*/

#include "generator.h"

sfRenderWindow *create_window(int width, int height, char *Name, int full)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 32};

    if (full == 1)
        window = sfRenderWindow_create(video_mode, Name, sfFullscreen |
        sfResize | sfClose, NULL);
    if (full == 0)
        window = sfRenderWindow_create(video_mode, Name, sfResize |
        sfClose, NULL);
    return (window);
}

struct game_object *create_object(char *spritesheet, sfVector2f
position, sfIntRect rect1)
{
    game_object *assets = malloc(sizeof(game_object));

    assets->texture = sfTexture_createFromFile(spritesheet, NULL);
    assets->sprite = sfSprite_create();
    sfSprite_setTexture(assets->sprite, assets->texture, sfTrue);
    assets->pos = position;
    sfSprite_setPosition(assets->sprite, assets->pos);
    assets->rect = rect1;
    if (assets->sprite == NULL || assets->texture == NULL)
        return (NULL);
    return (assets);
}

void destroy_object(struct game_object *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    free(obj);
}

void display_pause(sfRenderWindow *window)
{
    sfSprite *menu = sfSprite_create();
    sfTexture *menu_tex = sfTexture_createFromFile("./img/pause.png", NULL);
    sfVector2f position = {0, 0};

    sfSprite_setTexture(menu, menu_tex, sfTrue);
    sfSprite_setPosition(menu, position);
    sfRenderWindow_drawSprite(window, menu, NULL);
    sfRenderWindow_display(window);
}

int event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        close_window(event, window);
    return (0);
}

void close_window(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}
