/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:30:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/27 01:37:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

/*
cbdipfsrm
c : 0 : Réinitialiser tous les attributs (normal).
b : 1 : Gras (bold).
d : 2 : Faible (dim).
i : 3 : Italique.
p : 4 : Souligné.
f : 5 : Clignotant (rarement utilisé dans les terminaux modernes).
s : 6 : swap fg to bg
r : 7 : Inverser les couleurs (texte en arrière-plan et vice versa).
m : 8 : Masqué (le texte n'est pas affiché).
*/

void	set_bit(int *number, int bit, int index)
{
	if (bit)
		*number |= 1 << index;
	else
		*number = ~(~*number | 1 << index);
}

int	get_bit(int number, int index)
{
	return (!!(number & (1 << index)));
}

#include <stdio.h>

int	set_option(const char *in, int *options)
{
	static char	*flags = "cbdipfsrm";
	size_t		k;

	while (in && *in && !solib_strchr("-#(", *in)) {
		k = 0;
		while (k < solib_strlen(flags)) {
			if (*in == flags[k])
				set_bit(options, 1, k);
			k++;
		}
		in++;
	}
	printf("opt:%d\n", *options);
	return (0);
}

int	split_color(int color, int *r, int *g, int *b)
{
	*r = (0xFF0000 & color) >> 16;
	*g = (0x00FF00 & color) >> 8;
	*b = (0x0000FF & color);
	return (1);
}

int	read_color(const char *color) {
	int	out;
	int	k;

	if (!color || solib_strlen(color) < 6)
		return (-1);
	out = 0;
	k = -1;
	while (++k < 6) {
		out |= hex_char_to_int(color[k]) << ((5 - k) * 4);
	}
	return (out);
}

void	set_color(char *out, int color)
{
	out[ 7] = '0' + ((color >> 16) & 0xFF) / 100 % 10;
	out[ 8] = '0' + ((color >> 16) & 0xFF) / 10 % 10;
	out[ 9] = '0' + ((color >> 16) & 0xFF) / 1 % 10;
	out[11] = '0' + ((color >> 8) & 0xFF) / 100 % 10;
	out[12] = '0' + ((color >> 8) & 0xFF) / 10 % 10;
	out[13] = '0' + ((color >> 8) & 0xFF) / 1 % 10;
	out[15] = '0' + ((color >> 0) & 0xFF) / 100 % 10;
	out[16] = '0' + ((color >> 0) & 0xFF) / 10 % 10;
	out[17] = '0' + ((color >> 0) & 0xFF) / 1 % 10;
}

#include <stdio.h>

void	write_color(int fd, int colors[2], int color_count, int swap)
{
	static char	foreground[] = "\033[38;2;000;000;000m";
	static char	background[] = "\033[48;2;000;000;000m";

	if (color_count > 0)
	{
		set_color(foreground, colors[(swap + 0) % 2]);
		write(fd, foreground, 19);
	}
	if (color_count > 1)
	{
		set_color(background, colors[(swap + 1) % 2]);
		write(fd, background, 19);
	}
}

int	write_options(int fd, int options)
{
	if (get_bit(options, 0))
		write(fd, "\033[0m", 4);
	if (get_bit(options, 1))
		write(fd, "\033[1m", 4);
	if (get_bit(options, 2))
		write(fd, "\033[2m", 4);
	if (get_bit(options, 3))
		write(fd, "\033[3m", 4);
	if (get_bit(options, 4))
		write(fd, "\033[4m", 4);
	if (get_bit(options, 5))
		write(fd, "\033[5m", 4);
	if (get_bit(options, 7))
		write(fd, "\033[7m", 4);
	if (get_bit(options, 8))
		write(fd, "\033[8m", 4);
	return (0);
}

void	soprintf_putcolor_len(int fd, const char **s, va_list list_arg, size_t *len)
{
	int		options;
	int		colors[2];
	int		color_count;

	(*s)++;// je viens de passé le %C-s#a2a2a(
	colors[0] = 0;
	colors[1] = 0;
	color_count = 0;
	options = 0;
	if (!*s)
		return (ft_putstr_len(fd, "\nERROR COLOR\n", len));
	if (!solib_strcmp(*s, "clear()", 7))
		return ((void)((*s) += 6, write(fd, "\033[H\e[2J", 7)));
	while (*s && **s && **s != '(')
	{
		if (**s == '#')
			colors[(color_count++) % 2] = read_color((*s + 1));
		if (**s == '-')
			set_option((*s + 1), &options);
		(*s)++;
	} 
	(*s)++;
	write_options(fd, options);
	write_color(fd, colors, color_count, get_bit(options, 6));
	while (*s && **s && (**s != ')'))
	{
		if (**s == '%')
		{
			soprintf_select(fd, list_arg, s, len);
			write_options(fd, options);
			write_color(fd, colors, color_count, get_bit(options, 6));
			(*s)++;
		}
		else
		{
			ft_putchar_len(fd, **s, len);
			(*s)++;
		}
	}
	write(fd, "\033[0m", 4);
}