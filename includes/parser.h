/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:09:27 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/16 13:15:21 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include <main.h>

typedef struct		s_char
{
	char			c;
	struct s_char	*prev;
	struct s_char	*next;
}					t_char;

typedef struct		s_line
{
	int				x;
	int				nl;
	int				len;
	t_char			*str;
	struct s_line	*prev;
	struct s_line	*next;
}					t_line;

typedef struct		s_datas
{
	int				status;
	char			**env;
	t_line			*history;
}					t_datas;

#endif
