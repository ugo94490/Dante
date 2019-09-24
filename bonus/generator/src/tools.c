/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** tools.c
*/

#include <stdlib.h>
#include <string.h>

int my_strlen_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (i);
    for (i = 0; tab[i] != NULL; i++);
    return (i);
}

int my_free_tab(char **tab, int ret)
{
    for (int i = 0; i < my_strlen_tab(tab); i++)
        free(tab[i]);
    free(tab);
    return (ret);
}

char **tab_realloc(char **tab, char *buffer)
{
    int i = 0;
    char **copy = NULL;

    if (buffer == NULL)
        return (tab);
    if (tab == NULL) {
        copy = malloc(sizeof(char *) * (i + 2));
        copy[0] = malloc(sizeof(char) * (strlen(buffer) + 1));
        copy[0] = strcpy(copy[0], buffer);
        copy[1] = NULL;
    } else {
        for (i = 0; tab[i] != NULL; i++);
        copy = malloc(sizeof(char *) * (i + 2));
        for (int j = 0; tab[j] != NULL; j++)
            copy[j] = strdup(tab[j]);
        copy[i] = strdup(buffer);
        copy[i + 1] = NULL;
    }
    tab != NULL ? my_free_tab(tab, 0) : 0;
    free(buffer);
    return (copy);
}