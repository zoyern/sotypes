/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 18:55:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	soenv_format(t_solib *solib, t_soenv *env,int argc, char **argv)
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
		env->argv[i] = argv[i];
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
