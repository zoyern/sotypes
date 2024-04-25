/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:17:17 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:12:26 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

t_somemdata	*somemory_remove(t_solib *solib, void *ptr)
{
	t_somemdata	*current;
	t_somemdata	*tmp;

	if (!solib->memory)
		return (NULL);
	current = solib->memory->first;
	if ((unsigned long)current->ptr == (unsigned long)ptr)
	{
		solib->memory->first = current->next;
		return (current);
	}
	while (current->next && current->next->ptr)
	{
		tmp = current->next;
		if ((unsigned long)current->next->ptr == (unsigned long)ptr)
		{
			current->next = current->next->next;
			return (tmp);
		}
		current = tmp;
	}
	return (NULL);
}
