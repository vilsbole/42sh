/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:14:25 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:14:28 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_history_next(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_DOWN) != 0)
		return (-1);
	if (line == NULL || line->prev == NULL)
	{
		ft_tputs("bl");
		return (1);
	}
	ft_prompt_clear(datas, line);
	ft_prompt_print(datas, line->prev);
	datas->prompt.line = line->prev;
	return (0);
}
