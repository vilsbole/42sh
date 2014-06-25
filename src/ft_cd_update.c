/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:12:02 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:12:04 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int			ft_cd_update(t_datas *datas, char *opts, char *path, char *cwd)
{
	int			res;

	res = 0;
	if (ft_setvar(&(datas->local), "OWD", cwd) != 0)
		res = ft_error("cd", "can not update local variable", "OWD");
	if (ft_setvar(&(datas->local), "CWD", path) != 0)
		res = ft_error("cd", "can not update local variable", "CWD");
	if (ft_strichr(opts, 'q') >= 0)
		return (res);
	if (ft_setvar(&(datas->env), "OLDPWD", cwd) != 0)
		res = ft_error("cd", "can not update environment variable", "OLDPWD");
	if (ft_setvar(&(datas->env), "PWD", path) != 0)
		res = ft_error("cd", "can not update environment variable", "PWD");
	return (res);
}
