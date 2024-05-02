/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sofree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 13:16:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	sofree(t_solib *solib, void *ptr)
{
	t_somemdata	*memory;

	if (!ptr)
		return (0);
	if (!solib)
		return (free(ptr), 1);
	memory = somemory_remove(solib, ptr);
	if (!memory)
		return (0);
	free(memory->ptr);
	memory->ptr = NULL;
	free(memory);
	memory = NULL;
	return (1);
}
