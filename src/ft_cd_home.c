/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/01/29 05:45:40 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <libft.h>
#include <42sh.h>
#include <ftcd.h>

int		ft_cd_home(t_datas *datas, char *new, char *path, char *cwd)
{
	char	*tmp;

	tmp = ft_getenv(datas->local, "HOME");
	if (tmp == NULL || ft_strlen(tmp) == 0)
		return (ft_error(FTSH_NAME, "cd", "no HOME variable set."));
	ft_strcpy(new, tmp);
	ft_realpath(new);
	if (path == NULL || ft_strlen(path) == 0 || ft_strcmp(path, "~") == 0)
		return (0);
	if (ft_strlen(new) + ft_strlen(path + 1) >= MAXPATHLEN)
		return (1);
	if (path[0] == '~' && path[1] == '/')
		ft_strcat(new, path + 1);
	else
	{
		ft_bzero(new, MAXPATHLEN);
		return (ft_cd_path(new, path, cwd));
	}
	ft_realpath(new);
	return (0);
}
