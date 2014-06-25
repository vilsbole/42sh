/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:49:56 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:58 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstlen(t_dlist *dlst)
{
	size_t	n;

	if (!dlst)
		return (0);
	n = ft_dlstlen_rwd(dlst);
	n += ft_dlstlen_fwd(dlst);
	return (n - 1);
}
