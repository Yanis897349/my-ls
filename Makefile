##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Build my_ls
##

SRC := ./src/my_ls.c
SRC_TEST := ./tests/test_my_ls.c
CFLAGS := -Wall -Wextra -Werror -I .
NAME_TEST := unit_tests
NAME := my_ls

.PHONY: all clean fclean re tests_run

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

tests_run:
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(NAME_TEST) --coverage -lcriterion
	./$(NAME_TEST)
