/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:52:08 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:52:09 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char			*tmp1;
	const unsigned char		*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (n--)
	{
		*tmp1++ = *tmp2++;
		if (*(tmp2 - 1) == (unsigned char)c)
			return (tmp1);
	}
	return (NULL);
}
