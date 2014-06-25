/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:49:17 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:18 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_first(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*adlst != NULL)
	{
		tmp = *adlst;
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		new->next = tmp;
		tmp->prev = new;
	}
	*adlst = new;
}
