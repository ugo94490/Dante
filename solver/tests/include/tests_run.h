/*
** EPITECH PROJECT, 2019
** Any Project
** File description:
** Header for Unit Test using criterion.
*/

#ifndef _TESTS_RUN_
#define _TESTS_RUN_

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <stdbool.h>
#define REAL_MALLOC (__real_malloc)
#define wrap_malloc (__wrap_malloc)
void *REAL_MALLOC(size_t s);

#define SHOULD_MALLOC_FAIL() malloc_fail(false, 0)
#define SET_MALLOC_FAIL(x) malloc_fail(true, (x))

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

#endif /* _TESTS_RUN_ */
