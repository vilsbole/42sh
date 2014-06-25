/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:19:36 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:19:37 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

int		ft_move_left_up(t_datas *datas)
{
	int		i;

	i = 0;
	ft_tputs("up");
	while (++i < datas->cols)
		ft_tputs("nd");
	return (0);
}

int		ft_move_left(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_LEFT) != 0)
		return (-1);
	if (line->x == 0 && line->y == 0)
	{
		ft_tputs("bl");
		return (1);
	}
	line->i--;
	line->x--;
	if (line->y > 0 && line->x == -1)
	{
		if (--(line->y) == 0)
			line->x = datas->cols - line->plen - 1;
		else
			line->x = datas->cols - 1;
		if (tgetflag("bw") == 0)
			return (ft_move_left_up(datas));
	}
	ft_tputs("le");
	return (0);
}
