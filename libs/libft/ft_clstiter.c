/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:48:43 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:48:44 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstiter(t_clist *clst, void (*f)(t_clist *elem))
{
	t_clist	*tmp;

	if (!clst)
		return ;
	tmp = clst;
	while (tmp != clst->prev)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
	(*f)(tmp);
}
