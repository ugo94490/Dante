/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** t_solver.c
*/

#include <errno.h>
#include "tests_run.h"
#include "solver.h"

bool malloc_fail(bool set, int val)
{
    static int count = 0;

    if (set)
        count = val;
    else
        count--;
    return count == 0;
}

void *wrap_malloc(size_t s)
{
    if (SHOULD_MALLOC_FAIL()) {
        errno = ENOMEM;
        return NULL;
    }
    return real_malloc(s);
}

Test(CREATE, fail_malloc_two_file, .init=redirect_all_std)
{
    SET_MALLOC_FAIL(1);
    cr_assert_eq(create_maze("tests/ressources/g_simple_map.txt", 1, 1), NULL);
}

Test(CREATE, fail_malloc_3, .init=redirect_all_std)
{
    SET_MALLOC_FAIL(2);
    cr_assert_eq(create_ctrl("tests/ressources/g_one_line_map.txt"), NULL);
}

Test(CREATE, invalid_file, .init=redirect_all_std)
{
    cr_assert_eq(create_maze("bachibouzouk", 1, 1), NULL);
}

Test(SOLVER, fail_open, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("toast.txt"), NULL);
}

Test(SOLVER, fail_malloc_one, .init=redirect_all_std)
{
    SET_MALLOC_FAIL(1);
    cr_assert_eq(create_ctrl("tests/ressources/g_simple_map.txt"), NULL);
}

Test(SOLVER, success_open, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/g_simple_map.txt"), NULL);
}

Test(SOLVER, one_line_file, .init=redirect_all_std)
{
    cr_assert_neq(create_ctrl("tests/ressources/one_line_map.txt"), NULL);
}

Test(SOLVER, one_line_file_bad, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/one_line_map2.txt"), NULL);
}

Test(SOLVER, invalid_col_file, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_col_map2.txt"), NULL);
}

Test(SOLVER, invalid_file_empty, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/empty_map.txt"), NULL);
}

Test(SOLVER, invalid_file_lines, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_len_map.txt"), NULL);
}

Test(SOLVER, invalid_file_lines_2, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_len_map2.txt"), NULL);
}

Test(SOLVER, invalid_file_char, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map.txt"), NULL);
}

Test(SOLVER, invalid_file_char_2, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map2.txt"), NULL);
}

Test(SOLVER, invalid_file_char_3, .init=redirect_all_std)
{
    cr_assert_eq(create_ctrl("tests/ressources/i_char_map3.txt"), NULL);
}
