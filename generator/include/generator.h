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

#endif /* _GENERATOR_H_ */
