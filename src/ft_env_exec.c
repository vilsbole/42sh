/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:12:35 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:12:36 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_exec(t_datas *datas, t_bltenv *env)
{
	pid_t	pid;

	env->exe = ft_findexe(datas->path, env->av[0]);
	if (env->exe == NULL)
		return (1);
	if ((pid = fork()) < 0)
	{
		ft_error(FTSH_NAME, "env", "new processus failed.");
		return (ft_env_exit(env, 1));
	}
	else if (pid == 0)
	{
		if (execve(env->exe, env->av, env->ep) < 0)
			exit(ft_error(FTSH_NAME, "env", "execution failed."));
	}
	else
	{
		waitpid(pid, &(datas->status), 0);
		ft_response(datas);
		return (ft_env_exit(env, 0));
	}
	return (0);
}
