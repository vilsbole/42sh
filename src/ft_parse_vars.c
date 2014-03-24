/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_vars.c                                    :+:      :+:    :+:   */
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

static int	ft_isdelim(char *s, int i)
{
	if (ft_isdigit(s[i]) == 1 || ft_isalpha(s[i]) == 1 || s[i] == '_')
		return (0);
	return (1);
}

static void	ft_parse_vars_getkey(char *s, char *key)
{
	int			len;

	if (!s || *s != '$')
		return ;
	if (ft_strncmp(s, "$$", 2) == 0 || ft_strncmp(s, "$?", 2) == 0)
	{
		key[0] = s[1];
		return ;
	}
	s++;
	len = 0;
	while (s[len] != '\0' && ft_isdelim(s, len) == 0)
		len++;
	ft_strncpy(key, s, len);
}

static int	ft_parse_vars_join(t_datas *datas, char **new, char *key, char *s)
{
	int			i;

	i = ft_strichr(s, '$');
	if (i > 0 && s[i - 1] != '\\')
	{
		*new = ft_strfjoin(*new, ft_strsub(s, 0, i));
		dprintf(datas->debug, "%sSET RESULT:%s\nkey:\t%s\nstr:\t%s\ntmp:\t%s\nnew:\t%s\n", FTSH_GREEN, FTSH_COLOR_RESET, key, s, s + i, *new);
		return (i);
	}
	if (i == 0)
	{
		if (ft_strlen(key) == 0)
			*new = ft_strfjoin(*new, ft_strdup("$"));
		else
		{
			dprintf(datas->debug, "%sGET VALUE:\nkey:%s\t%s\nval:\t%s\n", FTSH_PURPLE, FTSH_COLOR_RESET, key, ft_getvar(datas, key));
			*new = ft_strfjoin(*new, ft_strdup(ft_getvar(datas, key)));
		}
	}
	else
	{
		*new = ft_strfjoin(*new, ft_strsub(s, 0, i - 1));
		if (ft_strcmp(key, "$") != 0)
			*new = ft_strfjoin(*new, ft_strsub(s, i, ft_strlen(key) + 1));
		else
		{
			*new = ft_strfjoin(*new, ft_strdup(key));
			dprintf(datas->debug, "%sSET RESULT:%s\nkey:\t%s\nstr:\t%s\ntmp:\t%s\nnew:\t%s\n", FTSH_GREEN, FTSH_COLOR_RESET, key, s, s + i + 1, *new);
			return (i + 1);
		}
	}
	dprintf(datas->debug, "%sSET RESULT:%s\nkey:\t%s\nstr:\t%s\ntmp:\t%s\nnew:\t%s\n", FTSH_GREEN, FTSH_COLOR_RESET, key, s, s + i + ft_strlen(key) + 1, *new);
	return (i + ft_strlen(key) + 1);
}

static int	ft_parse_vars_set(t_datas *datas, char **new, char *key, char *s)
{
	int			i;
	int			ret;

	ret = 0;
	i = ft_strichr(s, '$');
	ft_parse_vars_getkey(s + i, key);
	ret += ft_parse_vars_join(datas, new, key, s);
	if (*(s + ret) == '"')
	{
		if (s[i - 1] == '"')
			return (ret);
		i = ft_strichr(s + ret + 1, '"');
		*new = ft_strfjoin(*new, ft_strsub(s + ret, 1, i));
		ret += i + 2;
		dprintf(datas->debug, "PARSE QUOTE RETURN:\t(tmp: %i) %s\t(%s)\n", i - 1, s, s + ret);
	}
	return (ret);
}

char		*ft_parse_vars(t_datas *datas, char **str)
{
	int			i;
	char		*s;
	char		*new;
	char		key[FTSH_MAXLEN_LINE];

	if (!str || (s = *str) == NULL)
		return (NULL);
	if ((new = ft_strnew(0)) == NULL)
		return (NULL);
	dprintf(datas->debug, "\n%s==========> START PARSE VARS <==========%s\n\n", FTSH_BLUE, FTSH_COLOR_RESET);
	while (*s != '\0')
	{
		ft_bzero(key, FTSH_MAXLEN_LINE);
		i = ft_strichr(s, '$');
		if (i >= 0)
			s += ft_parse_vars_set(datas, &new, key, s);
		else
		{
			dprintf(datas->debug, "FINAL PARSE:\nkey:\t%s\nstr:\t%s\nnew:\t%s\n", key, s, new);
			new = ft_strfjoin(new, ft_strdup(s));
			break ;
		}
	}
	dprintf(datas->debug, "\n%sRESULT:%s\nsrc:\t%s\nres:\t%s\n", FTSH_YELLOW, FTSH_COLOR_RESET, *str, new);
	dprintf(datas->debug, "\n%s==========>  END PARSE VARS  <==========%s\n", FTSH_BLUE, FTSH_COLOR_RESET);
	ft_strdel(str);
	*str = new;
	return (new);
}
