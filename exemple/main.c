/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 17:53:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exemple.h"

int	main(int argc, char **argv, char **envp)
{
	t_solib	*solib;

	solib = sonew_types(argc, argv, envp);
	if (!solib)
		return (solib->close(solib, EXIT_FAILURE));
	solib->print("SOLIB INIT : %b\n", solib);
	soprintf("Program name : %s\n \
			Number of argument %C-p#FFFFFF(  %C#FF0000((hey))coucou  ): %d\n \
			Aruments : \n%S \
			Envp is init : %b\n\n",
			solib->env->name, solib->env->argc,
			solib->env->argv, solib->env->envp);
	return (solib_close(solib, EXIT_SUCCESS));
}
