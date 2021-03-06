/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:12:15 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:12:17 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_cmdtrim_parse(char *s, int *i, int *quote, int *space)
{
	int			res;
	static int	j = 0;

	if (s[*i] == '"')
	{
		if (*i > 0 && *space == 1 && *quote == 0)
			s[j++] = ' ';
		*quote = (*quote == 0 ? 1 : 0);
		s[j++] = s[(*i)++];
	}
	else if (*quote == 1)
		s[j++] = s[(*i)++];
	else if (ft_isspace(s[*i]) == 0)
	{
		if (j > 0 && *space == 1)
			s[j++] = ' ';
		s[j++] = s[*i];
	}
	*space = ft_isspace(s[*i]);
	res = j;
	if (s[*i + 1] == '\0')
		j = 0;
	return (res);
}

char		*ft_cmdtrim(char *s)
{
	int			i;
	int			j;
	int			space;
	int			quote;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	space = 1;
	quote = 0;
	while (s[i] != '\0')
	{
		j = ft_cmdtrim_parse(s, &i, &quote, &space);
		i++;
	}
	ft_bzero((s + j), i - j);
	return (s);
}
