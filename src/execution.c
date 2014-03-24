/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:24:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 19:15:52 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <42sh.h>
#include <stdio.h>

void    execution(t_cmds *tree)
{
	dprintf(2, "execution\n");
	dprintf(2, "j'execute : %s\n", tree->cmd[0]);
	tree->cmd_path = ft_findexe(get_env()->datas->path, tree->cmd[0]);
	if (execve(tree->cmd_path, tree->cmd, get_env()->datas->env) == -1)
	{
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(tree->cmd[0], 2);
		exit(1);
	}
}

int exec_cmd(t_cmds *tree)
{
	pid_t   pid;
	int     ret;

	if (ft_redir_right(tree) || ft_redir_left(tree))
		return (-1);
	if (!tree->cmd || (tree->cmd && !tree->cmd[0]))
		return (0);
	ret = implemented_function(get_env()->datas, tree->cmd);
	if (ret == 0)
	{
		pid = fork();
		if (pid == 0)
			execution(tree);
		if (pid < 0)
		{
			ft_putstr_fd("Fork failed\n", 2);
			return (-1);
		}
		waitpid(pid, &(get_env()->datas->status), 0);
	}
	if (ret == -1)
		exit(0);
	return (0);
}

int exec_tree(t_cmds *tree)
{
	if (!tree)
		return (0);
	if (tree->type == CMD)
	{
		if (exec_cmd(tree))
			return (-1);
		exec_tree(tree->right);
	}
	else if (tree->type == PIPE)
		ft_pipe(tree);
	return (0);
}

void    exec_trees(void)
{
	t_cmds  *tree;

	while (get_env()->cmds && *(get_env()->cmds))
	{
		if (!exec_tree(*(get_env()->cmds)))
		{
			tree = *(get_env()->cmds);
			get_env()->cmds++;
			free_tree(&tree);
			dup2(get_env()->fd_in, 0);
			dup2(get_env()->fd_out, 1);
		}
		else
			return ; /* ERROR */
	}
}