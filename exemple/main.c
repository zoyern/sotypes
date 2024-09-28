/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 19:23:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exemple.h"

int	main(int argc, char **argv, char **envp)
{
	t_solib	*solib;
	char	*testing;

	solib = sonew_types(argc, argv, envp);
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	solib->print("SOLIB INIT : %b\n", solib);
	testing = soprintf_get(solib,
			"Program name : %s\n \
			Number of argument %C-p#FFFFFF(  %C#FF0000((hey))coucou  ): %d\n \
			Aruments : \n%S \
			Envp is init : %b\n\n",
			solib->env->name, solib->env->argc,
			solib->env->argv, solib->env->envp);
	soprintf("testing : \n%s\n", testing);
	return (solib_close(solib, EXIT_SUCCESS));
}
