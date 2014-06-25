/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrandom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:13:36 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:13:37 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <ftsh.h>

char	*ft_getrandom(char *buf, int len)
{
	int		fd;
	int		res;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = read(fd, buf, len);
	close(fd);
	if (ret <= 0 || ft_strlen(buf) == 0)
		return (NULL);
	return (buf);
}
