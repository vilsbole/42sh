/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:55 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:56 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

void	ft_history_del(t_line **aline)
{
	t_line	*tmp;

	if (!aline || *aline == NULL)
		return ;
	while ((*aline)->prev != NULL)
		*aline = (*aline)->prev;
	while (*aline != NULL)
	{
		tmp = *aline;
		*aline = tmp->next;
		if (*aline != NULL)
			(*aline)->prev = NULL;
		free((t_line *)tmp);
	}
}
