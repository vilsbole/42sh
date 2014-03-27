/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:22:43 by evilsbol          #+#    #+#             */
/*   Updated: 2014/03/27 04:42:42 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include "libft.h"

# define S_NAME	"[msh]"
# define PROMPT "[msh] > "
# define COMMANDS "cd ls cat echo"
# define OPR "<>|&;"
# define ARGS "\"\'\\"
# define BLANK " \t"
# define WORD "<>|&;\\\"\'\\ \t"
# define BSLASH "$`\"\\\n"
# define MAX_SIZE_STR	1024
# define MAX_SIZE_ARG	512

typedef struct	s_flags
{
	int		index;
	int		quote;
	int		token;
	int		len;
}				t_flags;

/*
** lx_exec
*/
char		**lx_lexer(char *line);
int			lx_count(char *str, char c);
void		lx_arrayset(char **array, int size);
int			lx_arrsize(char **arr);
char		**lx_arrdup(char **arr);
t_flags		*lx_set_flags(void);

#endif /* !LEXER_H */
