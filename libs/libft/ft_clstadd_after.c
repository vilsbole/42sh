/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_after.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:23 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:24 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_after(t_clist **aclst, t_clist *new)
{
	if (*aclst == NULL)
	{
		*aclst = new;
		return ;
	}
	if ((*aclst)->prev == NULL && (*aclst)->next == NULL)
	{
		new->prev = *aclst;
		new->next = *aclst;
	}
	else
	{
		new->prev = *aclst;
		new->next = (*aclst)->next;
	}
	new->prev->next = new;
	new->next->prev = new;
	*aclst = new;
}
