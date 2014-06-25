/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:47:44 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:47:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrfree(char ***arr, size_t size)
{
	size_t	i;
	char	**tmp;

	if (*arr == NULL)
		return ;
	i = 0;
	tmp = *arr;
	while (i < size)
	{
		if (tmp[i] != NULL)
			free((char *)tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free((char **)tmp);
	*arr = NULL;
}
