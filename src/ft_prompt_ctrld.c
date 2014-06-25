/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_ctrld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:53 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:15:54 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_prompt_ctrld(t_datas *datas, t_line *line, char *str)
{
	if (ft_strcmp(str, FTSH_KEY_CTRLD) != 0)
		return (-1);
	if (!FLAG_ISTERM(datas->flags) && line == NULL)
	{
		ft_putstr("\b \b\b\n");
		ft_exit(datas, 0);
	}
	if (line == NULL)
		return (1);
	if (line->len == 0)
	{
		ft_putendl("exit");
		if (!FLAG_ISNOENV(datas->flags))
			ft_putstr(FTSH_COLOR_RESET);
		ft_exit(datas, 0);
	}
	else if (line->i == line->len - 1)
		ft_prompt_autocomplete(datas, line, FTSH_KEY_TAB);
	else
		ft_prompt_delchar(datas, line, 1);
	return (0);
}
