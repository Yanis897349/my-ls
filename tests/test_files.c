/*
** EPITECH PROJECT, 2023
** test_files
** File description:
** Unit testing files parsing from my_ls
*/

#include "src/Core/files.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(files, unique_file)
{
    int ac = 2;
    char *av[] = {"./my_ls", "Makefile"};
    char **files_path = get_files(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_null(files_path[1]);
    free(files_path);
}

Test(files, multiple_files)
{
    int ac = 3;
    char *av[] = {"./my_ls", "Makefile", "src"};
    char **files_path = get_files(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_str_eq(files_path[1], "src");
    cr_assert_null(files_path[2]);
    free(files_path);
}

Test(files, multiple_files_mixed_options)
{
    int ac = 4;
    char *av[] = {"./my_ls", "-l", "Makefile", "src"};
    char **files_path = get_files(ac, av);

    cr_assert_str_eq(files_path[0], "Makefile");
    cr_assert_str_eq(files_path[1], "src");
    cr_assert_null(files_path[2]);
    free(files_path);
}

Test(files, no_file)
{
    int ac = 2;
    char *av[] = {"./my_ls", "-l"};
    char **files_path = get_files(ac, av);

    cr_assert_null(files_path[0]);
}
