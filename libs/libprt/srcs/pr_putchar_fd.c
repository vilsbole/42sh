/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:01:40 by evilsbol          #+#    #+#             */
/*   Updated: 2013/11/22 16:30:11 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int		pr_putchar_fd(int fd, char c)
{
	if (c)
		write(fd, &c, 1);
	return (1);
}