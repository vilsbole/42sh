/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 19:36:26 by evilsbol          #+#    #+#             */
/*   Updated: 2013/12/08 19:40:03 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libprt.h"

void	pr_putnbr(int n)
{
	if (n == -2147483648)
		pr_putstr("-2147483648");
	else if (n < 0)
	{
		pr_putchar('-');
		pr_putnbr(n * -1);
	}
	else if (n < 10)
		pr_putchar(n + '0');
	else
	{
		pr_putnbr(n / 10);
		pr_putchar((n % 10) + '0');
	}
}
