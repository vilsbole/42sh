/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_response.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:35 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:36 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <libft.h>
#include <ftsh.h>

int		ft_response(t_datas *datas)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	if (WIFEXITED(datas->status))
		tmp = ft_itoa(WEXITSTATUS(datas->status));
	else if (WIFSIGNALED(datas->status))
		tmp = ft_itoa(WTERMSIG(datas->status));
	else if (WIFSTOPPED(datas->status))
		tmp = ft_itoa(WSTOPSIG(datas->status));
	res = ft_setvar(&(datas->local), "?", tmp);
	ft_strdel(&tmp);
	return (res);
}
