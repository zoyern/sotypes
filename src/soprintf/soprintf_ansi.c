/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_ansi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:19:02 by marvin            #+#    #+#             */
/*   Updated: 2024/05/01 05:19:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	ansi_16_basic_colors(int r, int g, int b)
{
	int cc;

	cc = 16;
	ansi_16_basic_colors_red(r, &cc);
    ansi_16_basic_colors_green(g, &cc);
	ansi_16_basic_colors_blue(b, &cc);
	return (cc);
}

char	*ansi_concat(char *base, char *cc, char *out)
{
	if (!cc)
		return (NULL);
	ansi_strmcat(&out, base);
	ansi_strmcat(&out, cc);
	free(cc);
	ansi_strmcat(&out, "m");
	return (out);
}

char	*ansi_format(int cc, int is_background)
{
	char	*out;

	out = (char *)malloc(1);
	out[0] = '\0';
	if (!is_background)
        return (ansi_concat("\033[38;5;", ansi_itoa(cc), out));
	else
		return (ansi_concat("\033[48;5;", ansi_itoa(cc), out));
}

char*	hex_to_ansi(char* hex, int is_background)
{
    int	r;
	int	g;
	int	b;
	int cc;

	soconvert_hex_to_rgb(hex, &r, &g, &b);
	cc = soconvert_rgb_to_ansi(r,g,b);
    return (ansi_format(cc, is_background));
}