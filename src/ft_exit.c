/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:11 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:13 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

int		ft_exit(t_datas *datas, int code)
{
	ft_shell_end(datas);
	ft_bzero(datas->prompt.buffer, FTSH_MAXLEN_LINE);
	ft_arrdel(&(datas->path));
	ft_arrdel(&(datas->env));
	ft_arrdel(&(datas->local));
	ft_history_del(&(datas->prompt.history));
	if (datas->prompt.line != NULL)
		ft_history_del(&(datas->prompt.line));
	exit(code);
	return (code);
}
