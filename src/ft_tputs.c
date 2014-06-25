/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:17:16 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:17:17 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <term.h>

static int	ft_tputs_putc(int c)
{
	return (write(1, &c, 1));
}

int			ft_tputs(char *s)
{
	return (tputs(tgetstr(s, NULL), 1, &ft_tputs_putc));
}
