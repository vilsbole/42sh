/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_reload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:16:58 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:18:00 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include <ftsh.h>

static int	ft_putnoterm(t_datas *datas)
{
	if (!FLAG_ISTERM(datas->flags) && !FLAG_ISADVERT(datas->flags))
	{
		ft_putstr_fd(FTSH_NAME, 2);
		ft_putstr_fd(": terminal not found: ", 2);
		ft_putstr_fd(FTSH_RED, 2);
		ft_putstr_fd("advanced line edition and coloration are disabled", 2);
		ft_putendl_fd(FTSH_COLOR_RESET, 2);
		datas->flags |= FLAG_ADVERT;
	}
	return (1);
}

int			ft_shell_reload(t_datas *datas)
{
	if (FLAG_ISTERM(datas->flags))
		ft_shell_end(datas);
	datas->flags &= ~FLAG_TERM;
	if (tgetent(NULL, ft_getenv(datas->local, "TERM")) < 1)
		return (ft_putnoterm(datas));
	datas->flags &= ~FLAG_ADVERT;
	datas->flags |= FLAG_TERM;
	datas->flags |= FLAG_COLOR;
	return (0);
}
