/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:14:33 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:14:34 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_history_prev(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_UP) != 0)
		return (-1);
	if (line == NULL || line->next == NULL)
	{
		ft_tputs("bl");
		return (1);
	}
	ft_prompt_clear(datas, line);
	ft_prompt_print(datas, line->next);
	datas->prompt.line = line->next;
	return (0);
}
