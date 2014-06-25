/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:08 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:09 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftsh.h>

int		ft_error(char *cmd, char *msg, char *arg)
{
	if (cmd != NULL)
		ft_putstr_fd(cmd, 2);
	else
		ft_putstr_fd(FTSH_NAME, 2);
	if (msg != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg, 2);
	}
	if (arg != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(arg, 2);
	}
	else
		ft_putchar_fd('\n', 2);
	return (1);
}
