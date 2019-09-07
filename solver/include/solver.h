/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** solver.h
*/

#ifndef _SOLVER_H_
#define _SOLVER_H_

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

/* Function to Solve the Maze */
int8_t solver(ctrl_t *);
char **create_maze(char *, int, int);
ctrl_t *create_ctrl(char *path_maze);
int ctrl_lines(int heigth, int tmp_line, int cols, char *buff);

#endif /* _SOLVER_H_ */
