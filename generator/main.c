/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <time.h>
#include "generator.h"

int check_nbr(char *str)
{
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) == 0)
            return (84);
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (check_nbr(av[1]) == 84 || check_nbr(av[2]) == 84)
        return (84);
    if (strcmp(av[3], "perfect") != 0 && strcmp(av[3], "perfect") != 0)
        return (84);
    return (0);
}

void init_info(info_t *info, char **av)
{
    info->width = atoi(av[1]);
    info->height = atoi(av[2]);
    info->type = strdup(av[3]);
}

char **alloc_maze(info_t *info)
{
    char **maze = malloc(sizeof(char *) * (info->height + 1));

    for (int i = 0; i < info->height; i++)
        maze[i] = malloc(sizeof(char) * (info->width + 2));
    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width + 2; j++) {
            maze[i][j] = 'X';
            maze[i][info->width + 1] = '\0';
            maze[i][info->width] = '\n';
        }
    maze[info->height] = NULL;
    return (maze);
}

int rand_maze(info_t *info)
{
    int k = 0;
    int d = 0;

    for (int i = 2; i < info->height; i += 2) {
        k = rand() % (((info->width / 5) * 4));
        k == 0 ? k = 1 : 0;
        d = rand() % k;
        info->maze[i - 1][d] = '*';
        for (int j = 0; j < k; j++)
            info->maze[i][j] = '*';
    }
    return (0);
}

int create_maze(info_t *info)
{
    info->maze = alloc_maze(info);

    for (int i = 0; i < info->width; i++)
        info->maze[0][i] = '*';
    rand_maze(info);
    return (0);
}

int print_maze(info_t *info)
{
    for (int i = 0; info->maze[i]; i++)
        printf("%s", info->maze[i]);
    return (0);
}

int free_all(info_t *info)
{
    for (int i = 0; info->maze[i]; i++)
        free(info->maze[i]);
    free(info->maze);
    free(info->type);
    free(info);
    return (0);
}

int main(int ac, char **av)
{
    info_t *info;

    srand(time(0));
    if (check_error(ac, av) == 84)
        return (84);
    info = malloc(sizeof(info_t));
    init_info(info, av);
    create_maze(info);
    print_maze(info);
    printf("\nx = %d, y = %d, type = %s\n", info->width, info->height, info->type);
    free_all(info);
    return (0);
}
