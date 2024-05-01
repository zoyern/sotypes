/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:31 by marvin            #+#    #+#             */
/*   Updated: 2024/04/30 20:05:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	somemory_clear(t_solib *solib)
{
	t_somemdata	*current;
	t_somemdata	*tmp;

	current = solib->memory->first;
	while (current->ptr)
	{
		tmp = current->next;
		solib->free(solib, current->ptr);
		current = tmp;
	}
	free(current);
	solib->memory->first = NULL;
}
