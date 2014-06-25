/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:31 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:33 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd_before(t_clist **aclst, t_clist *new)
{
	if (*aclst == NULL)
	{
		*aclst = new;
		return ;
	}
	if ((*aclst)->prev == NULL && (*aclst)->next == NULL)
	{
		new->next = *aclst;
		new->prev = *aclst;
	}
	else
	{
		new->next = *aclst;
		new->prev = (*aclst)->prev;
	}
	new->next->prev = new;
	new->prev->next = new;
	*aclst = new;
}
