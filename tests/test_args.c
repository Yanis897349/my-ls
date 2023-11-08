/*
** EPITECH PROJECT, 2023
** test_args
** File description:
** Unit testing args parsing from my_ls
*/

#include "src/Helpers/args.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(args, unique_file_arg)
{
    int ac = 2;
    char *av[] = {"./my_ls", "Makefile"};
    char **files_path = get_files_from_args(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_null(files_path[1]);
    free(files_path);
}

Test(args, multiple_files_args)
{
    int ac = 3;
    char *av[] = {"./my_ls", "Makefile", "src"};
    char **files_path = get_files_from_args(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_str_eq(files_path[1], "src");
    cr_assert_null(files_path[2]);
    free(files_path);
}

Test(args, multiple_files_mixed_options_args)
{
    int ac = 4;
    char *av[] = {"./my_ls", "-l", "Makefile", "src"};
    char **files_path = get_files_from_args(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_str_eq(files_path[1], "src");
    cr_assert_null(files_path[2]);
    free(files_path);
}

Test(args, no_file_arg)
{
    int ac = 1;
    char *av[] = {"./my_ls"};
    char **files_path = get_files_from_args(ac, av);

    cr_assert_not_null(files_path[0]);
    free(files_path);
}
