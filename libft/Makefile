#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 15:37:16 by gchateau          #+#    #+#              #
#    Updated: 2014/01/25 17:51:35 by gchateau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 -pedantic
LFLAGS = -I includes/

FILES = ft_atoi ft_itoa ft_intlen ft_tolower ft_toupper ft_bzero ft_fibonacci \
		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_isspace \
		ft_isupper ft_islower \
		ft_memchr ft_memcmp ft_memcpy ft_memccpy ft_memmove ft_memset \
		ft_memalloc ft_memdel \
		ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd \
		ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd \
		ft_strcat ft_strchr ft_strcmp ft_strccmp ft_strcpy ft_strdup \
		ft_strichr ft_strrichr ft_strlcat ft_strlen ft_strncat ft_strncmp \
		ft_strncpy ft_strnstr ft_strrchr ft_strstr ft_strclr ft_strsub \
		ft_strequ ft_strnequ ft_strnew ft_strdel ft_strfjoin ft_strjoin \
		ft_strtrim ft_strsplit ft_striter ft_striteri ft_strmap ft_strmapi \
		ft_strtolower ft_strtoupper \
		ft_lstnew ft_lstadd ft_lstadd_end ft_lstiter ft_lstdelone ft_lstdel \
		ft_lstlen ft_lstmap \
		ft_clstadd_after ft_clstadd_before ft_clstdel ft_clstdelone \
		ft_clstiter ft_clstlen ft_clstnew \
		ft_dlstadd_after ft_dlstadd_before ft_dlstadd_end ft_dlstadd_first \
		ft_dlstdel ft_dlstdel_fwd ft_dlstdel_rwd ft_dlstdelone \
		ft_dlstiter ft_dlstiter_fwd ft_dlstiter_rwd ft_dlstnew \
		ft_dlstlen ft_dlstlen_fwd ft_dlstlen_rwd \
		ft_arrsize ft_arrnew ft_arradd ft_arrdup ft_arrdel ft_arrfree \
		ft_arridel ft_arriter ft_arriteri \
		ft_realpath ft_implode ft_explode get_next_line

SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) -o $@ $(CFLAGS) $(LFLAGS) -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
