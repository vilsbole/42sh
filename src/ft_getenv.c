/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:29 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:30 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

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
