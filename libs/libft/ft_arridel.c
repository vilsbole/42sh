/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arridel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:47:48 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:47:50 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_arridel(char ***arr, size_t index)
{
	size_t	siz;
	size_t	i;
	char	**new;

	if (*arr == NULL || (siz = (size_t)ft_arrsize(*arr)) == 0)
		return (-1);
	if (index >= siz)
		return (1);
	i = 0;
	new = ft_arrnew(siz - 1);
	while ((*arr)[i] != NULL)
	{
		if (i != index)
			new[i] = (*arr)[i];
		else
			free((char *)arr[i]);
		i++;
	}
	ft_arrdel(arr);
	*arr = new;
	return (0);
}
