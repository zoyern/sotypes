/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/06/10 21:11:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

char	*soenv_dup(t_solib *solib, const char *s)
{
	size_t	len;
	char	*t;

	if (!s)
		return (0);
	while (s[len])
		len++;
	t = (char *)solib->malloc(solib, sizeof(char) * (len + 1));
	if (!t)
		return (0);
	while (*s)
		*t++ = *s++;
	*t = 0;
	return (t -= len);
}

void	soenv_format(t_solib *solib, t_soenv *env, int argc, char **argv)
{
	int	i;

	env->name = argv[0];
	if (argc < 1)
		return ;
	argv++;
	i = 0;
	while (i < argc && argv[i])
		i++;
	env->argv = (char **)solib->malloc(solib, sizeof(char *) * (i + 1));
	env->argc = i;
	i = -1;
	while (++i < env->argc && argv[i])
		env->argv[i] = soenv_dup(solib, argv[i]);
	env->argv[i] = 0;
}

void	sonew_env(t_solib *solib, int argc, char **argv, char **envp)
{
	t_soenv	*env;

	env = (t_soenv *)solib->malloc(solib, sizeof(t_soenv));
	env->argc = 0;
	env->argv = NULL;
	env->name = NULL;
	if (argv)
		soenv_format(solib, env, argc, argv);
	env->envp = envp;
	solib->env = env;
}
