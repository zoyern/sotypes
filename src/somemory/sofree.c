/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sofree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:45 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:10:41 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	sofree(t_solib *solib, void *ptr)
{
	t_somemdata	*memory;

	if (!ptr)
		return (0);
	memory = somemory_remove(solib, ptr);
	if (!memory)
		return (0);
	free(memory->ptr);
	memory->ptr = NULL;
	free(memory);
	memory = NULL;
	return (1);
}
