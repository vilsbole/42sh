/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:52:00 by evilsbol          #+#    #+#             */
/*   Updated: 2014/01/07 17:45:53 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** to do: fix segfault when int is called with %s instead of %d.
*/

#ifndef LIBPRT_H
# define LIBPRT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define RESET			"\033[0m"
# define BLACK			"\033[30m"			/* Black */
# define RED			"\033[31m"			/* Red */
# define GREEN			"\033[32m"			/* Green */
# define YELLOW			"\033[33m"	 		/* Yellow */
# define BLUE			"\033[34m"			/* Blue */
# define MAGENTA		"\033[35m"			/* Magenta */
# define CYAN			"\033[36m"			/* Cyan */
# define WHITE			"\033[37m"	 		/* White */
# define BOLDBLACK		"\033[1m\033[30m"	/* Bold Black */
# define BOLDRED		"\033[1m\033[31m"	/* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"	/* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"	/* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"	/* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"	/* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"	/* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"	/* Bold White */

/*
** SRC1
*/
size_t	pr_strlen(const char *str);
char	*pr_itoa(int nb);
char	*pr_utoa(unsigned int nb);
char	*pr_otoa(unsigned int nb);
char	*pr_htoa(unsigned long nb);

void	pr_putstr(const char *s1);
void	pr_putnbr(const int nb);
int		pr_putchar(const char c);
int		pr_putint(int c);
int		pr_printchar(va_list ap);
int		pr_printstr(va_list ap);
int		pr_printnbr(va_list ap);
int		pr_printunsigned(va_list ap);
int		pr_printoctal(va_list ap);
int		pr_printhexa(va_list ap);
int		pr_printvoid(va_list ap);

/*
** SRC2
*/
void	pr_putstr_fd(int fd, const char *s1);
void	pr_putnbr_fd(int fd, const int nb);
int		pr_putchar_fd(int fd, const char c);
int		pr_putint_fd(int fd, int c);
int		pr_printchar_fd(int fd, va_list ap);
int		pr_printstr_fd(int fd, va_list ap);
int		pr_printnbr_fd(int fd, va_list ap);
int		pr_printunsigned_fd(int fd, va_list ap);
int		pr_printoctal_fd(int fd, va_list ap);
int		pr_printhexa_fd(int fd, va_list ap);
int		pr_printvoid_fd(int fd, va_list ap);

/*
** SRC3
*/
int		pr_printf(const char *s, ...);
int		pr_printf_fd(int fd, const char *s, ...);

/*
** EXTRA
*/
void	pr_putendl(const char *str);
void	pr_quit(int system, char *e_perso);
void	pr_prompt(char *prompt, char *color);

#endif /* ! LIBPRT_H */
