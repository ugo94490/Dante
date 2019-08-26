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
            maze[i][j] = 0;
            maze[i][info->width + 1] = -2;
            maze[i][info->width] = -1;
        }
    maze[info->height] = NULL;
    return (maze);
}

/*int rand_maze(info_t *info)
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
    }*/

int print_maze(info_t *info)
{
    for (int i = 0; i < info->height; i++) {
        for (int j = 0; j < info->width + 2; j++)
            printf("%d", info->maze[i][j]);
        printf("\n");
    }
    return (0);
}

int choose_dir(int **maze, int x, int y, info_t *info)
{
    int gen = 0;

    while (1) {
        gen = rand() % 4;
        if (gen == 0 && (x + 1 < info->width))
            if (maze[x + 1][y] == 0)
                break;
        if (gen == 1 && (x - 1 >= 0))
            if (maze[x - 1][y] == 0)
                break;
        if (gen == 2 && (y + 1 < info->height))
            if (maze[x][y + 1] == 0)
                break;
        if (gen == 3 && (y - 1 >= 0))
            if (maze[x][y - 1] == 0)
                break;
    }
    return (gen);
}

int check_dir(int **maze, int x, int y, info_t *info)
{
    int count = 0;

    if (x + 1 < info->height)
        if (maze[x + 1][y] == 1)
            count++;
    if (x - 1 >= 0)
        if (maze[x - 1][y] == 1)
            count++;
    if (y + 1 < info->width)
        if (maze[x][y + 1] == 1)
            count++;
    if (y - 1 >= 0)
        if (maze[x][y - 1] == 1)
            count++;
    return (count);
}

int **generate_maze(int **maze, int x, int y, info_t *info)
{
    int gen = choose_dir(maze, x, y, info);
    int new_x = x;
    int new_y = y;

    while (1) {
        if (gen == 0)
            new_x += 1;
        if (gen == 1)
            new_x -= 1;
        if (gen == 2)
            new_y += 1;
        if (gen == 3)
            new_y -= 1;
        if (check_dir(maze, new_x, new_y, info) == 0) {
            maze[new_x][new_y] = 1;
            generate_maze(maze, new_x, new_y, info);
        }
    }
    printf("gen = %d\n", gen);
    return (maze);
}

int create_maze(info_t *info)
{
    info->maze = alloc_maze(info);
    info->maze[0][0] = 0;
    //info->maze = generate_maze(info->maze, 0, 0, info);
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
