/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:05 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:07 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

static int	ft_env_setep_count(char **cmd, int i)
{
	int			n;

	n = 0;
	while (cmd[i] != NULL)
	{
		if (ft_strichr(cmd[i], '=') <= 0)
			return (n);
		n++;
		i++;
	}
	return (n);
}

static int	ft_env_setep_new(t_bltenv *env, char **cmd, int i, int n)
{
	int			j;

	env->ep = ft_arrnew(n);
	if (env->ep == NULL)
		return (-1);
	j = 0;
	while (j < n)
	{
		env->ep[j] = ft_strdup(cmd[i]);
		if (env->ep[j] == NULL)
		{
			ft_arrdel(&(env->ep));
			return (-1);
		}
		j++;
		i++;
	}
	return (i);
}

static int	ft_env_setep_dup(t_bltenv *env, char **cmd, int i, int n)
{
	char		*val;
	char		key[FTSH_MAXLEN_LINE];

	ft_bzero(key, FTSH_MAXLEN_LINE);
	while (n--)
	{
		ft_strncpy(key, cmd[i], ft_strichr(cmd[i], '='));
		val = ft_strchr(cmd[i], '=') + 1;
		if (ft_setvar(&(env->ep), key, val) != 0)
		{
			ft_arrdel(&(env->ep));
			return (-1);
		}
		i++;
	}
	return (i);
}

int			ft_env_setep(t_datas *datas, t_bltenv *env, char **cmd, int i)
{
	int			n;

	env->ep = NULL;
	n = ft_env_setep_count(cmd, i);
	if (n == 0 && ft_strichr(env->opts, 'i') >= 0)
		return (i);
	else if (n != 0 && ft_strichr(env->opts, 'i') >= 0)
		return (ft_env_setep_new(env, cmd, i, n));
	env->ep = ft_arrdup(datas->env);
	if (env->ep == NULL)
		return (-1);
	return (ft_env_setep_dup(env, cmd, i, n));
}
