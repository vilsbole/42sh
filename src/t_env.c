#include <main.h>

static t_env    *new_env(void)
{
	t_env   *env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env)
	{
		env->cmds = NULL;
		env->envp = NULL;
	}
	return (env);
}

t_env   *get_env(void)
{
	static t_env	 *env = NULL;

	if (env == NULL)
		env = new_env();
	return (env);
}
