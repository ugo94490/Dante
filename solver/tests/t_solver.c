/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** t_solver.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "solver.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(SOLVER, no_exit_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_no_end_map.txt");

    cr_assert_eq(solver(control), 1);
}

Test(SOLVER, one_line_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_one_line_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test(SOLVER, one_col_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_one_col_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test(SOLVER, simple_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_simple_map2.txt");

    cr_assert_eq(solver(control), 0);
}

Test(SOLVER, complex_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_complex_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test(SOLVER, hard_map, .init=redirect_all_std)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_hard_maze.txt");

    cr_assert_eq(solver(control), 1);
}
