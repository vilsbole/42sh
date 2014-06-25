/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:12:58 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:01 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_print(char **env)
{
	int		i;

	i = 0;
	if (env == NULL)
		return (0);
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}
