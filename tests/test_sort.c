/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Test sort functions
*/

#include "Helpers/sort.h"
#include "Helpers/args.h"
#include "Core/files.h"
#include "Core/memory.h"
#include "Core/path.h"
#include <criterion/criterion.h>

Test(sort, basic_number_sort)
{
    int ac = 2;
    char *av[] = {"./my_ls", "tests/test_purposes"};
    char *sorted[] = {"AFile", "bFile", "file",
        "test1", "test2", NULL};
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = get_files_list(files_path);
    char *filename = NULL;

    sort_alphabetically(files_list);
    for (int i = 2; files_list[i] != NULL; i++) {
        filename = extract_name_from_path(files_list[i]->path);
        cr_assert_str_eq(filename, sorted[i]);
    }
    free_files_list(files_list);
    free(files_path);
}
