/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:35:07 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/27 06:45:58 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <42sh.h>
#include <libft.h>

char	*get_tmpdir(char *file, char *buf)
{
	int	fd;

	fd = open("/tmp", O_RDONLY);
	fcntl(fd, F_GETPATH, buf);
	close(fd);
	ft_strcat(buf, file);
	return (buf);
}

void	parser_new_cmd(t_cmds **current_node, int *is_new_cmd, char **lex)
{
	if (*is_new_cmd)
	{
		(*current_node)->cmd = new_arr(len_cmd(lex));
		(*current_node)->rredir = new_arr((nb_item(lex, ">")) + 1);
		(*current_node)->lredir = new_arr((nb_item(lex, "<")) + 1);
		(*current_node)->drredir = new_arr((nb_item(lex, ">>")) + 1);
		*is_new_cmd = FALSE;
	}
}
