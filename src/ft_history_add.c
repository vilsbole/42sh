/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:52 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:53 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

void	ft_history_add(t_datas *datas, t_line *line)
{
	t_line	*tmp;

	if (!line)
		return ;
	if (line->prev != NULL)
		line->prev->next = line->next;
	if (line->next != NULL)
		line->next->prev = line->prev;
	tmp = (line->prev != NULL ? line->prev : line->next);
	ft_history_del(&tmp);
	datas->prompt.line = NULL;
	line->prev = NULL;
	line->next = datas->prompt.history;
	if (datas->prompt.history != NULL)
		datas->prompt.history->prev = line;
	datas->prompt.history = line;
}
