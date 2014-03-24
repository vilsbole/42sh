/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_printvoid_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:49:52 by evilsbol          #+#    #+#             */
/*   Updated: 2013/12/23 19:49:54 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprt.h"

int		pr_printvoid_fd(int fd, va_list ap)
{
	char			*p;
	unsigned long	c;

	pr_putstr_fd(fd, "0x");
	c = va_arg(ap, unsigned long);
	p = pr_htoa(c);
	pr_putstr_fd(fd, p);
	return (pr_strlen(p) + 2);
}
