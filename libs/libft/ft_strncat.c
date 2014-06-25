/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:54:45 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:54:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (size_t)ft_strlen(dest);
	while (i < n && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i += 1;
	}
	dest[len + i] = '\0';
	return (dest);
}
