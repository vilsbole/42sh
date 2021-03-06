/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_files_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:22:50 by evilsbol          #+#    #+#             */
/*   Updated: 2014/06/25 15:22:52 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <ftsh.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

void	files_drredir(t_cmds *tree)
{
	int		i;
	int		fd;
	int		file_fd;
	char	buf[MAXPATHLEN];

	i = 0;
	get_tmpdir(TMP_FILE_R, buf);
	if (tree->drredir && tree->drredir[i])
	{
		fd = open(buf, O_RDONLY);
		while (tree->drredir[i])
		{
			file_fd = open(tree->drredir[i], O_RDWR | O_CREAT | O_APPEND);
			chmod(tree->drredir[i], S_IRWXU);
			get_write_file(buf, file_fd);
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
	char	buf[MAXPATHLEN];

	i = 0;
	get_tmpdir(TMP_FILE_R, buf);
	if (tree->rredir && tree->rredir[i])
	{
		fd = open(buf, O_RDONLY);
		while (tree->rredir[i])
		{
			file_fd = open(tree->rredir[i], O_RDWR | O_CREAT | O_TRUNC);
			chmod(tree->rredir[i], S_IRWXU);
			get_write_file(buf, file_fd);
			close(file_fd);
			i++;
		}
		close(fd);
	}
}
