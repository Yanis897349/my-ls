##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_ls
##

SRC := ./src/Core/options.c \
	./src/Core/files.c \
	./src/Core/directory.c \
	./src/Core/display.c \
	./src/Core/display_error.c \
	./src/Core/memory.c \
	./src/Core/path.c \
	./src/Helpers/args.c \
	./src/Helpers/sort.c
SRC_TEST := ./tests/test_my_ls.c \
	./tests/test_options.c \
	./tests/test_args.c \
	./tests/test_files.c \
	./tests/test_display.c
MAIN_SRC := ./src/my_ls.c
CFLAGS := -Wall -Wextra -Werror -I. -I./src/ -L . -lmy
LIB_PATH := ./lib/my
NAME_TEST := unit_tests
NAME := my_ls

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run valgrind

all: $(NAME)

build_lib:
	make -C $(LIB_PATH)

clean_lib:
	make clean -C $(LIB_PATH)

fclean_lib:
	make fclean -C $(LIB_PATH)

$(NAME): build_lib
	$(CC) $(MAIN_SRC) $(SRC) $(CFLAGS) -o $(NAME)

clean: clean_lib
	rm -f $(NAME)

fclean: clean fclean_lib tests_clean

re: fclean all

tests_run: build_lib
	$(CC) $(SRC) $(SRC_TEST) $(CFLAGS) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)

valgrind: all
	valgrind -s --leak-check=full --error-exitcode=1 ./$(NAME)

tests_clean:
	rm -f $(NAME_TEST)
	rm -f *.gcno
	rm -f *.gcda
