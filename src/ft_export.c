/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:15 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:16 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int			ft_export(t_datas *datas, char **cmd)
{
	if (ft_strcmp(cmd[0], "export") != 0)
		return (-1);
	if (cmd[1] == NULL)
	{
		ft_error(FTSH_NAME, "export", "missing argument.");
		ft_error("usage", "export [KEY] (optional [VALUE])", NULL);
		return (1);
	}
	if (cmd[2] == NULL)
		ft_setvar(&(datas->env), cmd[1], ft_getenv(datas->local, cmd[1]));
	else
		ft_setvar(&(datas->env), cmd[1], cmd[2]);
	return (0);
}
