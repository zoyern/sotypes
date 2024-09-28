/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 22:50:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	hex_c_to_int(char hex_char)
{
	if (hex_char >= '0' && hex_char <= '9')
		return (hex_char - '0');
	else if (hex_char >= 'A' && hex_char <= 'F')
		return (hex_char - 'A' + 10);
	else if (hex_char >= 'a' && hex_char <= 'f')
		return (hex_char - 'a' + 10);
	else
		return (0);
}

int	split_color(int color, int *r, int *g, int *b)
{
	*r = (0xFF0000 & color) >> 16;
	*g = (0x00FF00 & color) >> 8;
	*b = (0x0000FF & color);
	return (1);
}

int	read_hex_to_int(const char *color)
{
	int	out;
	int	k;

	if (!color || solib_strlen(color) < 6)
		return (-1);
	out = 0;
	k = -1;
	while (++k < 6)
		out |= hex_c_to_int(color[k]) << ((5 - k) * 4);
	return (out);
}
