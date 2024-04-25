/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:11:24 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	somemory_close(t_solib *solib)
{
	if (!solib)
		return ;
	if (!solib->memory)
		return ;
	if (!solib->memory->first)
		return (free(solib->memory));
	solib->memory->clear(solib);
	free(solib->memory);
}

int	sonew_memory(t_solib *solib)
{
	solib->memory = (t_somemory *)malloc(sizeof(t_somemory));
	if (!solib->memory)
		return (free(solib), 1);
	solib->memory->show = somemory_show;
	solib->memory->remove = somemory_remove;
	solib->memory->clear = somemory_clear;
	solib->memory->add = somemory_add;
	solib->memory->close = somemory_close;
	solib->memory->first = NULL;
	return (0);
}
