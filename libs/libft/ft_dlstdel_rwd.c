/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_rwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:49:26 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:29 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdel_rwd(t_dlist **adlst, void (*del)(void *, size_t))
{
	t_dlist	*dlst;
	t_dlist	*tmp;

	dlst = (*adlst)->prev;
	while (dlst != NULL)
	{
		tmp = dlst;
		dlst = tmp->prev;
		(*del)(tmp->content, tmp->content_size);
		free((t_dlist *)tmp);
	}
}
