/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:57 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:01 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_before(t_dlist **adlst, t_dlist *new)
{
	if (*adlst != NULL)
	{
		new->next = *adlst;
		new->next->prev = new;
		new->prev = (*adlst)->prev;
		if (new->prev != NULL)
			new->prev->next = new;
	}
	*adlst = new;
}
