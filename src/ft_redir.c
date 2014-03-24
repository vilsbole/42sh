/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:16:13 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 12:13:18 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <main.h>
#include <stdio.h>   


char    *get_file_content(int fd)
{
	char        *buf;
	int         ret;
	char        *tmp;
	char        *line;

	if (fd < 0)
		return (NULL);
	buf = ft_strnew(2048);
	line = ft_strnew(2048);
	while ((ret = read(fd, buf, 2048)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
	}
	ft_strdel(&buf);
	return (line);
}

void    no_such_file(char *file)
{
	ft_putstr_fd("42sh: no such file or directory :", 2);
	ft_putendl_fd(file, 2);
}

int     get_write_file(char *file, int fd)
{
	int		file_fd;
	char	*content;

	if ((file_fd = open(file, O_RDONLY)) == -1)
	{
		close(fd);
		no_such_file(file);
		return (-1);
	}
	content = get_file_content(file_fd);
	write(fd, content, ft_strlen(content));
	free(content);
	if (close(file_fd) == -1)
	{
		ft_putstr_fd("close failed\n", 2);
		close(fd);
		return (-1);
	}
	return (0);
}

int ft_redir_left(t_cmds *tree)
{
	int     i;
	int     fd;
	char    *tmp;

	dprintf(2, "left\n");
	if (!tree->lredir || !tree->lredir[0])
		return (0);
	i = 0;
	tmp = ".cartmanlikes42";
	if (!tree->cmd || (tree->cmd && !tree->cmd[0]) 
		|| (tree->father && tree->father->type != PIPE))
		fd = 1;
	else if ((fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC)) == -1)
	{
		ft_putstr_fd("42sh: open failed\n", 2);
		return (-1);
	}
	chmod(tmp, S_IRWXU);
	while (tree->lredir[i])
		if (get_write_file(tree->lredir[i++], fd))
			return (-1);
	close(fd);
	if ((fd = open(tmp, O_RDONLY)) == -1)
	{
		ft_putstr_fd("42sh: open failed\n", 2);
		return (-1);
	}
	if (dup2(fd, 0) == -1)
		ft_putstr_fd("42sh: dup failed\n", 2);
	close(fd);
	return (0);
}

int ft_redir_right(t_cmds *tree)
{
	int fd;

	if (!tree->rredir || (tree->rredir && !tree->rredir[0]))
	{
		dprintf(2, "no-right\n");
		return (0);
	}
	fd = open(tree->rredir[0], O_RDWR | O_TRUNC | O_CREAT);
	if (fd == -1)
	{
		ft_putstr_fd("42sh: open failed\n", 2);
		return (-1);
	}
	chmod(tree->rredir[0], S_IRWXU);
	dup2(fd, 1);
	close(fd);
	return (0);
}
