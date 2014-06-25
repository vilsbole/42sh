/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:28 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:15:29 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

int		ft_move_right(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_RIGHT) != 0)
		return (-1);
	if (line->i == FTSH_MAXLEN_LINE - 2 || line->i == line->len - 1)
	{
		ft_tputs("bl");
		return (1);
	}
	line->i++;
	line->x++;
	if ((line->y == 0 && line->x == datas->cols - line->plen)
		|| (line->y > 0 && line->x == datas->cols))
	{
		ft_tputs("do");
		line->x = 0;
		line->y++;
	}
	else
		ft_tputs("nd");
	return (0);
}
