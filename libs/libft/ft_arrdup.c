/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:47:38 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:47:41 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	size_t	len;
	size_t	i;
	char	**new;

	if (!arr)
		return (NULL);
	len = (size_t)ft_arrsize(arr);
	new = ft_arrnew(len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	return (new);
}
