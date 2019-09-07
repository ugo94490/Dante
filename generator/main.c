/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <time.h>
#include "generator.h"

#define E 0
#define O 1
#define N 2
#define S 3

int check_nbr(char *str)
{
    for (int i = 0; str[i]; i++)
        if (isdigit(str[i]) == 0)
            return (84);
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac != 4 && ac != 3)
        return (84);
    if (check_nbr(av[1]) == 84 || check_nbr(av[2]) == 84)
        return (84);
    if (ac == 4)
        if (strcmp(av[3], "perfect") != 0)
            return (84);
    return (0);
}

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

void init_info(info_t *info, char **av, int ac)
{
    int value_1 = 0;
    int value_2 = 0;

    info->width = atoi(av[1]);
    info->height = atoi(av[2]);
    info->x = 0;
    info->y = 0;
    info->prev_x = 0;
    info->prev_y = 0;
    if (info->width % 2 == 1)
        value_1 = info->width / 2 + 1;
    if (info->height % 2 == 1)
        value_2 = info->height / 2 + 1;
    info->total = value_1 * value_2;
    if (ac == 4)
        info->type = strdup(av[3]);
}

int **alloc_maze(info_t *info)
{
    int **maze = malloc(sizeof(int *) * (info->height + 1));

    for (int i = 0; i < info->height; i++)
        maze[i] = malloc(sizeof(int) * (info->width + 2));
    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width + 2; j++) {
            maze[i][j] = 1;
            maze[i][info->width + 1] = -2;
            maze[i][info->width] = -1;
        }
    maze[info->height] = NULL;
    return (maze);
}

int convert_print(info_t *info, int i, int j)
{
    if (info->maze[i][j] == 0)
        printf("*");
    if (info->maze[i][j] == 1)
        printf("X");
    if (i != info->height - 1)
        if (info->maze[i][j] == -1)
            printf("\n");
    return (0);
}

int print_maze(info_t *info)
{
    for (int i = 0; i < info->height; i++) {
        for (int j = 0; j < info->width + 2; j++)
            convert_print(info, i, j);
    }
    return (0);
}

int choose_dir(int **maze, int x, int y, info_t *info)
{
    int direction = -1;
    char **tab = NULL;

    if (x + 2 < info->height)
        if (maze[x + 2][y] == 1)
            tab = tab_realloc(tab, strdup("1"));
    if (x - 2 >= 0)
        if (maze[x - 2][y] == 1)
            tab = tab_realloc(tab, strdup("2"));
    if (y + 2 < info->width)
        if (maze[x][y + 2] == 1)
            tab = tab_realloc(tab, strdup("3"));
    if (y - 2 >= 0)
        if (maze[x][y - 2] == 1)
            tab = tab_realloc(tab, strdup("4"));
    if (my_strlen_tab(tab) == 0)
        return (direction);
    direction = atoi(tab[rand() % my_strlen_tab(tab)]);
    my_free_tab(tab, 0);
    return (direction);
}

int **modif_maze(int **maze, int x, int y, info_t *info)
{
    int dir = choose_dir(maze, x, y, info);

    if (dir == -1)
        return (maze);
    dir == 1 ? maze[x + 1][y] = 0, maze[x + 2][y] = 0 : 0;
    dir == 2 ? maze[x - 1][y] = 0, maze[x - 2][y] = 0 : 0;
    dir == 3 ? maze[x][y + 1] = 0, maze[x][y + 2] = 0 : 0;
    dir == 4 ? maze[x][y - 1] = 0, maze[x][y - 2] = 0 : 0;
    return (maze);
}

int **generate_maze(int **maze, info_t *info)
{
    for (int i = 0; i < info->height; i += 2) {
        for (int j = 0; j < info->width; j += 2)
            maze = modif_maze(maze, i, j, info);
    }
    return (maze);
}

int create_maze(info_t *info)
{
    info->maze = alloc_maze(info);
    info->maze[0][0] = 0;
    info->maze[info->height - 1][info->width - 1] = 0;
    info->maze = generate_maze(info->maze, info);
    return (0);
}

int free_all(info_t *info, int ac)
{
    for (int i = 0; info->maze[i]; i++)
        free(info->maze[i]);
    free(info->maze);
    if (ac == 4)
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
    init_info(info, av, ac);
    create_maze(info);
    print_maze(info);
    free_all(info, ac);
    return (0);
}
