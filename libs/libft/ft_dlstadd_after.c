/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:53 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:54 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_after(t_dlist **adlst, t_dlist *new)
{
	if (*adlst != NULL)
	{
		new->prev = *adlst;
		new->prev->next = new;
		new->next = (*adlst)->next;
		if (new->next != NULL)
			new->next->prev = new;
	}
	*adlst = new;
}
