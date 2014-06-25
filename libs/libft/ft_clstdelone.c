/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:39 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:40 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_clstdelone(t_clist **aclst, void (*del)(void *, size_t))
{
	t_clist	*tmp;

	tmp = *aclst;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = tmp->next;
		*aclst = tmp->prev;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
		*aclst = tmp->next;
	}
	(*del)(tmp->content, tmp->content_size);
	if (tmp->next == NULL && tmp->prev == NULL)
		*aclst = NULL;
	free((t_clist *)tmp);
}
