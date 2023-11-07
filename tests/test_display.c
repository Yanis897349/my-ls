/*
** EPITECH PROJECT, 2023
** test_display
** File description:
** Unit testing display from my_ls
*/

#include "src/Core/directories.h"
#include "src/Core/files.h"
#include "src/Core/display.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display, basic_display, .init = redirect_all_std, .disabled = 1)
{
    int ac = 2;
    char *av[] = {"./my_ls", "tests/test_purposes"};
    char **files_path = get_files(ac, av);
    directory_t **directories = open_directories(files_path);

    basic_display(directories);
    cr_assert_stdout_eq_str("file  test1\n");
    free_directories(directories);
    free(files_path);
}
