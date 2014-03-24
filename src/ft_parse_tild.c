/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tild.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:46:24 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/03 16:13:03 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <42sh.h>

static char	*ft_parse_tild_set(t_datas *datas, char *str)
{
	char		*new;
	char		*home;

	home = ft_getenv(datas->local, "HOME");
	if (ft_strlen(str) == 1)
		return (ft_strdup(home));
	new = ft_strnew(ft_strlen(home) + ft_strlen(str + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, home);
	ft_strcat(new, str + 1);
	return (new);
}

char		*ft_parse_tild(t_datas *datas, char **str)
{
	int			i;
	char		*new;

	if (!str || *str == NULL)
		return (NULL);
	dprintf(datas->debug, "\n%s==========> START PARSE TILD <==========%s\n\n", FTSH_BLUE, FTSH_COLOR_RESET);
	dprintf(datas->debug, "%sSTART PARSE:%s\t %s\n", FTSH_CYAN, FTSH_COLOR_RESET, *str);
	i = ft_strichr(*str, '~');
	if (i == 0 && ((*str)[i + 1] == '\0' || (*str)[i + 1] == '/'))
		new = ft_parse_tild_set(datas, *str);
	else if (i == 1 && (*str)[0] == '\\')
		new = ft_strdup(*str + 1);
	else
		new = ft_strdup(*str);
	if (new == NULL)
		return (NULL);
	dprintf(datas->debug, "%sFINAL PARSE:%s\nkey:\t%s\nstr:\t%s\nnew:\t%s\n", FTSH_CYAN, FTSH_COLOR_RESET, *str, new);
	ft_strdel(str);
	*str = new;
	dprintf(datas->debug, "\n%s==========>  END PARSE TILD  <==========%s\n", FTSH_BLUE, FTSH_COLOR_RESET);
	return (new);
}
