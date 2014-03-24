/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:17:43 by evilsbol          #+#    #+#             */
/*   Updated: 2014/02/07 17:23:01 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprt.h"

void	pr_quit(int system, char *e_perso)
{
	if (system)
		pr_printf_fd(2, RED "%s: %s\n" RESET, strerror(system), e_perso);
	else
		pr_printf_fd(2, RED "%s\n" RESET, e_perso);
	exit(EXIT_FAILURE);
}
