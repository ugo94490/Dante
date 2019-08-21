/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** t_solver.c
*/

#include <criterion/criterion.h>
#include "solver.h"

Test (SOLVER, fail_open)
{
    cr_assert_eq(create_ctrl("toast.txt"), NULL);
}

Test (SOLVER, success_open)
{
    cr_assert_neq(create_ctrl("tests/ressources/g_simple_map.txt"), NULL);
}

Test (SOLVER, one_line_file)
{
    cr_assert_neq(create_ctrl("tests/ressources/one_line_map.txt"), NULL);
}

Test (SOLVER, invalid_col_file)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_col_map2.txt"), NULL);
}

Test (SOLVER, invalid_file_empty)
{
    cr_assert_eq(create_ctrl("tests/ressources/empty_map.txt"), NULL);
}

Test (SOLVER, invalid_file_lines)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_len_map.txt"), NULL);
}

Test (SOLVER, invalid_file_lines_2)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_len_map2.txt"), NULL);
}

Test (SOLVER, invalid_file_char)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map.txt"), NULL);
}

Test (SOLVER, invalid_file_char_2)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map2.txt"), NULL);
}

Test (SOLVER, invalid_file_char_3)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map3.txt"), NULL);
}
