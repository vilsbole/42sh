/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrichr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:55:15 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:55:16 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrichr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i-- >= 0)
	{
		if (s[i] == (char)c)
			return (i);
	}
	return (-1);
}
