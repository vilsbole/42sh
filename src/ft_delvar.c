/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:18:21 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:18:24 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static void	ft_delvar_del(char **arr, char *key)
{
	size_t		i;
	int			len;
	char		del;

	i = 0;
	del = 0;
	len = ft_strlen(key);
	while (arr[i] != NULL)
	{
		if (del == 1)
			arr[i] = arr[i + 1];
		else
		{
			if (ft_strncmp(arr[i], key, len) == 0 && arr[i][len] == '=')
			{
				ft_strdel(&(arr[i]));
				arr[i] = arr[i + 1];
				del = 1;
			}
		}
		i++;
	}
}

int			ft_delvar(char **arr, char *key)
{
	if (!arr || !key || ft_strlen(key) == 0)
		return (1);
	if (ft_getenv(arr, key) == NULL)
		return (-1);
	ft_delvar_del(arr, key);
	return (0);
}
