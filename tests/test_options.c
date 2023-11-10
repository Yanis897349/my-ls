/*
** EPITECH PROJECT, 2023
** test_options
** File description:
** Unit testing options parsing from my_ls
*/

#include "Core/options.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(options, options_string_set_max)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-alRdrt"};
    options_t *options = create_options(ac, av);

    cr_assert_eq(options->is_all, 1);
    cr_assert_eq(options->is_long, 1);
    cr_assert_eq(options->is_recursive, 0);
    cr_assert_eq(options->is_dir_only, 1);
    cr_assert_eq(options->is_reverse_sort, 1);
    cr_assert_eq(options->is_time_sort, 1);
    free(options);
}

Test(options, options_string_set_reduced)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-aRd"};
    options_t *options = create_options(ac, av);

    cr_assert_eq(options->is_all, 1);
    cr_assert_eq(options->is_long, 0);
    cr_assert_eq(options->is_recursive, 0);
    cr_assert_eq(options->is_dir_only, 1);
    cr_assert_eq(options->is_reverse_sort, 0);
    cr_assert_eq(options->is_time_sort, 0);
    free(options);
}

Test(options, options_string_set_empty)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-"};
    options_t *options = create_options(ac, av);

    cr_assert_eq(options->is_all, 0);
    cr_assert_eq(options->is_long, 0);
    cr_assert_eq(options->is_recursive, 0);
    cr_assert_eq(options->is_dir_only, 0);
    cr_assert_eq(options->is_reverse_sort, 0);
    cr_assert_eq(options->is_time_sort, 0);
    free(options);
}

Test(options, options_string_with_not_supported_flag, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-aRdX"};
    options_t *options = create_options(ac, av);

    cr_assert_eq(options, NULL);
    cr_assert_stderr_eq_str("my_ls: invalid option -- 'X'\n");
    free(options);
}
