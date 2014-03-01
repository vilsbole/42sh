# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 14:32:09 by mfassi-f          #+#    #+#              #
#    Updated: 2014/03/01 22:23:49 by mfassi-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRN = "\x1b[32;01m"

YLLW = "\x1b[33;01m"

NOCLR = "\x1b[0m"

NAME = libft.a

LIB = libft

FLAGS = -Wextra -Wall -Werror

CC = gcc

AR = ar rc

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strcpy.c ft_strdup.c ft_strcat.c \
	  ft_strncpy.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isdigit.c ft_atoi.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memmove.c ft_strlcat.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strsubsplit.c

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(SRC)
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[all]$(NOCLR) : Compilation of $(LIB)
	@gcc $(FLAGS) -I includes -c $(SRC)
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[all]$(NOCLR) : Creation of Library $(LIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean : 
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[clean]$(NOCLR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[clean]$(NOCLR) : Deleting done !

fclean : clean 
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[fclean]$(NOCLR) : Deleting $(LIB)
	@rm -f $(NAME)
	@echo $(GRN)$(LIB)$(NOCLR)$(YLLW)[fclean]$(NOCLR) : Deleting done !

re : fclean all

.PHONY: clean fclean re all
