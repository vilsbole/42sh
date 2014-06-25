/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:14:47 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:14:49 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_home(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_HOME) != 0)
		return (-1);
	if (line->x == 0 && line->y == 0)
	{
		ft_tputs("bl");
		return (1);
	}
	while (!(line->x == 0 && line->y == 0))
		ft_move_left(datas, line, FTSH_KEY_LEFT);
	return (0);
}
