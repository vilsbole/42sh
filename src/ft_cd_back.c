/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_back.c                                       :+:      :+:    :+:   */
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

int		ft_cd_back(t_datas *datas, char *new)
{
	int			len;
	char		*tmp;

	tmp = ft_getenv(datas->local, "OWD");
	len = ft_strlen(tmp);
	if (tmp == NULL || len == 0 || len >= MAXPATHLEN)
		return (1);
	ft_strcpy(new, tmp);
	ft_realpath(new);
	return (0);
}
