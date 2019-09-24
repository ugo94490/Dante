/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver.h
*/

#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* Define and Static Const */
static const char GOOD = 'o';
static const char WALL = 'X';
static const char WRONG = '@';
static const char EMPTY = '*';
static const char BORDER = '#';

/* Usefull Struct to Solve */
typedef struct ctrl_s {
    char **maze;
    int heigth;
    int width;
} ctrl_t;

typedef struct game_object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
}game_object;

/* Function to Solve the Maze */
int8_t solver(ctrl_t *, sfRenderWindow *);
char **create_maze(char *, int, int);
ctrl_t *create_ctrl(char *path_maze);
int ctrl_lines(int heigth, int tmp_line, int cols, char *buff);

sfRenderWindow *create_window(int, int, char*, int);
struct game_object *create_object(char*, sfVector2f, sfIntRect);
void destroy_object(struct game_object *obj);
int event(sfRenderWindow *);
void close_window(sfEvent, sfRenderWindow*);

#endif /* _SOLVER_H_ */
