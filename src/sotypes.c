/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotypes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:09:59 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	solib_close(t_solib *solib, int status)
{
	if (!solib)
		return (status);
	solib->memory->close(solib);
	free(solib);
	if (status)
		exit(status);
	return (status);
}

t_solib	*sonew_types(void)
{
	t_solib	*solib;

	solib = (t_solib *)malloc(sizeof(t_solib));
	if (!solib)
		return (NULL);
	if (sonew_memory(solib))
		return (NULL);
	solib->close = solib_close;
	solib->malloc = somalloc;
	solib->free = sofree;
	return (solib);
}
