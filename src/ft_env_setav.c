/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_setav.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:03 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:04 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_setav(t_bltenv *env, char **cmd, int i)
{
	int		j;
	int		n;

	n = 0;
	j = i;
	while (cmd[j++] != NULL)
		n++;
	env->av = ft_arrnew(n);
	if (env->av == NULL)
		return (ft_error(FTSH_NAME, "env", "memory allocation failed."));
	j = 0;
	while (cmd[i] != NULL)
	{
		env->av[j] = ft_strdup(cmd[i]);
		if (env->av[j] == NULL)
		{
			ft_arrdel(&(env->av));
			return (ft_error(FTSH_NAME, "env", "memory allocation failed"));
		}
		j++;
		i++;
	}
	return (0);
}
