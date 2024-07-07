/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotypes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 19:01:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	solib_close(t_solib *solib, int status)
{
	if (!solib)
	{
		if (status)
			exit(status);
		return (status);
	}
	solib->memory->close(solib);
	free(solib);
	if (status)
		exit(status);
	return (status);
}

t_solib	*sonew_types(int argc, char **argv, char **envp)
{
	t_solib	*solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (NULL);
	solib->print = soprintf;
	if (sonew_memory(solib))
		return (NULL);
	solib->close = solib_close;
	solib->malloc = somalloc;
	solib->free = sofree;
	solib->libft = NULL;
	sonew_env(solib, argc, argv, envp);
	return (solib);
}
