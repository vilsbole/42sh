/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftenv_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:26:54 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:26:55 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTENV_STRUCT_H
# define FTENV_STRUCT_H

typedef struct	s_bltenv
{
	char		*opts;
	char		*exe;
	char		**av;
	char		**ep;
}				t_bltenv;

#endif
