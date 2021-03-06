/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:50:40 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:50:41 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_count(unsigned int n, int i)
{
	if (n >= 10)
		return (ft_intlen_count(n / 10, i + 1));
	else
		return (i + 1);
	return (0);
}

int			ft_intlen(int n)
{
	int				len;
	unsigned int	tmp;

	tmp = (n < 0) ? (n * -1) : n;
	len = ft_intlen_count(tmp, 0);
	len += (n < 0) ? 1 : 0;
	return (len);
}
