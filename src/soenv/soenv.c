/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/06/10 21:23:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

size_t	soenv_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	soenv_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	len;

	len = (soenv_strlen(src));
	if (!sz)
		return (len);
	while (*src && sz-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}

char	*soenv_strdup(t_solib *solib, const char *s)
{
	char	*out;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = soenv_strlen(s);
	out = solib->malloc(solib, sizeof(char) * (s_len + 1));
	if (!out)
		return (0);
	soenv_strlcpy(out, s, s_len + 1);
	out[s_len] = 0;
	return (out);
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
		env->argv[i] = soenv_strdup(solib, argv[i]);
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
