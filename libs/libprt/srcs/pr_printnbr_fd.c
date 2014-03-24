/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_printnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:49:06 by evilsbol          #+#    #+#             */
/*   Updated: 2013/12/23 19:49:07 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprt.h"

int		pr_printnbr_fd(int fd, va_list ap)
{
	int		c;
	char	*p;

	c = va_arg(ap, int);
	p = pr_itoa(c);
	pr_putstr_fd(fd, p);
	return (pr_strlen(p));
}
