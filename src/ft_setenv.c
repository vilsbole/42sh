/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:43 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:45 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

static int	ft_setenv_usage(char **cmd)
{
	if (ft_arrsize(cmd) < 2)
	{
		ft_error(FTSH_NAME, "setenv", "missing argument.");
		ft_putendl_fd("usage: setenv [NAME] [VALUE]", 2);
		return (1);
	}
	return (0);
}

int			ft_setenv(t_datas *datas, char **cmd)
{
	if (ft_strcmp(cmd[0], "setenv") != 0)
		return (-1);
	if (ft_setenv_usage(cmd) != 0)
		return (1);
	if (ft_setvar(&(datas->env), cmd[1], cmd[2]) != 0)
		return (ft_error(FTSH_NAME, "setenv", "memory allocation failed."));
	if (ft_strcmp(cmd[1], "HOME") == 0
		|| (ft_strcmp(cmd[1], "CWD") != 0 && ft_strcmp(cmd[1], "OWD") != 0
			&& ft_strcmp(cmd[1], "$") != 0 && ft_strcmp(cmd[1], "?") != 0
			&& ft_getenv(datas->local, cmd[1]) != NULL
			&& ft_strlen(cmd[1]) > 0))
		ft_set(datas, cmd);
	return (0);
}
