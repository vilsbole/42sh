/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_addchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:22:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 18:10:59 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <42sh.h>

static void	ft_prompt_addchar_nl(t_datas *datas, t_line *line)
{
	int			i;

	i = 0;
	while (++i < datas->cols)
		ft_tputs("le");
	ft_tputs("do");
	line->x = 0;
	line->y++;
}

void		ft_prompt_addchar(t_datas *datas, t_line *line, char c)
{
	char		*dst;
	char		*src;

	if (line->len == FTSH_MAXLEN_LINE - 1)
	{
		ft_tputs("bl");
		return ;
	}
	if (line->i + 1 != '\0')
	{
		dst = line->buf + line->i + 2;
		src = line->buf + line->i + 1;
		ft_memmove(dst, src, FTSH_MAXLEN_LINE - (line->i + 1));
	}
	line->buf[++(line->i)] = c;
	ft_putchar(c);
	line->len++;
	line->x++;
	if ((line->y == 0 && line->x == datas->cols - line->plen)
		|| (line->y > 0 && line->x == datas->cols))
		ft_prompt_addchar_nl(datas, line);
	dprintf(datas->debug, "%sADDCHAR:%s\tx: %i\ty: %i\n", FTSH_CYAN, FTSH_COLOR_RESET, line->x, line->y);
	if (line->i != line->len - 1)
		ft_prompt_reprint(datas, line, 0);
}
