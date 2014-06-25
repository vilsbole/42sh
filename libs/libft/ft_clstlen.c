/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:46 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:47 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_clstlen(t_clist *clst)
{
	size_t	n;
	t_clist	*tmp;

	if (!clst)
		return (0);
	n = 1;
	tmp = clst->next;
	while (tmp != NULL && tmp != clst)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}
