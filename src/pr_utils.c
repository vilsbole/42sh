/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:21:26 by evilsbol          #+#    #+#             */
/*   Updated: 2014/06/25 15:21:30 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

int		nb_semicolon(char **lex)
{
	int	nb;

	nb = 2;
	while (lex && *lex)
	{
		if (!ft_strcmp(*lex, ";"))
			nb++;
		lex++;
	}
	return (nb);
}

int		len_cmd(char **lex)
{
	int	i;

	i = 1;
	while (*lex)
	{
		if (!ft_strcmp(*lex, "|") || !ft_strcmp(*lex, "&&")
				|| !ft_strcmp(*lex, "||") || !ft_strcmp(*lex, ";"))
			break ;
		i++;
		lex++;
	}
	return (i);
}

int		nb_item(char **lex, char *item)
{
	int	i;

	i = 0;
	while (*lex)
	{
		if (!ft_strcmp(*lex, item))
			i++;
		lex++;
	}
	return (i);
}

void	add_token(char **arr, char *token)
{
	arr[ft_arrsize(arr)] = ft_strdup(token);
}

char	**new_arr(int size)
{
	char	**arr;

	arr = (char **)malloc((size) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (size)
		arr[--size] = NULL;
	return (arr);
}
