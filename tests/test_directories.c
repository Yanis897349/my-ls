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
    char *av[] = {"./my_ls", "src/"};
    char **files_path = get_files(ac, av);
    DIR **directories = open_directories(files_path);

    cr_assert_not_null(directories[0]);
    cr_assert_null(directories[1]);
    close_directories(directories);
    free(files_path);
}

Test(directories, multiple_directories) {
    int ac = 3;
    char *av[] = {"./my_ls", "src/", "include/"};
    char **files_path = get_files(ac, av);
    DIR **directories = open_directories(files_path);

    cr_assert_not_null(directories[0]);
    cr_assert_not_null(directories[1]);
    cr_assert_null(directories[2]);
    close_directories(directories);
    free(files_path);
}

Test(directories, invalid_directory) {
    int ac = 2;
    char *av[] = {"./my_ls", "invalid/"};
    char **files_path = get_files(ac, av);
    DIR **directories = open_directories(files_path);

    cr_assert_null(directories[0]);
    close_directories(directories);
    free(files_path);
}

Test(directories, mixed_valid_invalid_directories) {
    int ac = 3;
    char *av[] = {"./my_ls", "src/", "invalid/"};
    char **files_path = get_files(ac, av);
    DIR **directories = open_directories(files_path);

    cr_assert_not_null(directories[0]);
    cr_assert_null(directories[1]);
    close_directories(directories);
    free(files_path);
}
