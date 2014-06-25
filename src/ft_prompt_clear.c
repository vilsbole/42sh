/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:50 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:15:52 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

void	ft_prompt_clear(t_datas *datas, t_line *line)
{
	if (line->len == 0)
		return ;
	if (line->i < line->len - 1)
		ft_move_end(datas, line, FTSH_KEY_END);
	while (!(line->x == 0 && line->y == 0))
	{
		ft_move_left(datas, line, FTSH_KEY_LEFT);
		ft_putchar(' ');
		ft_tputs("le");
		if ((line->y == 0 && line->x == datas->cols - line->plen - 1)
			|| (line->y > 0 && line->x == datas->cols - 1))
			ft_tputs("nd");
	}
}
