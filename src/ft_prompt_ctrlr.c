/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_ctrlr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:15:56 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:15:58 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_prompt_ctrlr(t_datas *datas, t_line *line, char *str)
{
	(void)datas;
	(void)line;
	if (ft_strcmp(str, FTSH_KEY_CTRLR) != 0)
		return (-1);
	ft_tputs("bl");
	return (0);
}
