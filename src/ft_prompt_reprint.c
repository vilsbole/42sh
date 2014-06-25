/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_reprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:20 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:21 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_prompt_reprint_put(t_datas *datas, t_line *line, \
	int *x, int *y)
{
	int			i;
	int			j;

	i = line->i + 1;
	while (line->buf[i] != '\0')
	{
		ft_putchar(line->buf[i]);
		(*x)++;
		if ((*y == 0 && *x == datas->cols - line->plen)
			|| (*y > 0 && *x == datas->cols))
		{
			j = 0;
			while (++j < datas->cols)
				ft_tputs("le");
			ft_tputs("do");
			*x = 0;
			(*y)++;
		}
		i++;
	}
}

static void	ft_prompt_reprint_le(t_datas *datas, t_line *line, int *x, int *y)
{
	int			i;

	i = 0;
	(*x)--;
	if (*y > 0 && *x == -1)
	{
		if (--(*y) == 0)
			*x = datas->cols - line->plen - 1;
		else
			*x = datas->cols - 1;
		if (tgetflag("bw") == 0)
		{
			ft_tputs("up");
			while (++i < datas->cols)
				ft_tputs("nd");
			return ;
		}
	}
	ft_tputs("le");
}

void		ft_prompt_reprint(t_datas *datas, t_line *line, int dc)
{
	int			x;
	int			y;

	x = line->x;
	y = line->y;
	if (line->len != 0 && line->i != line->len - 1)
		ft_prompt_reprint_put(datas, line, &x, &y);
	if (dc == 1)
	{
		ft_putchar(' ');
		ft_tputs("le");
		if ((y == 0 && x == datas->cols - line->plen - 1)
			|| (y > 0 && x == datas->cols - 1))
			ft_tputs("nd");
	}
	while (!(x == line->x && y == line->y))
		ft_prompt_reprint_le(datas, line, &x, &y);
}
