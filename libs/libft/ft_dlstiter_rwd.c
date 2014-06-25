/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_rwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:08:17 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:08:21 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstiter_rwd(t_dlist *dlst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	tmp = dlst;
	while (tmp != NULL)
	{
		(*f)(tmp);
		tmp = tmp->next;
	}
}
