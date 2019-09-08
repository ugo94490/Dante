/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator.h
*/

#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

typedef struct info_s
{
    int width;
    int height;
    int x;
    int y;
    int prev_x;
    int prev_y;
    int total;
    char *type;
    int **maze;
}info_t;

typedef struct link_s
{
    int x;
    int y;
    struct link_s *next;
    struct link_s *prev;
} link_t;

/* Check Error */
int check_nbr(char *);
int check_error(int, char **);

/* Create Info */
int **alloc_maze(info_t *);
void init_info(info_t *, char **, int);

/* Maze Tools */
int print_maze(info_t *);
int **modif_maze(int **, int, int, info_t *);
int **generate_maze(int **, info_t *);
int create_maze(info_t *);

/* Direction tools */
int check_one(link_t **, info_t *);
int convert_print(info_t *, int, int);

/* Node Tools */
void link_end(link_t **, int, int);
link_t *init_link(int, int);
int my_linklen(link_t **);
void add_link(link_t **, int, int);

/* Tools Function */
int my_strlen_tab(char **);
char **tab_realloc(char **, char *);
int my_free_tab(char **, int);
int free_all(info_t *, int);

#endif /* _GENERATOR_H_ */
