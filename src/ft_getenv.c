/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:36:15 by gchateau          #+#    #+#             */
/*   Updated: 2014/03/23 02:16:27 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

char	*ft_getenv(char **env, char *key)
{
	size_t	i;
	size_t	len;
	char	*ret;

	if (!env || !key)
		return (NULL);
	i = 0;
	len = ft_strlen(key);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
		{
			ret = ft_strchr(env[i], '=') + 1;
			return (ret);
		}
		i++;
	}
	return (NULL);
}
