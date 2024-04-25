/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somemory_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:15:43 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:10:55 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	somemory_add(t_solib *solib, void *ptr)
{
	t_somemdata	*memory;

	memory = (t_somemdata *)malloc(sizeof(t_somemdata));
	if (!memory)
		solib->close(solib, EXIT_FAILURE);
	memory->ptr = ptr;
	memory->next = solib->memory->first;
	solib->memory->first = memory;
}
