/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sotypes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:59:30 by marvin            #+#    #+#             */
/*   Updated: 2024/05/04 17:02:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOTYPES_H
# define SOTYPES_H

# include <sotypes/types.h>

t_solib	*sonew_types(int argc, char **argv, char **envp);
void			*somalloc(t_solib *solib, size_t size);
int				sofree(t_solib *solib, void *ptr);

#endif