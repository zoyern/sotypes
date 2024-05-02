/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:32 by marvin            #+#    #+#             */
/*   Updated: 2024/05/02 13:20:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	*somalloc(t_solib *solib, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!solib)
	{
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (!ptr)
		solib->close(solib, EXIT_FAILURE);
	somemory_add(solib, ptr);
	return (ptr);
}
