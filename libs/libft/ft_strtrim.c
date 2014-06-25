/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:55:44 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:55:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s)
{
	size_t	i;
	size_t	j;
	int		space;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	space = 1;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 0)
		{
			if (j > 0 && space == 1)
				s[j++] = ' ';
			space = 0;
			s[j] = s[i];
			j++;
		}
		else
			space = 1;
		i++;
	}
	ft_bzero((s + j), i - j);
	return (s);
}
