/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:20:32 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 21:10:48 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	*somalloc(t_solib *solib, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		solib->close(solib, EXIT_FAILURE);
	somemory_add(solib, ptr);
	return (ptr);
}
