/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:51 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:16:55 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

int			ft_shell_end(t_datas *datas)
{
	if (!FLAG_ISTERM(datas->flags))
		return (0);
	if (tcsetattr(0, TCSANOW, ft_getterm(NULL)) == -1)
		return (ft_error(FTSH_NAME, "can not restore terminal.", NULL));
	return (0);
}
