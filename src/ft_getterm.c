/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getterm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:39 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:41 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <libft.h>
#include <ftsh.h>

struct termios		*ft_getterm(t_datas *datas)
{
	static struct termios	back;
	static struct termios	*restore;

	if (restore == NULL)
	{
		if (tcgetattr(0, &back) == -1)
			return (NULL);
		if (datas != NULL)
		{
			datas->cols = tgetnum("co");
			datas->rows = tgetnum("li");
		}
		restore = &back;
	}
	return (restore);
}
