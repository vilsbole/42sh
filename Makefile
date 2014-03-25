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

FILES = main ft_findexe ft_error ft_signal ft_response \
		ft_getterm ft_getdatas ft_getdatas_setenv ft_getdatas_setlocal \
		ft_cd ft_cd_back ft_cd_check ft_cd_home ft_cd_path ft_cd_putpath  \
		ft_cd_update \
		ft_env ft_env_exec ft_env_exit ft_env_setav ft_env_setep ft_env_print \
		implemented_function \
		ft_getenv ft_getlocal ft_getvar ft_setvar ft_delvar \
		ft_setenv ft_unsetenv ft_exit ft_color ft_echo ft_set ft_unset \
		ft_history \
		ft_cmdsplit ft_cmdtrim ft_parse_vars \
		ft_check_daccess ft_check_path \
		ft_putpath ft_tputs ft_prompt_autocomplete \
		ft_shell_start ft_shell_end ft_shell_reload \
		ft_prompt ft_prompt_readentry ft_prompt_readkey ft_prompt_return \
		ft_prompt_ctrld ft_prompt_clear ft_prompt_print ft_prompt_reprint \
		ft_prompt_addchar ft_prompt_delchar ft_prompt_nl ft_prompt_ctrlr \
		ft_move_left ft_move_right ft_move_up ft_move_down \
		ft_move_home ft_move_end ft_move_prev ft_move_next \
		ft_history_add ft_history_del ft_history_prepare ft_history_new \
		ft_history_prev ft_history_next \
		ft_pipe parser execution cmds t_env parser_utils ft_redir \
		lx_lexer lx_tools

LPATH =	-L./ -l42sh \
		-L./libs/libft -lft \
		-L./libs/libprt -lprt \
		-L/usr/lib -ltermcap
HPATH = -Iincludes \
		-I./libs/libft/includes \
		-I./libs/libprt/includes \

SRCDIR = src
OBJDIR = obj
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
AR = ar -cq
CFLAGS = gcc -Wall -Wextra -Werror -O0 -g3

# COLORS
GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NOCOLOR = "\x1b[0m"

# START RULES
.PHONY: all clean fclean re

all: $(NAME)

compile_lib:
	@make -C libs/libft
	@make -C libs/libprt

$(NAME): compile_lib $(LIBA)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation of $(NAME)
	@$(CFLAGS) $(HPATH) $(LPATH) -o $(NAME)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[all]$(NOCOLOR) : Compilation done !

$(LIBA): $(OBJS)
	@echo "$(YELLOW)linking project lib...$(DARK)"
	@$(AR) $@ $^
	@ranlib $@
	@echo "$(WHITE)$(YELLOW)$(NAME) built$(WHITE)\n"
	
$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(HPATH) -o $@ -c $^

clean:
	@make clean -C libs/libft
	@make clean -C libs/libprt
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting .o files
	@rm -f $(OBJS)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !

fclean: clean
	@make fclean -C libs/libft
	@make fclean -C libs/libprt
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[clean]$(NOCOLOR) : Deleting done !
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting $(NAME)
	@rm -f $(NAME) $(LIBA)
	@echo $(GRN)$(NAME)$(NOCOLOR)$(YLLW)[fclean]$(NOCOLOR) : Deleting done !

re:	fclean all

# DO NOT DELETE THIS LINE -- make depends on it
