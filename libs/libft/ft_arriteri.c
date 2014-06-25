/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:47:59 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:01 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arriteri(char **arr, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (arr && (*f))
	{
		i = 0;
		while (arr[i] != NULL)
		{
			(*f)(i, arr[i]);
			i++;
		}
	}
}
