/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen_rwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:50:15 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:50:18 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstlen_rwd(t_dlist *dlst)
{
	size_t	n;
	t_dlist	*tmp;

	if (!dlst)
		return (0);
	n = 0;
	tmp = dlst;
	while (tmp != NULL)
	{
		n++;
		tmp = tmp->prev;
	}
	return (n);
}
