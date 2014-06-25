/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:12:40 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:12:41 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>
#include <ftenv.h>

int		ft_env_exit(t_bltenv *env, int code)
{
	ft_strdel(&(env->exe));
	ft_arrdel(&(env->av));
	ft_arrdel(&(env->ep));
	return (code);
}
