/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:14:44 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:14:45 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_end(t_datas *datas, t_line *line, char *str)
{
	int		i;

	if (ft_strcmp(str, FTSH_KEY_END) != 0)
		return (-1);
	i = line->i;
	if (i == FTSH_MAXLEN_LINE - 2 || line->buf[i + 1] == '\0')
	{
		ft_tputs("bl");
		return (1);
	}
	while (i++ < line->len - 1)
		ft_move_right(datas, line, FTSH_KEY_RIGHT);
	return (0);
}
