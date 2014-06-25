/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:54:05 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:54:06 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*cpy;

	if (!s)
		return (NULL);
	i = 0;
	cpy = (char *)malloc((ft_strlen(s) + 1) * sizeof(*cpy));
	if (cpy != NULL)
	{
		while (s[i] != '\0')
		{
			cpy[i] = s[i];
			i += 1;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
