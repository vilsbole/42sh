/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:49:20 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 14:49:21 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **adlst, void (*del)(void *, size_t))
{
	ft_dlstdel_rwd(adlst, (*del));
	ft_dlstdel_fwd(adlst, (*del));
	ft_dlstdelone(adlst, (*del));
}
