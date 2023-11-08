/*
** EPITECH PROJECT, 2023
** test_display
** File description:
** Unit testing display from my_ls
*/

#include "src/Core/files.h"
#include "src/Core/display.h"
#include "src/Helpers/args.h"
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
    char **files_path = get_files_from_args(ac, av);
    file_t **files_list = get_files_list(files_path);

    basic_display(files_list);
    cr_assert_stdout_eq_str("file  test1\n");
    free_files_list(files_list);
    free(files_path);
}
