/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:05 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:06 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_prompt_nl(t_datas *datas, t_line *line)
{
	if (line->buf[line->i + 1] == '\0'
		&& ((line->i == 0 && line->buf[line->i] == '\\')
			|| (line->i > 0 && line->buf[line->i] == '\\'
				&& ft_isspace(line->buf[line->i - 1]) == 1)))
	{
		line->plen = ft_strlen(FTSH_PROMPT) + 1;
		line->x = 0;
		line->y = 0;
		line->len--;
		line->buf[line->i--] = '\0';
		ft_putchar('\n');
		if (FLAG_ISCOLOR(datas->flags))
			ft_putstr(FTSH_RED);
		ft_putchar('`');
		ft_putstr(FTSH_PROMPT);
		if (FLAG_ISCOLOR(datas->flags))
		{
			if (!FLAG_ISNOENV(datas->flags))
				ft_putstr(FTSH_HWHITE);
			else
				ft_putstr(FTSH_COLOR_RESET);
		}
		return (1);
	}
	return (0);
}
