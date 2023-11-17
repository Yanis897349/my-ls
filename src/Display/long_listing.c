/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Long listing format
*/

#include "Core/files.h"
#include "Core/options.h"
#include "Display/symbolic.h"
#include "Helpers/path.h"
#include "include/my_strings.h"
#include "include/my_io.h"
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/sysmacros.h>

static void print_permissions(file_t *file)
{
    my_putstr((file->stat->st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((file->stat->st_mode & S_IWUSR) ? "w" : "-");
    if (file->stat->st_mode & S_ISUID)
        my_putstr((file->stat->st_mode & S_IXUSR) ? "s" : "S");
    else
        my_putstr((file->stat->st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((file->stat->st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((file->stat->st_mode & S_IWGRP) ? "w" : "-");
    if (file->stat->st_mode & S_ISGID)
        my_putstr((file->stat->st_mode & S_IXGRP) ? "s" : "S");
    else
        my_putstr((file->stat->st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((file->stat->st_mode & S_IROTH) ? "r" : "-");
    my_putstr((file->stat->st_mode & S_IWOTH) ? "w" : "-");
    if (file->stat->st_mode & S_ISVTX)
        my_putstr((file->stat->st_mode & S_IXOTH) ? "t " : "T ");
    else
        my_putstr((file->stat->st_mode & S_IXOTH) ? "x " : "- ");
}

static void print_time(file_t *file)
{
    char *str = ctime(&file->stat->st_mtime);
    char **time_array = my_str_to_word_array(str);

    my_putchar(' ');
    my_putstr(time_array[1]);
    my_putchar(' ');
    my_putstr(time_array[2]);
    my_putchar(' ');
    my_putstr(time_array[3]);
    my_putchar(':');
    my_putstr(time_array[4]);
    my_putchar(' ');
    for (int i = 0; time_array[i] != NULL; i++)
        free(time_array[i]);
    free(time_array);
}

static void print_char_device(file_t *file)
{
    my_put_nbr(major(file->stat->st_rdev));
    my_putstr(", ");
    my_put_nbr(minor(file->stat->st_rdev));
}

static void print_long_file(file_t *file, int is_in_directory)
{
    char filetype = get_filetype(file);

    my_putchar(get_filetype(file));
    print_permissions(file);
    my_put_nbr(file->stat->st_nlink);
    my_putchar(' ');
    my_putstr(getpwuid(file->stat->st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(file->stat->st_gid)->gr_name);
    my_putchar(' ');
    if (filetype == 'c' || filetype == 'b')
        print_char_device(file);
    else
        my_put_nbr(file->stat->st_size);
    print_time(file);
    handle_symbolic(file, filetype, is_in_directory);
}

static void print_long_directory(file_t *file)
{
    my_putstr(file->path);
    my_putstr(":\n");
    for (int i = 0; file->content[i] != NULL; i++) {
        print_long_file(file->content[i], 1);
        my_putchar('\n');
    }
}

static int handle_long_listing_special(file_t **files_list,
    options_t *options)
{
    int is_special = 0;

    if (options->is_recursive)
        return is_special;
    if (files_list[0]->is_directory && files_list[1] == NULL) {
        is_special = 1;
        for (int i = 0; files_list[0]->content[i] != NULL; i++) {
            print_long_file(files_list[0]->content[i], 1);
            my_putchar('\n');
        }
    }
    return is_special;
}

void long_listing_file(file_t **files_list, int *have_directory)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        if (files_list[i]->is_directory) {
            (*have_directory) = 1;
            continue;
        }
        print_long_file(files_list[i], 0);
        my_putchar('\n');
    }
}

void long_listing_directories(file_t **files_list, options_t *options)
{
    for (int i = 0; files_list[i] != NULL; i++) {
        if (!files_list[i]->is_directory) {
            continue;
        }
        print_long_directory(files_list[i]);
        my_putchar('\n');
        if (options->is_recursive)
            long_listing_directories(files_list[i]->content, options);
    }
}

void handle_long_listing(file_t **files_list, options_t *options)
{
    int have_directory = 0;

    if (handle_long_listing_special(files_list, options))
        return;
    long_listing_file(files_list, &have_directory);
    if (!have_directory)
        return;
    my_putchar('\n');
    long_listing_directories(files_list, options);
}
