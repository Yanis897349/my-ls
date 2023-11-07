/*
** EPITECH PROJECT, 2023
** test_options
** File description:
** Unit testing options parsing from my_ls
*/

#include "src/Core/options.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(options, options_string_set_max)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-alRdrt"};
    char *options_string = get_options(ac, av);

    cr_assert_str_eq(options_string, "alRdrt");
    free(options_string);
}

Test(options, options_string_set_reduced)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-aRd"};
    char *options_string = get_options(ac, av);

    cr_assert_str_eq(options_string, "aRd");
    free(options_string);
}

Test(options, options_string_set_empty)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-"};
    char *options_string = get_options(ac, av);

    cr_assert_str_eq(options_string, "");
    free(options_string);
}

Test(options, options_string_with_supported_flags)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-aRdrt"};
    char *options_string = get_options(ac, av);
    int is_valid = is_options_string_valid(options_string);

    cr_assert_eq(is_valid, 1);
    free(options_string);
}

Test(options, options_string_with_not_supported_flag)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-aRdX"};
    char *options_string = get_options(ac, av);
    int is_valid = is_options_string_valid(options_string);

    cr_assert_neq(is_valid, 1);
    cr_assert_eq(is_valid, 3);
    free(options_string);
}
