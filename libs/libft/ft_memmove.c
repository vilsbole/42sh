/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:52:45 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:52:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_memmove_bwd(unsigned char *s1, const unsigned char *s2, size_t n)
{
	size_t				i;

	i = n - 1;
	while (i--)
		s1[i] = s2[i];
}

static void	ft_memmove_fwd(unsigned char *s1, const unsigned char *s2, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
}

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	if (n == 0)
		return (s1);
	tmp1 = s1;
	tmp2 = s2;
	if (tmp1 < tmp2)
		ft_memmove_fwd(tmp1, tmp2, n);
	else if (tmp1 > tmp2)
		ft_memmove_bwd(tmp1, tmp2, n);
	return (s1);
}
