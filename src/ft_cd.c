/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/24 17:18:26 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <unistd.h>
#include <libft.h>
#include <42sh.h>
#include <ftcd.h>

static int	ft_cd_usage(char **cmd, int i)
{
	if (cmd[i] != NULL && cmd[i + 1] != NULL)
	{
		ft_error(FTSH_NAME, "cd", "too many arguments.");
		return (ft_error("usage", FTSH_BLT_USAGE, NULL));
	}
	return (0);
}

static int	ft_cd_check_opts(char *str, char *opts)
{
	int			i;
	char		tmp[20];

	i = 1;
	ft_bzero(tmp, 20);
	while (str[i] != '\0')
	{
		if (ft_strichr(FTSH_BLT_OPTS, str[i]) >= 0)
		{
			if (ft_strichr(opts, str[i]) < 0)
				opts[ft_strlen(opts)] = str[i];
		}
		else
		{
			ft_strcpy(tmp, "illegal option -- ");
			tmp[18] = str[i];
			ft_error("cd", tmp, NULL);
			return (ft_error("Usage", FTSH_BLT_USAGE, NULL));
		}
		i++;
	}
	return (0);
}

static int	ft_cd_get_opts(char **cmd, char *opts)
{
	int			i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (ft_strcmp(cmd[i], "-") == 0 || ft_strichr(cmd[i], '-') != 0)
			return (i);
		if (ft_strcmp(cmd[i], "--") == 0)
			return (i + 1);
		if (ft_cd_check_opts(cmd[i], opts) != 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	ft_cd2(char *opts, char *str, char *new, char *old)
{
	t_datas		*datas;

	datas = ft_getdatas(NULL);
	if (datas == NULL)
		return (ft_error(FTSH_NAME, "cd", "internal error."));
	if (ft_cd_check(new) != 0)
		return (1);
	if ((str != NULL && ft_strcmp(str, "-") == 0)
		|| ft_strichr(opts, 'l') >= 0 || ft_strichr(opts, 'n') >= 0
		|| ft_strichr(opts, 'p') >= 0 || ft_strichr(opts, 'v') >= 0)
		ft_cd_putpath(datas, opts, new);
	return (ft_cd_update(datas, opts, new, old));
}

int			ft_cd(t_datas *datas, char **cmd)
{
	int			i;
	int			res;
	char		new[MAXPATHLEN];
	char		cwd[MAXPATHLEN];
	char		opts[FTSH_BLT_MAXOPTS + 1];

	if (ft_strcmp(cmd[0], "cd") != 0)
		return (-1);
	ft_bzero(new, MAXPATHLEN);
	ft_bzero(cwd, MAXPATHLEN);
	ft_bzero(opts, FTSH_BLT_MAXOPTS + 1);
	if (getcwd(cwd, MAXPATHLEN) == NULL)
		return (ft_error("cd", "can not get current working directory.", NULL));
	i = ft_cd_get_opts(cmd, opts);
	if (i == -1 || ft_cd_usage(cmd, i) != 0)
		return (1);
	if (cmd[i] == NULL || ft_strichr(cmd[i], '~') == 0)
		res = ft_cd_home(datas, new, cmd[i], cwd);
	else if (ft_strcmp(cmd[i], "-") == 0)
		res = ft_cd_back(datas, new);
	else
		res = ft_cd_path(new, cmd[i], cwd);
	if (res != 0)
		return (res);
	return (ft_cd2(opts, cmd[i], new, cwd));
}
