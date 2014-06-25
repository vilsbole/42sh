/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:55:55 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:55:57 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static int		ft_gnl_setline(char **buffer, char **line)
{
	int				i;

	i = ft_strichr(*buffer, '\n');
	if (i < 0 && *line == NULL)
	{
		*line = ft_strdup(*buffer);
		return (0);
	}
	else if (i == 0 && *line == NULL)
		*line = ft_strnew(1);
	else if (i > 0)
	{
		if (*line == NULL)
			*line = ft_strsub(*buffer, 0, i);
		else
			*line = ft_strfjoin(*line, ft_strsub(*buffer, 0, i));
	}
	ft_strcpy(*buffer, ft_strchr(*buffer, '\n') + 1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	*line = NULL;
	buffer = ((!buffer) ? ft_strnew(BUFF_SIZE + 1) : buffer);
	if (ft_gnl_setline(&buffer, line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strichr(buf, '\n') >= 0)
		{
			ft_strcpy(buffer, buf);
			return (ft_gnl_setline(&buffer, line));
		}
		*line = ft_strfjoin(*line, ft_strdup(buf));
	}
	free(buffer);
	if (ft_strlen(*line) > 0)
		return (1);
	if (ret <= 0)
		return (ret);
	return (0);
}
