/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjacques <yjacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 15:17:11 by yjacques          #+#    #+#             */
/*   Updated: 2014/06/25 15:17:13 by yjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <term.h>
#include <libft.h>
#include <ftsh.h>

static void	ft_signal_resize(int sig)
{
	t_datas		*datas;

	(void)sig;
	datas = ft_getdatas(NULL);
	if (FLAG_ISTERM(datas->flags))
	{
		datas->cols = tgetnum("co");
		datas->rows = tgetnum("li");
	}
}

static void	ft_signal_prompt(int sig)
{
	t_line		*line;
	t_datas		*datas;

	datas = ft_getdatas(NULL);
	dprintf(datas->debug, "\nSIG:\t%i\nstatus:\t%i\n", sig, datas->status);
	line = datas->prompt.line;
	if (line != NULL && line->i != line->len - 1)
		ft_move_end(datas, line, FTSH_KEY_END);
	if (datas->prompt.line != NULL)
	{
		while (datas->prompt.line->prev != NULL)
			datas->prompt.line = line->prev;
		ft_bzero((datas->prompt.line)->buf, FTSH_MAXLEN_LINE);
		(datas->prompt.line)->i = -1;
		(datas->prompt.line)->x = 0;
		(datas->prompt.line)->y = 0;
		(datas->prompt.line)->len = 0;
	}
	if (sig == SIGINT)
		ft_putchar('\n');
	ft_prompt(datas, 0);
	if (FLAG_ISTERM(datas->flags) && FLAG_ISCOLOR(datas->flags))
		ft_putstr(FTSH_HWHITE);
}

static void	ft_signal_exit(int sig)
{
	int			code;
	t_line		*line;
	t_datas		*datas;

	code = 0;
	datas = ft_getdatas(NULL);
	line = datas->prompt.line;
	if (sig == SIGKILL)
		code = 1;
	if (line != NULL && line->i != line->len - 1)
		ft_move_end(datas, line, FTSH_KEY_END);
	ft_putchar('\n');
	ft_exit(datas, code);
}

void		ft_signal(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, &ft_signal_exit);
	signal(SIGKILL, &ft_signal_exit);
	signal(SIGCONT, &ft_signal_prompt);
	signal(SIGINT, &ft_signal_prompt);
	signal(SIGWINCH, &ft_signal_resize);
}
