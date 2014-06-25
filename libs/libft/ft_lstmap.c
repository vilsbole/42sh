/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:51:58 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:52:00 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;
	t_list	*first;

	first = NULL;
	prev = NULL;
	while (lst != NULL)
	{
		new = (*f)(lst);
		if (new == NULL)
			return (NULL);
		if (!first)
		{
			first = new;
			first->next = NULL;
		}
		else if (first && first->next == NULL)
			first->next = new;
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}
