/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:53:35 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:53:36 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_realpath(char *path)
{
	size_t	i;
	char	*tmp;
	char	**arr;

	i = 0;
	if (!path || (arr = ft_strsplit(path, '/')) == NULL)
		return (NULL);
	ft_bzero(path, (size_t)ft_strlen(path));
	if (ft_arrsize(arr) <= 0)
		ft_strcat(path, "/");
	while (arr[i] != NULL)
	{
		tmp = ft_strrchr(path, '/');
		if (ft_strcmp(arr[i], "..") == 0 && ft_strrichr(path, '/') > 0)
			*tmp = '\0';
		else if (ft_strcmp(arr[i], ".") != 0)
		{
			ft_strcat(path, "/");
			if (ft_strcmp(arr[i], "..") != 0)
				ft_strcat (path, arr[i]);
		}
		i++;
	}
	ft_arrdel(&arr);
	return (path);
}
