/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:49:31 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:33 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdelone(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	tmp = *adlst;
	if (tmp->prev != NULL)
	{
		tmp->prev->next = tmp->next;
		*adlst = tmp->prev;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
		*adlst = tmp->next;
	}
	(*del)(tmp->content, tmp->content_size);
	if (tmp->prev == NULL && tmp->next == NULL)
		*adlst = NULL;
	free((t_dlist *)tmp);
}
