/*
** EPITECH PROJECT, 2023
** test_files
** File description:
** Unit testing getting files stats from my_ls
*/

#include "src/Core/files.h"
#include "src/Core/memory.h"
#include "src/Helpers/args.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(files, unique_file)
{
    int ac = 2;
    char *av[] = {"./my_ls", "src"};
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = get_files_list(files_path);

    cr_assert_str_eq(files_list[0]->path, "src");
    cr_assert_null(files_list[1]);
    free_files_list(files_list);
    free(files_path);
}
