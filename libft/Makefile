#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 15:37:16 by gchateau          #+#    #+#              #
#    Updated: 2014/03/24 20:25:02 by mfassi-f         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft

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

GRN = "\x1b[32;01m"
YLLW = "\x1b[33;01m"
NCLR = "\x1b[0m"
RM = rm -f
SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)
LIBNAME = $(NAME).a

all: $(NAME)

$(NAME) : $(SRC)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[all]$(NCLR) : Compilation of $(NAME)
	@gcc $(FLAGS) -I includes -c $(SRC)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[all]$(NCLR) : Creation of Library $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[clean]$(NCLR) : Deleting .o files
	@rm -f $(OBJ)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[clean]$(NCLR) : Deleting done !

fclean : clean
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[fclean]$(NCLR) : Deleting $(NAME)
	@rm -f $(NAME)
	@echo $(GRN)$(NAME)$(NCLR)$(YLLW)[fclean]$(NCLR) : Deleting done !

re : fclean all

.PHONY: clean fclean re all
