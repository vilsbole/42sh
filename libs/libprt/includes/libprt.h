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
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

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

#endif
