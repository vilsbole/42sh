/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_addchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:44 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:15:46 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

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
	if (line->buf[line->i + 1] != '\0')
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
	if (line->i != line->len - 1)
		ft_prompt_reprint(datas, line, 0);
}
