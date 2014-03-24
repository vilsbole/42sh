#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 19:38:04 by evilsbol          #+#    #+#              #
#    Updated: 2014/01/08 17:20:16 by evilsbol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# PROJECT VARIABLES
NAME = $(LIBA)
LIBA = libprt.a

LPATH = -L./ -lprt
HPATH = -Iincludes
SRCS = $(SRC1) $(SRC2) $(SRC3) $(EXTRA)

# Libptr Part I
SRC1 =	pr_htoa.c pr_itoa.c pr_otoa.c pr_utoa.c \
		pr_putchar.c pr_putint.c pr_putstr.c pr_putnbr.c pr_strlen.c \
		pr_printchar.c pr_printhexa.c pr_printnbr.c pr_printoctal.c \
		pr_printstr.c pr_printunsigned.c pr_printvoid.c

SRC2 =	pr_putchar_fd.c pr_putint_fd.c pr_putstr_fd.c pr_putnbr_fd.c \
		pr_printchar_fd.c pr_printhexa_fd.c pr_printnbr_fd.c pr_printoctal_fd.c \
		pr_printstr_fd.c pr_printunsigned_fd.c pr_printvoid_fd.c

SRC3 = pr_printf.c pr_printf_fd.c pr_putendl.c

EXTRA = pr_quit.c pr_prompt.c

# STANDARD VARIABLES
CC = gcc -Wall -Wextra -Werror -g #-pedantic
AR = ar -cq
RM = rm -rf
SRCDIR = srcs
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
NOW := $(shell date +"%c" | tr ' :' '_')

# COLORS
DARK	= \033[1;32m
CYAN	= \033[1;36m
YELLOW	= \033[38;5;3m
RED		= \033[1;31m
WHITE	= \033[0m

# MAKEHELP
LOADING = ./makehelp/loading

# START RULES
.PHONY: all depend clean fclean re build run save

all: $(NAME)
	
$(NAME): $(OBJS)
	@echo "$(YELLOW)linking project lib...$(DARK)"
	@$(AR) $@ $^
	@ranlib $@
	@echo "$(WHITE)$(YELLOW)$(NAME) built$(WHITE)\n"
	
$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(HPATH) -o $@ -c $^

clean:
	@echo "$(YELLOW)removing $(OBJDIR)...$(WHITE)"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)removing $(NAME)...$(WHITE)"
	@$(RM) $(NAME)

re: fclean
	@make all

# Personnal rules
save:
	@git add --all
	@git commit -m 'saving $(NOW)'
	@echo "$(YELLOW)all files added and commited$(WHITE)"

run:
	@make all
	@echo "$(YELLOW)TEST BEGIN\n $(WHITE)"
	@./$(NAME) $(TEST)
	@echo "$(YELLOW) \nTEST END $(WHITE)"

# DO NOT DELETE THIS LINE -- make depends on it
