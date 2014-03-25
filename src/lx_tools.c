/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:24:02 by evilsbol          #+#    #+#             */
/*   Updated: 2014/02/12 16:24:28 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lx_count(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			count++;
	return (count);
}

void	lx_arrayset(char **array, int size)
{
	while (size--)
	{
		if (array[size])
			array[size] = ft_strnew(MAX_SIZE_STR);
	}
}

int		lx_arrsize(char **arr)
{
	int		i;

	i = 0;
	if (arr)
	{
		while (arr[i][0] != '\0')
			i++;
	}
	return (i);
}

char	**lx_arrdup(char **arr)
{
	size_t	len;
	size_t	i;
	char	**new;

	if (!arr)
		return (NULL);
	len = (size_t)lx_arrsize(arr);
	new = ft_arrnew(len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (arr[i][0] == '\0')
			new[i] = NULL;
		else
			new[i] = ft_strdup(arr[i]);
		i++;
	}
	return (new);
}

t_flags	*lx_set_flags(void)
{
	t_flags		*flags;

	flags = NULL;
	if ((flags = (t_flags *)malloc(sizeof(t_flags))))
	{
		flags->index = 0;
		flags->quote = 0;
		flags->token = 0;
		flags->len = 0;
	}
	return (flags);
}