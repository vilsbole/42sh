/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:50:36 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:50:37 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_implode_len(char **arr, const char *str)
{
	size_t			i;
	size_t			len;
	size_t			slen;

	i = 0;
	len = 0;
	slen = (size_t)ft_strlen(str);
	while (arr[i] != NULL)
	{
		len += (size_t)ft_strlen(arr[i]);
		if (i > 0)
			len += slen;
		i++;
	}
	return (len);
}

char			*ft_implode(char **arr, const char *str)
{
	size_t			i;
	char			*implode;

	if (!arr)
		return (NULL);
	i = ft_implode_len(arr, str);
	implode = ft_strnew(i);
	if (i == 0)
		return (implode);
	ft_strcpy(implode, arr[0]);
	i = 1;
	while (arr[i] != NULL)
	{
		if (str != NULL)
			ft_strcat(implode, str);
		ft_strcat(implode, arr[i]);
		i++;
	}
	return (implode);
}
