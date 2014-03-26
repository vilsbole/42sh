/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 20:29:39 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/26 19:55:37 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include <libft.h>
#include <42sh.h>
#include <ftcd.h>

int		ft_cd_path(char *new, char *path, char *cwd)
{
	if (ft_strlen(path) >= MAXPATHLEN)
		return (1);
	if (ft_strichr(path, '/') != 0)
	{
		if (ft_strlen(cwd) >= MAXPATHLEN - 1)
			return (1);
		ft_strcpy(new, cwd);
		ft_strcat(new, "/");
		ft_strcat(new, path);
	}
	else
		ft_strcpy(new, path);
	ft_realpath(new);
	return (0);
}
