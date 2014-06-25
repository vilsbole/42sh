/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:46 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:48 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

char	*ft_getvar(t_datas *datas, char *key)
{
	char	*tmp;

	if (!key)
		return (NULL);
	tmp = ft_getenv(datas->env, key);
	if (tmp != NULL)
		return (tmp);
	return (ft_getenv(datas->local, key));
}
