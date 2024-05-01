/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_ansi_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:22:43 by marvin            #+#    #+#             */
/*   Updated: 2024/05/01 05:22:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int hex_char_to_int(char hex_char)
{
    if (hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0';
    } else if (hex_char >= 'A' && hex_char <= 'F') {
        return hex_char - 'A' + 10;
    } else if (hex_char >= 'a' && hex_char <= 'f') {
        return hex_char - 'a' + 10;
    } else {
        return -1;
    }
}

void	soconvert_hex_to_rgb(char *hex, int *r, int *g, int *b)
{
	*r = hex_char_to_int(hex[0]) * 16 + hex_char_to_int(hex[1]);
    *g = hex_char_to_int(hex[2]) * 16 + hex_char_to_int(hex[3]);
    *b = hex_char_to_int(hex[4]) * 16 + hex_char_to_int(hex[5]);
}