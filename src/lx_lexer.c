/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslimane <kslimane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 23:12:47 by kslimane          #+#    #+#             */
/*   Updated: 2014/03/24 19:05:39 by kslimane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_arrayset(char **array, int size)
{
	while (size--)
	{
		if (array[size])
		array[size] = ft_strnew(1024);
	}
}

void	lx_closetok(char **data, t_flags *flags)
{
	pr_printf("lx_closetok\n");
	int		i;

	i = 0;
	if (flags->token)
	{
		while (data[flags->index][i])
			i++;
		data[flags->index][i] = '\0';
		flags->index++;
		flags->token = 0;
		flags->len++;
	}
}	

void	lx_endinput(char **data, t_flags *flags)
{
	if (flags->token)
		lx_closetok(data, flags);
	else
		data[flags->index][0] = '\0';
}

void	lx_addtoword(char **data, char c, t_flags *flags)
{
	pr_printf("lx_addtoword\n");
	int		i;

	i = 0;
	if (flags->token)
	{
		while (data[flags->index][i])
			i++;
		data[flags->index][i] = c;
		pr_printf("Apres added : %s\n", data[flags->index]);
	}
	else
	{
		pr_printf("Bonjour index = %d, c = %c \n", flags->index, c);
		data[flags->index][0] = c;
		flags->token = 1;
	}
}

int		lx_tokopr(char **data, char *str, t_flags *flags)
{
//	pr_printf("lx_tokopr\n");
	int		shift;

	shift = 0;
	if (flags->quote == 0 && lx_count(OPR, str[0]))
	{
		if (flags->token)
			lx_closetok(data, flags);
		shift = (str[1] == str[0] ? 2 : 1);
		data[flags->index++] = ft_strsub(str, 0, shift);
		return (shift - 1);
	}
	return (0);
}

int		lx_flags(char c, t_flags *flags)
{
	pr_printf("lx_flags\n");
	if (lx_count(ARGS, c))
	{
		if (c == '"')
			flags->quote = flags->quote == 1 ? 0 : 1;
		else if (c == '\'')
			flags->quote = flags->quote == 2 ? 0 : 2;
		else
			flags->quote = 3;
		pr_printf("Sortie de lx_flags avec %d\n", flags->quote);
		return (1);
	}
	return (0);
}

t_flags		*lx_set_flags(void)
{
	t_flags		*flags;

	flags = NULL;
	if ((flags = (t_flags *)malloc(sizeof(t_flags))))
	{
		flags->index = 0;
		flags->quote = 0;
		flags->token = 0;
		flags->len = 0;
	}
	return (flags);
}

void		lx_scanner(char *line, char **data)
{
	int		i;
	t_flags	*flags;

	i = -1;
	flags = lx_set_flags();
	while (line[++i])
	{
		if (flags->quote == 0 && lx_count(SPLIT, line[i]))
		{
			lx_closetok(data, flags);
			i++;
		}
		if (flags->quote == 0 && lx_tokopr(data, &line[i], flags))
			i++;
		i += lx_flags(line[i], flags);		/* A replacer ? */
		if (flags->quote == 2)
			//dquote(data, flags, line[i]);
		if (line[i] == '\n')
			lx_closetok(data, flags);
		if ((flags->quote == 0 && (lx_count(WORD, line[i]) == 0))
			|| flags->quote == 2)
			lx_addtoword(data, line[i], flags);
	}
	lx_endinput(data, flags);
}

int     lx_arrsize(char **arr)
{
    int     i;

    i = 0;
    if (arr)
    {
        while (arr[i][0] != '\0')
            i++;
    }
    return (i);
}

char    **lx_arrdup(char **arr)
{
    size_t  len;
    size_t  i;
    char    **new;

    if (!arr)
		return (NULL);
    len = (size_t)lx_arrsize(arr);
    new = ft_arrnew(len);
    if (new == NULL)
		return (NULL);
    i = 0;
    while (i < len)
    {
		if (arr[i][0] == '\0')
			new[i] = NULL;
		else
			new[i] = ft_strdup(arr[i]);
		i++;
    }
    return (new);
}

char		**lx_lexer(char *line)
{
	int		i;
	char	*axiom;
	char	**data;
	char	**res;

	i = 0;
	axiom = line;
	data = ft_arrnew(MAX_SIZE_ARR);
	ft_arrayset(data, MAX_SIZE_STR);
	if (ft_strequ(axiom, "exit") || ft_strequ(axiom, "quit"))
		exit(EXIT_SUCCESS);
	else
		lx_scanner(line, data);
	res = lx_arrdup(data);
	while (res[i] && res[i][0])
		pr_printf("word: %s | %d\n", res[i++], lx_arrsize(res));
	ft_arrdel(&data);
	return (res);
}
