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
    char *type;
    char **maze;
}info_t;

#endif /* _GENERATOR_H_ */
