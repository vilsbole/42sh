# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2014/03/24 12:10:34 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

SRC_FILES = get_line.c main.c get_next_line.c free_arr.c search_path.c \
				ft_env.c ft_cd1.c ft_cd2.c utils.c ft_setenv.c ft_unsetenv.c \
				t_env.c parser.c ft_findexe.c ft_error.c ft_getenv.c ft_redir.c\
				execution.c ft_pipe.c cmds.c parser_utils.c

LIBFT_NAME = libft.a

LIBFT_DIR = ./libft
LIB = $(LIBFT_DIR)/$(LIBFT_NAME)
HPATH = -Iincludes -I$(LIBFT_DIR)/includes
CFLAGS = gcc -Wall -Wextra -Werror -O0 -g
SRC_PATH = ./src/
HEADER = includes/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NOCOLOR = "\x1b[0m"

all: compile_lib $(NAME)

compile_lib:
	@make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(HEADER)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation of $(NAME)
	@$(CFLAGS) $(HPATH) $(LIB) $(GRAPH_LIB) $(SRC) -o $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation done !

clean:
	@make clean -C $(LIBFT_DIR)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !

fclean:
	@make fclean -C $(LIBFT_DIR)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting done !

re:	fclean all compile_lib

.PHONY: clean
