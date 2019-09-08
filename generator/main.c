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
        maze[i] = malloc(sizeof(int) * (info->width + 1));
    for (int i = 0; i < info->height; i++)
        for (int j = 0; j < info->width; j++) {
            maze[i][j] = 1;
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
        for (int j = 0; j < info->width + 1; j++)
            convert_print(info, i, j);
        //printf("%d ", info->maze[i][j]);
    }
    printf("\n");
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
        return (-1);
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

int **change(int **maze, int x, int y, int flag)
{
    int nb = 0;

    if (flag == 0) {
        nb = (maze[y][x+1] > maze[y][x-1]) ? maze[y][x-1] : maze[y][x+1];
        1 == 1 ? maze[y][x+1] = nb, maze[y][x-1] = nb : 0;
        maze[y][x] = nb;
    }
    if (flag == 1) {
        nb = (maze[y+1][x] > maze[y-1][x]) ? maze[y-1][x] : maze[y+1][x];
        1 == 1 ? maze[y+1][x] = nb, maze[y-1][x] = nb : 0;
        maze[y][x] = nb;
    }
    printf("x = %d y = %d\n", x, y);
    return (maze);
}

int **check_case(int **maze, info_t *info, int x, int y)
{
    if (x + 1 < info->width && x - 1 > 0)
        if (maze[y][x] == -3 && maze[y][x + 1] != maze[y][x - 1])
            maze = change(maze, x, y, 0);
    if (y + 1 < info->height && y - 1 > 0)
        if (maze[x][y] == -3 && maze[y + 1][x] != maze[y - 1][x])
            maze = change(maze, x, y, 1);
    return (maze);
}

link_t *init_link(int y, int x)
{
    link_t *link = malloc(sizeof(*link));

    link->x = x;
    link->y = y;
    link->next = NULL;
    link->prev = NULL;
    return (link);
}

int my_linklen(link_t *link)
{
    int i = 1;

    if (link == NULL)
        return (0);
    while (link->next != NULL) {
        link = link->next;
        i++;
    }
    return (i);
}

void add_link(link_t **link, int x, int y)
{
    (*link)->next = malloc(sizeof(link_t));
    (*link)->next->prev = (*link);
    (*link) = (*link)->next;
    (*link)->next = NULL;
    (*link)->x = x;
    (*link)->y = y;
}

int get_len(link_t *link)
{
    int len = 0;

    while (link->prev != NULL)
        link = link->prev;
    len = my_linklen(link);
    return (len);
}

int check_one(link_t **link, info_t *info)
{
    int dir = 0;
    static int flag = 0;

    if (!(*link))
        return (-1);
    dir = choose_dir(info->maze, (*link)->x, (*link)->y, info);
    //printf("%d\n", get_len((*link)));
    if (dir == -1 && flag == 0){
        print_maze(info);
        printf("\n");
        if ((*link)->next == NULL) {
            printf("dernier node\n");
            (*link) = (*link)->prev;
            free((*link)->next);
            (*link)->next = NULL;
        } else if ((*link)->next != NULL && (*link)->prev == NULL) {
            printf("1er node\n");
            (*link) = (*link)->next;
            free((*link)->prev);
        } else if ((*link)->next != NULL && (*link)->prev != NULL) {
            printf("node au milieu\n");
            (*link) = (*link)->next;
            (*link)->prev->prev->next = (*link);
            (*link)->prev = (*link)->prev->prev;
        }
        return (-1);
    }
    if (dir == 1) {
        dir == 1 ? info->maze[(*link)->x + 1][(*link)->y] = 0,
        info->maze[(*link)->x + 2][(*link)->y] = 0 : 0;
        add_link(link, (*link)->x + 2, (*link)->y);
    }
    if (dir == 2) {
        dir == 2 ? info->maze[(*link)->x - 1][(*link)->y] = 0,
        info->maze[(*link)->x - 2][(*link)->y] = 0 : 0;
        add_link(link, (*link)->x - 2, (*link)->y);
    }
    if (dir == 3) {
        dir == 3 ? info->maze[(*link)->x][(*link)->y + 1] = 0,
        info->maze[(*link)->x][(*link)->y + 2] = 0 : 0;
        add_link(link, (*link)->x, (*link)->y + 2);
    }
    if (dir == 4) {
        dir == 4 ? info->maze[(*link)->x][(*link)->y - 1] = 0,
        info->maze[(*link)->x][(*link)->y - 2] = 0 : 0;
        add_link(link, (*link)->x, (*link)->y - 2);
    }
    flag = 0;
    return (0);
}

void go_rand(link_t **link)
{
    int len = 0;
    int pos = 0;

    printf("pd pd pdp dppd pd pdpdd = %d %d\n", (*link)->x, (*link)->y);
    len = get_len((*link));
    pos = rand() % len;
    while ((*link)->prev != NULL)
        (*link) = (*link)->prev;
    //printf("len = %d pos = %d\n", len, pos);
    for (int i = 0; i < pos; i++)
        (*link) = (*link)->next;
}

int **generate_maze(int **maze, info_t *info)
{
    link_t *link = init_link(0, 0);
    link_t *tmp = link;

    maze[link->y][link->x] = 0;
    while (my_linklen(tmp) != 0) {
        //printf("tmp_len = %d\n", get_len(tmp));
        if (check_one(&link, info) == -1)
            go_rand(&link);
        //printf("next = %d %d \n", link->next->x, link->next->y);
    }
    return (info->maze);
}

int create_maze(info_t *info)
{
    info->maze = alloc_maze(info);
    info->maze = generate_maze(info->maze, info);
    //info->maze[info->height - 1][info->width - 1] = 0;
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
