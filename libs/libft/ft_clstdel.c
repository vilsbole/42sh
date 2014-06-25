/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:35 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:37 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_clstdel(t_clist **aclst, void (*del)(void *, size_t))
{
	t_clist	*tmp;

	(*aclst)->prev->next = NULL;
	(*aclst)->prev = NULL;
	while (*aclst != NULL)
	{
		tmp = *aclst;
		(*del)(tmp->content, tmp->content_size);
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		*aclst = tmp->next;
		free((t_clist *)tmp);
	}
	*aclst = NULL;
}
