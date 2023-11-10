/*
** EPITECH PROJECT, 2023
** test_display
** File description:
** Unit testing display from my_ls
*/

#include "Core/files.h"
#include "Core/display.h"
#include "Helpers/args.h"
#include "Helpers/memory.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display, basic_display, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"./my_ls", "tests/test_purposes"};
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = get_files_list(files_path);

    basic_display(files_list);
    cr_assert_stdout_eq_str("AFile  bFile  file  test1  test2\n");
    free_files_list(files_list);
    free(files_path);
}
