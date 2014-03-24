/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <mfassi-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:32:17 by mfassi-f          #+#    #+#             */
/*   Updated: 2014/03/24 14:56:46 by mfassi-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/types.h>//chmod
# include <sys/stat.h>//chmod

# include <libft.h>
# include <get_line.h>
# include <free_arr.h>
# include <search_path.h>
# include <ft_env.h>
# include <ft_cd1.h>
# include <ft_setenv.h>
# include <ft_unsetenv.h>

//type
# define CMD 0
# define PIPE 1
//flag
# define AND 0
# define OR 1

# define UNDEF -1
# define TRUE 1
# define FALSE 0
# define FTSH_NAME "42sh"


typedef struct		s_cmds
{
	char			**cmd;
	char			*cmd_path;
	int				type;
	int				flag;
	char			**rredir;
	char			**lredir;
	struct s_cmds	*right;
	struct s_cmds	*left;
	struct s_cmds	*father;
}					t_cmds;

typedef	struct		s_env
{
	t_cmds			**cmds;
	int				fd_in;
	int				fd_out;
	char			**envp;
}					t_env;

t_env	*get_env(void);
t_cmds  **parser(char **lex);
int     ft_error(char *cmd, char *msg, char *arg);
char            *ft_findexe(char **path, char *exe);
char    *ft_getenv(char **env, char *key);


/* REDIRECTION */



char	*get_file_content(int fd);
void	no_such_file(char *file);
int		get_write_file(char * file, int fd);
int		ft_redir_left(t_cmds *tree);
int		ft_redir_right(t_cmds *tree);


/* EXECUTION */

void	execution(t_cmds *tree);
int		exec_cmd(t_cmds *tree);
int		exec_tree(t_cmds *tree);
void	exec_trees(void);

/* PIPE */

void	call_child(int *p, t_cmds *tree);
void	call_father(int *p, t_cmds *tree);
int		grand_father(int *p, t_cmds *tree, int pid);
int		ft_pipe(t_cmds *tree);


/* CMDS */

t_cmds	*new_cmd();
void	free_tree(t_cmds **tree);
void	free_all_trees(t_cmds **cmds);
void	go_to_up(t_cmds	**cmds);


/* PARSER UTILS */

int		nb_semicolon(char **lex);
int		len_cmd(char **lex);
int		nb_item(char **lex, char *item);
void	add_token(char **arr, char *token);
char	**new_arr(size_t size);

/* TRASH */

int		implemented_function(char **cmd, char ***envp);


#endif
