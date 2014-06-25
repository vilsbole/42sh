/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:39 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:42 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ftsh.h>

static int		ft_set_print(t_datas *datas)
{
	size_t			i;
	char			**arr;

	i = 0;
	arr = datas->local;
	while (arr[i] != NULL)
	{
		ft_putendl(arr[i]);
		i++;
	}
	return (0);
}

static void		ft_set_checkactions(t_datas *datas, char **cmd)
{
	if (ft_strcmp(cmd[1], "TERM") == 0)
		ft_shell_reload(datas);
	else if (ft_strcmp(cmd[1], "PATH") == 0)
	{
		ft_arrdel(&(datas->path));
		datas->path = ft_strsplit(ft_getenv(datas->local, "PATH"), ':');
	}
}

int				ft_set(t_datas *datas, char **cmd)
{
	int				res;
	char			*tmp;

	if (ft_strcmp(cmd[0], "set") != 0)
		return (-1);
	if (cmd[1] == NULL)
		return (ft_set_print(datas));
	if (ft_strlen(cmd[1]) == 0)
		return (ft_error(FTSH_NAME, cmd[0], "invalid key."));
	if (ft_strcmp(cmd[1], "CWD") == 0 || ft_strcmp(cmd[1], "OWD") == 0
		|| ft_strcmp(cmd[1], "$") == 0 || ft_strcmp(cmd[1], "?") == 0)
		return (ft_error(FTSH_NAME, cmd[0], "locked system variable."));
	if (ft_strcmp(cmd[1], "PATH") == 0)
		tmp = ft_check_path(cmd[2]);
	else
		tmp = cmd[2];
	res = ft_setvar(&(datas->local), cmd[1], tmp);
	if (tmp != cmd[2])
		ft_strdel(&tmp);
	if (res != 0)
		return (ft_error(FTSH_NAME, cmd[0], "memory allocation failed."));
	ft_set_checkactions(datas, cmd);
	return (0);
}
