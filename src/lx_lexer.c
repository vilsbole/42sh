/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslimane <kslimane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 23:12:47 by kslimane          #+#    #+#             */
/*   Updated: 2014/03/27 06:20:05 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lx_scanner(char *line, char **data)
{
	int			i;
	t_flags		*flags;

	i = -1;
	flags = lx_set_flags();
	while (line[++i])
	{
		if (flags->quote == 0 && lx_count(BLANK, line[i]))
		{
			lx_closetok(data, flags);
			i++;
		}
		if (flags->quote == 0 && (lx_tokopr(data, &line[i], flags) || line[i] == ';'))
			i++;
		if (line[i] == '\\')
			i += lx_backslash(data, &line[i], flags);
		i += lx_flags(line[i], flags);
		if (flags->quote == 2)
			i += lx_squote(data, &line[i], flags);
		if (flags->quote == 1)
			i += lx_dquote(data, &line[i], flags);
		if (line[i] == '\n')
			lx_closetok(data, flags);
		if (line[i] && flags->quote == 0 && lx_count(WORD, line[i]) == 0)
			lx_addtoword(data, line[i], flags);
	}
	if (flags)
		free(flags);
	if (lx_endinput(data, flags))
		return (-1);
	return (0);
}

char		**lx_lexer(char *line)
{
	int		i;
	char	**data;
	char	**res;

	i = 0;
	if (!(data = ft_arrnew(512)))
		ft_putendl("42sh : Oups, a malloc failed");
	ft_arrayset(data, 512);
	if (lx_scanner(line, data))
		ft_arrdel(&data);
	if (data)
	{
		while (data[i] && data[i][0])
			ft_putstr(data[i++]);
		res = lx_arrdup(data);
		ft_arrdel(&data);
		return (res);
	}
	return (NULL);
}
