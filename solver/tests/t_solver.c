/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** t_solver.c
*/

#include <criterion/criterion.h>
#include "solver.h"

Test (SOLVER, no_exit_map)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_no_end_map.txt");

    cr_assert_eq(solver(control), 1);
}

Test (SOLVER, simple_map)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_simple_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test (SOLVER, complex_map)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_complex_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test (SOLVER, one_line_map)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_one_line_map.txt");

    cr_assert_eq(solver(control), 0);
}

Test (SOLVER, one_col_map)
{
    ctrl_t *control = create_ctrl("tests/ressources/g_one_col_map.txt");

    cr_assert_eq(solver(control), 0);
}
