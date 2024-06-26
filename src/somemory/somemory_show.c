/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:17:04 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 20:27:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	somemory_show(t_solib *solib)
{
	t_somemdata	*current;

	current = solib->memory->first;
	while (current)
	{
		solib->print("%p -> %CF26C29(%p)\t\tnext : %p\n",
			current, current->ptr, current->next);
		current = current->next;
	}
}
