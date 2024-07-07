/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:32 by marvin            #+#    #+#             */
/*   Updated: 2024/07/07 19:03:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	*somalloc(t_solib *solib, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		solib_close(solib, EXIT_FAILURE);
	if (!solib)
		return (ptr);
	somemory_add(solib, ptr);
	return (ptr);
}
