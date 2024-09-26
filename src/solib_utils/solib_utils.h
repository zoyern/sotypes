/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:57:56 by marvin            #+#    #+#             */
/*   Updated: 2024/09/26 21:30:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLIB_UTILS_H
# define SOLIB_UTILS_H

# include <sotypes/all.h>

size_t	solib_strlen(const char *str);
int		solib_strcmp(const char *s1, const char *s2, size_t n);
int		hex_char_to_int(char hex_char);
void	solib_strmcat(char **dst, char *src);
char	*solib_strchr(const char *str, int c);

#endif
