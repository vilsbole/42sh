/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_delchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:59 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:03 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_prompt_delchar_bwd(t_datas *datas, t_line *line)
{
	int			i;
	char		*dst;
	char		*src;

	i = 0;
	dst = line->buf + line->i;
	src = line->buf + line->i + 1;
	ft_memmove(dst, src, FTSH_MAXLEN_LINE - (line->i + 1));
	line->i--;
	line->x--;
	if (line->x < 0 && line->y > 0)
	{
		if (--(line->y) == 0)
			line->x = datas->cols - line->plen - 1;
		else
			line->x = datas->cols - 1;
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

static void	ft_prompt_delchar_fwd(t_line *line)
{
	char		*dst;
	char		*src;

	if (line->i == FTSH_MAXLEN_LINE - 2 || line->buf[line->i + 1] == '\0')
		return ;
	dst = line->buf + line->i + 1;
	src = line->buf + line->i + 2;
	ft_memmove(dst, src, FTSH_MAXLEN_LINE - (line->i + 2));
}

void		ft_prompt_delchar(t_datas *datas, t_line *line, int mode)
{
	if (line->len == 0 || (mode == 0 && line->x == 0 && line->y == 0)
		|| (mode == 1 && line->i == line->len - 1))
	{
		ft_tputs("bl");
		return ;
	}
	line->len--;
	if (mode == 0)
		ft_prompt_delchar_bwd(datas, line);
	else if (mode == 1)
		ft_prompt_delchar_fwd(line);
	ft_prompt_reprint(datas, line, 1);
}
