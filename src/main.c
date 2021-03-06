/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 18:01:59 by evilsbol          #+#    #+#             */
/*   Updated: 2014/06/26 18:02:01 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ftsh.h>
#include "lexer.h"

static void	ft_parser_load(t_datas *datas)
{
	char		**tmp;

	tmp = lx_lexer(datas->prompt.buffer);
	get_env()->cmds = parser(tmp);
	ft_arrdel(&tmp);
	if (!get_env()->cmds)
		return ;
	exec_trees();
	dup2(get_env()->fd_in, 0);
	dup2(get_env()->fd_out, 1);
}

int			main(int ac, char **av, char **ep)
{
	t_datas		*datas;

	(void)ac;
	(void)av;
	datas = ft_getdatas(ep);
	if (datas == NULL)
		return (ft_error(FTSH_NAME, "running failed.", NULL));
	ft_signal();
	while (42)
	{
		ft_shell_start(datas);
		if (ft_prompt(datas, 1) == NULL)
			continue ;
		ft_shell_end(datas);
		ft_parser_load(datas);
		ft_magic(datas);
	}
	return (0);
}
