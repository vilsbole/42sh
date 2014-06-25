/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:57 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:58 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

t_line	*ft_history_new(t_datas *datas)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (new == NULL)
		return (NULL);
	new->i = -1;
	new->x = 0;
	new->y = 0;
	new->len = 0;
	new->plen = datas->prompt.plen;
	new->prev = NULL;
	new->next = NULL;
	ft_bzero(new->buf, FTSH_MAXLEN_LINE);
	return (new);
}
