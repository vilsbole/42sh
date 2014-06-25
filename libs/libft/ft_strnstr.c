/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:55:03 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:55:04 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while ((i + j) < n && j < (size_t)ft_strlen(s2)
					&& s1[i + j] == s2[j])
			{
				j += 1;
				if (s2[j] == '\0')
					return ((char *)s1 + i);
			}
		}
		i += 1;
	}
	return (NULL);
}
