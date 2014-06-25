/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:47:19 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:47:33 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_arrdel(char ***arr)
{
	size_t	i;
	char	**tmp;

	if (!arr || !*arr)
		return ;
	i = 0;
	tmp = *arr;
	while (tmp[i] != NULL)
	{
		free((char *)tmp[i]);
		i++;
	}
	free((char **)tmp);
	*arr = NULL;
}
