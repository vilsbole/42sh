/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:53:44 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:53:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			chr;

	i = 0;
	chr = c;
	if (chr == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != chr)
	{
		if (s[i] == '\0')
			return (NULL);
		i += 1;
	}
	return ((char *)s + i);
}
