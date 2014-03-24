/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:28:15 by gchateau          #+#    #+#             */
/*   Updated: 2014/02/06 05:28:46 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTCD_H
# define FTCD_H
# define FTSH_BLT_OPTS		("lnpqv")
# define FTSH_BLT_USAGE		("cd [-lnpqv] [DIR]")
# define FTSH_BLT_MAXOPTS	(5)

int		ft_cd_check(char *path);
int		ft_cd_back(t_datas *datas, char *new);
int		ft_cd_path(char *new, char *path, char *cwd);
int		ft_cd_home(t_datas *datas, char *new, char *path, char *cwd);
int		ft_cd_update(t_datas *datas, char *opts, char *path, char *cwd);
void	ft_cd_putpath(t_datas *datas, char *opts, char *path);

#endif /* !FTCD_H */