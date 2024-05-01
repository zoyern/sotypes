/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory_show.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:17:04 by marvin            #+#    #+#             */
/*   Updated: 2024/05/01 07:20:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	somemory_show(t_solib *solib)
{
	t_somemdata	*current;

	current = solib->memory->first;
	solib->print("color test : %CF26C29(coucou les amis (je suis un peu fatigué)) mdr\n");
	while (current)
	{
		solib->print("%p -> %CF26C29(%p)\t\tnext : %p\n", current, current->ptr, current->next);
		current = current->next;
	}
}
