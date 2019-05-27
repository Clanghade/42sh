##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for minishell2
##

SRC =	main.c								\
		./lib/my_strlen.c					\
		./lib/my_putnbr_base.c				\
		./lib/my_putstr.c					\
		./lib/my_getnbr.c					\
		./lib/my_putchar.c					\
		./lib/my_str_isnum.c				\
		./lib/my_strcpy.c					\
		./lib/my_str_to_word_array.c		\
		./minishell1/cd.c					\
		./minishell1/exec_prog.c			\
		./minishell1/error_exe.c			\
		./minishell1/function_echo.c		\
		./minishell1/function_exit.c		\
		./minishell1/get_next_line.c		\
		./minishell1/mysh.c					\
		./minishell1/command.c				\
		./minishell1/setenv.c				\
		./minishell1/useful.c				\
		./minishell2/freedom.c				\
		./minishell2/binary_tree.c			\
		./minishell2/looking_sign.c			\
		./minishell2/run_binary.c 			\
		./minishell2/redirection_left.c		\
		./minishell2/always.c				\
		./my_42sh/quote.c					\
		./my_42sh/separator.c				\
		./my_42sh/variables.c \
		./my_42sh/alias.c \
		./my_42sh/history.c \
		./my_42sh/history2.c \
		./my_42sh/history3.c \
		./my_42sh/replace_word.c \
		init.c \
		./my_42sh/manage_var_alias.c \
		./my_42sh/check_sh.c		\
		./my_42sh/do_if.c			\
		./my_42sh/get_cmd.c			\
		./my_42sh/do_if_cmd.c		\
		./my_42sh/utils_type.c		\
		./my_42sh/fill_cmd.c		\
		./my_42sh/repeat.c			\
		./my_42sh/fill_repeat.c		\
		./my_42sh/glob.c			\
		./my_42sh/utils_strcmp.c	\

CC =	gcc

CFLAGS =	-W -Wextra -Wall -g3

OBJ =	$(SRC:.c=.o)

NAME =	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
