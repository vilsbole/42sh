/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:24:22 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 14:54:53 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <main.h>

#include <stdio.h>
void    execution(t_cmds *tree)
{
	dprintf(2, "execution\n");
	dprintf(2, "j'execute : %s\n", tree->cmd[0]);
	char    **split_path;
	char    *path;

	split_path = ft_strsplit(ft_getenv(get_env()->envp, "PATH"), ':');
	path = ft_findexe(split_path, tree->cmd[0]);//free path ??
	free_arr(&split_path);
	tree->cmd_path = path;
	if (execve(path, tree->cmd, get_env()->envp) == -1)
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
	ret = implemented_function(tree->cmd, &get_env()->envp);
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
		wait(0);
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
			return ;//ERROR
	}
}
