/*
** EPITECH PROJECT, 2023
** test_directories
** File description:
** Unit testing opening directories from my_ls
*/

#include "src/Core/directories.h"
#include "src/Core/files.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(directories, unique_directory) {
    int ac = 2;
    char *av[] = {"./my_ls", "src"};
    char **files_path = get_files(ac, av);
    directory_t **directories = open_directories(files_path);

    cr_assert_str_eq(directories[0]->name, "src");
    cr_assert_null(directories[1]);
    free_directories(directories);
    free(files_path);
}
