/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:51:22 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:51:27 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_fillstr(unsigned int n, char *ptr, int i)
{
	if (n > 9)
		ft_itoa_fillstr(n / 10, ptr, i - 1);
	ptr[i] = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	unsigned int	tmp;
	int				len;
	char			*str;

	tmp = (n < 0) ? (n * -1) : n;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_itoa_fillstr(tmp, str, len - 1);
	return (str);
}
