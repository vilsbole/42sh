/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:14:42 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:14:43 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_move_down(t_datas *datas, t_line *line, char *str)
{
	int		i;

	if (ft_strcmp(str, FTSH_KEY_SHDOWN) != 0)
		return (-1);
	if (line->i + datas->cols > line->len - 1)
	{
		ft_tputs("bl");
		return (1);
	}
	i = 0;
	while (i++ != datas->cols)
		ft_move_right(datas, line, FTSH_KEY_RIGHT);
	return (0);
}
