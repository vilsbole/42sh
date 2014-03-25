	# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 21:34:01 by mfassi-f          #+#    #+#              #
#    Updated: 2014/03/25 00:28:39 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
LIBA = lib42sh.a

FILES = main.c ft_findexe.c ft_error.c ft_signal.c ft_response.c \
		ft_getterm.c ft_getdatas.c ft_getdatas_setenv.c ft_getdatas_setlocal.c \
		ft_cd.c ft_cd_back.c ft_cd_check.c ft_cd_home.c ft_cd_path.c ft_cd_putpath.c \
		ft_cd_update.c \
		ft_env.c ft_env_exec.c ft_env_exit.c ft_env_setav.c ft_env_setep.c ft_env_print.c \
		implemented_function.c \
		ft_getenv.c ft_getlocal.c ft_getvar.c ft_setvar.c ft_delvar.c \
		ft_setenv.c ft_unsetenv.c ft_exit.c ft_color.c ft_echo.c ft_set.c ft_unset.c \
		ft_history.c \
		ft_cmdsplit.c ft_cmdtrim.c ft_parse_vars.c \
		ft_check_daccess.c ft_check_path.c \
		ft_putpath.c ft_tputs.c ft_prompt_autocomplete.c \
		ft_shell_start.c ft_shell_end.c ft_shell_reload.c \
		ft_prompt.c ft_prompt_readentry.c ft_prompt_readkey.c ft_prompt_return.c \
		ft_prompt_ctrld.c ft_prompt_clear.c ft_prompt_print.c ft_prompt_reprint.c \
		ft_prompt_addchar.c ft_prompt_delchar.c ft_prompt_nl.c ft_prompt_ctrlr.c \
		ft_move_left.c ft_move_right.c ft_move_up.c ft_move_down.c \
		ft_move_home.c ft_move_end.c ft_move_prev.c ft_move_next.c \
		ft_history_add.c ft_history_del.c ft_history_prepare.c ft_history_new.c \
		ft_history_prev.c ft_history_next.c \
		ft_pipe.c parser.c execution.c cmds.c t_env.c parser_utils.c ft_redir.c \
		lx_lexer.c lx_tools.c

LPATH =	-L./libs/libft -lft \
		-L./libs/libprt -lprt \
		-L/usr/lib -ltermcap
HPATH = -Iincludes \
		-I./libs/libft/includes \
		-I./libs/libprt/includes \

SRCDIR = ./src/
HEADER = includes/
OBJDIR = .obj
SRCS = $(FILES)
SRC1 = $(addprefix $(SRCDIR), $(SRCS))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
AR = ar -cq
CFLAGS = gcc -Wall -Wextra -Werror -O0 -g3

# COLORS
GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NOCOLOR = "\x1b[0m"

# START RULES
.PHONY: all clean fclean re

all: compile_lib $(NAME)

compile_lib:
	@make -C libs/libft
	@make -C libs/libprt

$(NAME): $(SRC1) $(HEADER)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR):'\t''\t'Compilation of $(NAME)
	@$(CFLAGS) $(HPATH) $(LPATH) $(SRC1) -o $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR):'\t''\t'$(NAME) built !

$(LIBA): $(OBJS)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[lib]$(NOCOLOR):'\t''\t'Creation of $(LIBA)
	@$(AR) $@ $^
	@ranlib $@
	
$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(HPATH) -o $@ -c $^

clean:
	@make clean -C libs/libft
	@make clean -C libs/libprt
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR):'\t''\t'Deleting \'.o\' files
	@rm -rf $(OBJDIR)

fclean:
	@make fclean -C libs/libft
	@make fclean -C libs/libprt
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR):'\t''\t'Deleting \'.o\' files
	@rm -rf $(OBJDIR) 42sh.dSYM
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR):'\t''\t'Deleting $(NAME)
	@rm -rf $(NAME) $(LIBA)

re:	fclean all

# DO NOT DELETE THIS LINE -- make depends on it
