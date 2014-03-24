/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 17:23:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 14:01:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <free_arr.h>
#include <stdio.h>
#include <main.h>

void	free_arr(char ***arr)
{
	int	i;

	i = 0;
	while (arr && *arr && (*arr)[i])
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
