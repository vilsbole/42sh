/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:26:47 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:26:49 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCD_H
# define FTCD_H
# define FTSH_BLT_OPTS		("lnpqv")
# define FTSH_BLT_USAGE		("cd [-lnpqv] [DIR]")
# define FTSH_BLT_MAXOPTS	(5)

int		ft_cd_check(char *path);
int		ft_cd_set(t_datas *datas, char *opts, char *str, char *new);
int		ft_cd_update(t_datas *datas, char *opts, char *path, char *cwd);
void	ft_cd_putpath(t_datas *datas, char *opts, char *path);

#endif
