/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchateau <gchateau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 13:37:39 by gchateau          #+#    #+#             */
/*   Updated: 2013/12/16 20:16:07 by gchateau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFT_H
# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H
#  define BUFF_SIZE 1

typedef struct		s_gnl
{
	char			*buf;
	int				fd;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

int		get_next_line(int const fd, char **line);

# endif /* !GET_NEXT_LINE_H */
#endif /* !LIBFT_H */
