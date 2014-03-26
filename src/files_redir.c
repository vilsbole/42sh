/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:51:36 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/26 20:52:42 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <42sh.h>

void	files_drredir(t_cmds *tree)
{
	int		i;
	int		fd;
	int		file_fd;

	i = 0;
	if (tree->drredir && tree->drredir[i])
	{
		fd = open(TMP_FILE_L, O_RDONLY);
		while (tree->drredir[i])
		{
			file_fd = open(tree->drredir[i], O_RDWR | O_CREAT | O_APPEND);
			get_write_file(TMP_FILE_L, file_fd);
			close(file_fd);
			i++;
		}
		close(fd);
	}
}

void	files_rredir(t_cmds *tree)
{
	int		i;
	int		fd;
	int		file_fd;

	i = 0;
	if (tree->rredir && tree->rredir[i])
	{
		fd = open(TMP_FILE_L, O_RDONLY);
		while (tree->rredir[i])
		{
			file_fd = open(tree->rredir[i], O_RDWR | O_CREAT | O_TRUNC);
			get_write_file(TMP_FILE_L, file_fd);
			close(file_fd);
			i++;
		}
		close(fd);
	}
}
