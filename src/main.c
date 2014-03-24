/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:31:48 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 12:13:32 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <signal.h>
#include <stdio.h>
static void	print_prompt()
{
	ft_putstr("\x1B[37m(\x1B[0m");
	ft_putstr("\x1B[36m");
	ft_putstr(*find(get_env()->envp, "PWD=") + 4);
	ft_putstr("\x1B[0m");
	ft_putstr("\x1B[37m)\x1B[0m");
	ft_putstr("\x1B[31m$>\x1B[0m");
}

char	*get_path(char **envp, char **cmd)
{
	char	**paths;
	char	*part_path;
	char	*path;

	paths = ft_strsplit(envp[0] + 5, ':');
	part_path = ft_strjoin(search_path(paths, cmd[0]), "/");
	path = ft_strjoin(part_path, cmd[0]);
	ft_strdel(&part_path);
	free_arr(&paths);
	return (path);
}

static char	**get_cmd(void)
{
	char	*line;
	char	**cmd;

	line = get_line();
	if (ft_strlen(line) == 0)
	{
		ft_strdel(&line);
		return (NULL);
	}
	cmd = ft_strsplit(line, ' ');//LEXER
	ft_strdel(&line);
	return (cmd);
}

int		implemented_function(char **cmd, char ***envp)
{
	if (!cmd)
		return (1);
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		printf("j'exit\n");
		free_arr(&cmd);
		return (-1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0)
		ft_env(*envp, cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ft_cd(cmd, *envp);
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		*envp = ft_setenv(cmd, *envp);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		*envp = ft_unsetenv(cmd, *envp);
	else
		return (0);
	return (1);
}


void	print_lin_arr(char **line)
{
	int	i;
	int	j;
	
	i = 0;
	if (!line || *line == NULL)
	{
		dprintf(2, "\n");
		return ;
	}
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j])
		{
			write(2, line[i] + j, 1);
			j++;
		}
		dprintf(2, "[ %s ]", line[i]);
		i++;
	}
	dprintf(2, "\n");
}

void   tr_prt(t_cmds *tree, int id, int child, int father)
{
	if (!tree)
		return ;
	tr_prt(tree->right, id + 1, 0, id);
	dprintf(2, "father: %d->%s:%d; type: %d; flag: %d; cmd :", father, ((child) ? "right" : "left"),id, tree->type, tree->flag);
	print_lin_arr(tree->cmd);
	tr_prt(tree->left, id + 2, 1, id);
}

int		main(int argc, char **argv, char **envp)
{
	char	**lex;
//	t_env	*env;

	//open TERMCAPS
	get_env();
	get_env()->fd_in = dup(0);
	get_env()->fd_out = dup(1);
	get_env()->envp = envp;
	while (argc == 1 && argv)
	{
		print_prompt();
		lex = get_cmd();
		get_env()->cmds = parser(lex);
		if (!get_env()->cmds)
			continue;
		tr_prt(get_env()->cmds[0], 0 ,0,0);
		exec_trees();
		dup2(get_env()->fd_in, 0);
		dup2(get_env()->fd_out, 1);
	}
	//kill TERMCAPS
	return (0);
}
