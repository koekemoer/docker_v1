/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaske <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:01:45 by tmaske            #+#    #+#             */
/*   Updated: 2016/08/27 12:33:53 by tmaske           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_extern(t_vars *t_v)
{
	int			sig;
	int			pid;

	sig = 1;
	if (t_v->path == NULL && t_v->e == 0)
	{
		ft_putstr("Error: Command Not Found: ");
		ft_putendl(t_v->args[0]);
	}
	else if (t_v->path != NULL && t_v->e == 0)
	{
		pid = fork();
		if (pid < 0)
			ft_putendl("Error: Forking Failed");
		else if (pid > 0)
			wait(&sig);
		else if (pid == 0)
			execve(t_v->path, t_v->e_args, t_v->env);
	}
	else if (t_v->e == -1)
		t_v->e = 0;
}

void			ft_check_args(t_vars *t_v, int i, const char **in)
{
	while (++i < 6 && t_v->e == 0)
	{
		if (t_v->e == 0 && ft_strcmp(t_v->args[0], in[i]) == 0)
			ft_builtin(t_v, i);
	}
	i = -1;
	if (t_v->e == 0 && access(t_v->args[0], F_OK) == -1)
	{
		while (t_v->e == 0 && ++i < ft_arrlen(t_v->paths))
		{
			t_v->temp = ft_strjoin(t_v->paths[i], "/");
			t_v->path = ft_strjoin(t_v->temp, t_v->args[0]);
			ft_strdel(&t_v->temp);
			if (access(t_v->path, F_OK) != -1)
				break ;
			else
				ft_strdel(&t_v->path);
		}
	}
	else if (t_v->e == 0)
		t_v->path = ft_strdup(t_v->args[0]);
	t_v->e_args = t_v->args;
	ft_extern(t_v);
}

void			ft_init_vars(t_vars *t_v)
{
	char		*temp;

	if (t_v->line != NULL)
		ft_strdel(&t_v->line);
	if (t_v->args != NULL)
		ft_arrdel(t_v->args);
	if (t_v->path != NULL)
		ft_strdel(&t_v->path);
	if (t_v->paths != NULL && *t_v->paths != NULL)
		ft_arrdel(t_v->paths);
	t_v->home = ft_envseek(t_v, "HOME");
	t_v->pwd = ft_envseek(t_v, "PWD");
	temp = ft_envseek(t_v, "PATH");
	if (temp)
		t_v->paths = ft_strsplit(temp, ':');
	else
		t_v->paths = NULL;
	if (getcwd(t_v->cwd, sizeof(t_v->cwd)) == NULL)
		t_v->e = 1;
	t_v->args_len = 0;
	t_v->line = NULL;
}

int				main(void)
{
	extern char	**environ;
	t_vars		t_v;

	t_v.e = -1;
	t_v.line = NULL;
	t_v.args = NULL;
	t_v.path = NULL;
	t_v.paths = NULL;
	t_v.env_len = ft_arrlen(environ);
	t_v.env = (char **)ft_memalloc(sizeof(char *) * (t_v.env_len + 1));
	while (++t_v.e < t_v.env_len)
		t_v.env[t_v.e] = ft_strdup(environ[t_v.e]);
	t_v.env[t_v.e] = NULL;
	t_v.e = 0;
	ft_shlvl(&t_v);
	while (1)
	{
		ft_init_vars(&t_v);
		if (t_v.e != 0)
			ft_errexit(&t_v);
		ft_putstr("$>");
		get_next_line(STDIN, &t_v.line);
		ft_check_line(&t_v);
	}
	return (0);
}
