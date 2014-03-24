/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 11:52:39 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 19:17:34 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <42sh.h>

t_cmds  *new_cmd(void)
{
	t_cmds  *new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (new)
	{
		new->cmd = NULL;
		new->type = UNDEF;
		new->flag = UNDEF;
		new->cmd_path = NULL;
		new->rredir = NULL;
		new->lredir = NULL;
		new->right = NULL;
		new->left = NULL;
		new->father = NULL;
	}
	return (new);
}

void    free_tree(t_cmds **tree)
{
	if (!*tree)
		return ;
	free_tree(&(*tree)->left);
	free_tree(&(*tree)->right);
	ft_arrdel(&(*tree)->cmd);
	ft_arrdel(&(*tree)->rredir);
	ft_arrdel(&(*tree)->lredir);
	if ((*tree)->cmd_path)
		free((*tree)->cmd_path);
	free(*tree);
}

void	free_all_trees(t_cmds	**cmds)
{
	int		i;
	t_cmds	**tree;

	i = 0;
	while (cmds && cmds[i])
	{
		tree = cmds + i;
		while (tree && *tree &&  (*tree)->father)
			*tree = (*tree)->father;
		free_tree(tree);
		i++;
	}
	free(cmds);
}

void    go_to_up(t_cmds **cmds)
{
	int		i;
	t_cmds	**tree;

	i = 0;
	while (cmds && cmds[i])
	{
		tree = cmds + i;
		while (tree && *tree &&  (*tree)->father)
			*tree = (*tree)->father;
		i++;
	}
}