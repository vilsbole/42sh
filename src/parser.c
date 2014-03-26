/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:21:40 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/26 20:35:02 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <42sh.h>
#include <stdio.h>

int     parser_pipe(t_cmds **current_node, int *is_new_cmd, char **lex, t_cmds **cmds)
{
	t_cmds  *tmp;

	tmp = (*current_node);
	(*current_node) = new_cmd();
	(*current_node)->type = PIPE;
	(*current_node)->left = tmp;
	if (tmp->father)
	{
		(*current_node)->father = tmp->father;
		(*current_node)->father->right = (*current_node);
	}
	(*current_node)->left->father = (*current_node);
	(*current_node)->right = new_cmd();
	(*current_node)->right->father = (*current_node);
	(*current_node) = (*current_node)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '|'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

int     parser_or(t_cmds **current_node, int *is_new_cmd, char **lex, t_cmds **cmds)
{
	(*current_node)->right = new_cmd();
	(*current_node)->right->father = (*current_node);
	(*current_node)->right->flag = OR;
	(*current_node) = (*current_node)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '||'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

int     parser_and(t_cmds **current_node, int *is_new_cmd, char **lex, t_cmds **cmds)
{
	(*current_node)->right = new_cmd();
	(*current_node)->right->father = (*current_node);
	(*current_node)->right->flag = AND;
	(*current_node) = (*current_node)->right;
	*is_new_cmd = TRUE;
	if (!*(lex + 1) || !ft_strcmp(*(lex + 1), "&&")
			|| !ft_strcmp(*(lex + 1), "||") || !ft_strcmp(*(lex + 1), "|")
			|| !ft_strcmp(*(lex + 1), ";"))
	{
		ft_putstr_fd("42sh: parse error near '&&'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	return (0);
}

int     parser_lredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	dprintf(2, "je suis sur %s\n", *lex);
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '<'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	dprintf(2, "hey je rajoute un token %s \n", *lex);
	add_token((*current_node)->lredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}

int     parser_rredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '>'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	add_token((*current_node)->rredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}

int     parser_drredir(t_cmds **current_node, char **lex, t_cmds **cmds)
{
	if (!*(lex) || !ft_strcmp(*(lex), "&&")
			|| !ft_strcmp(*(lex), "||") || !ft_strcmp(*(lex), "|")
			|| !ft_strcmp(*(lex), ">") || !ft_strcmp(*(lex), "<")
			|| !ft_strcmp(*(lex), ">>") || !ft_strcmp(*(lex), ";"))
	{
		ft_putstr_fd("42sh: parse error near '>>'\n", 2);
		free_all_trees(cmds);
		return (-1);
	}
	add_token((*current_node)->drredir, *lex);
	(*current_node)->type = CMD;
	return (0);
}
void    parser_new_cmds(t_cmds ***current_tree, t_cmds **current_node, int *is_new_cmds, int *is_new_cmd)
{
	if (*is_new_cmds)
	{
		(*current_tree) = (*current_tree) + 1;
		(*current_node) = new_cmd();
		**current_tree = *current_node;
		*is_new_cmds = FALSE;
		*is_new_cmd = TRUE;
	}
}

void    parser_new_cmd(t_cmds **current_node, int *is_new_cmd, char **lex)
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

int     parser_process(t_cmds **current_node, int *is_new, char ***lex, t_cmds **cmds)
{
	int res;

	res = 0;
	parser_new_cmd(current_node, &is_new[1], *lex);
	if (!ft_strcmp(**lex, ";"))
		is_new[0] = TRUE;
	else if (!ft_strcmp(**lex, "|"))
		res = parser_pipe(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "||"))
		res = parser_or(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "&&"))
		res = parser_and(current_node, &is_new[1], *lex, cmds);
	else if (!ft_strcmp(**lex, "<"))
		res = parser_lredir(current_node, ++(*lex), cmds);
	else if (!ft_strcmp(**lex, ">"))
		res = parser_rredir(current_node, ++(*lex), cmds);
	else if (!ft_strcmp(**lex, ">>"))
		res = parser_drredir(current_node, ++(*lex), cmds);
	else
	{
		dprintf(2, "J'ai trouver un e commande\n");
		(*current_node)->type = CMD;
		add_token((*current_node)->cmd, **lex);
	}
	dprintf(2, "je suit sortit\n");
	return (res);
}

t_cmds  **parser(char **lex)
{
	t_cmds  **cmds;
	int     is_new[2];
	t_cmds  **current_tree;
	t_cmds  *current_node;

	is_new[0] = FALSE;
	is_new[1] = TRUE;
	cmds = (t_cmds **)ft_memalloc(sizeof(t_cmds *) * nb_semicolon(lex));
	*cmds = new_cmd();
	current_tree = cmds;
	current_node = *cmds;
	while (lex && *lex)
	{
		parser_new_cmds(&current_tree, &current_node, &is_new[0], &is_new[1]);
		if (parser_process(&current_node, is_new, &lex, cmds))
			return (NULL);
		dprintf(2, "lex %s\n", *lex);
		lex++;
		dprintf(2, "lex %s\n", *lex);
	}
	go_to_up(cmds);
	return (cmds);
}
