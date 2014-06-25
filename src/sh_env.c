/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:22:23 by evilsbol          #+#    #+#             */
/*   Updated: 2014/06/25 15:22:26 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static t_env	*new_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env)
	{
		env->cmds = NULL;
		env->envp = NULL;
		env->datas = NULL;
	}
	return (env);
}

t_env			*get_env(void)
{
	static t_env	*env = NULL;

	if (env == NULL)
		env = new_env();
	return (env);
}
