##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_ls
##

SRC := ./src/my_ls.c
SRC_TEST := ./tests/test_my_ls.c
CFLAGS := -Wall -Wextra -Werror -I . -L . -lmy
NAME_TEST := unit_tests
NAME := my_ls

.PHONY: all build_lib clean_lib fclean_lib clean fclean re tests_run

all: $(NAME)

build_lib:
	make -C ./lib/my

clean_lib:
	make clean -C ./lib/my

fclean_lib:
	make fclean -C ./lib/my

$(NAME): build_lib
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L./lib/my -lmy

clean: clean_lib
	rm -f $(NAME)

fclean: clean fclean_lib

re: fclean all

tests_run:
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)
