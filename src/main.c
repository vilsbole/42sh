/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:22:23 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/25 20:03:47 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include <unistd.h>
#include <libft.h>
#include <42sh.h>
#include "lexer.h"

static void	ft_main_debug(t_datas *datas, char **av)
{
	datas->debug = open(av[2], O_WRONLY);
	ft_putendl_fd(FTSH_BLUE, datas->debug);
	ft_putstr_fd("#################### ", datas->debug);
	ft_putstr_fd(FTSH_HWHITE, datas->debug);
	ft_putstr_fd("FTSH DEBUG MODE ON ", datas->debug);
	ft_putstr_fd(FTSH_GREEN, datas->debug);
	ft_putstr_fd(av[2], datas->debug);
	ft_putstr_fd(FTSH_BLUE, datas->debug);
	ft_putendl_fd(" ####################", datas->debug);
	ft_putendl_fd(FTSH_COLOR_RESET, datas->debug);
}

static void	ft_parser_load(t_datas *datas)
{
	char		**tmp;

//	tmp = ft_cmdsplit(datas->prompt.buffer);
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
	if (ac > 2 && ft_strcmp(av[1], "-d") == 0)
		ft_main_debug(datas, av);
	ft_shell_start(datas);
	ft_signal();
	get_env()->fd_in = dup(0);
	get_env()->fd_out = dup(1);
	get_env()->datas = datas;
	while (42)
	{
		if (ft_prompt(datas, 1) == NULL)
			continue ;
		ft_error(FTSH_NAME, "\033[1;31mBUFFER\033[0m", datas->prompt.buffer);
		ft_parser_load(datas);
	}
	return (0);
}
