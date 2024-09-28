/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:30:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 23:28:11 by marvin           ###   ########.fr       */
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

void	set_color(char *out, int color)
{
	out[7] = '0' + ((color >> 16) & 0xFF) / 100 % 10;
	out[8] = '0' + ((color >> 16) & 0xFF) / 10 % 10;
	out[9] = '0' + ((color >> 16) & 0xFF) / 1 % 10;
	out[11] = '0' + ((color >> 8) & 0xFF) / 100 % 10;
	out[12] = '0' + ((color >> 8) & 0xFF) / 10 % 10;
	out[13] = '0' + ((color >> 8) & 0xFF) / 1 % 10;
	out[15] = '0' + ((color >> 0) & 0xFF) / 100 % 10;
	out[16] = '0' + ((color >> 0) & 0xFF) / 10 % 10;
	out[17] = '0' + ((color >> 0) & 0xFF) / 1 % 10;
}

void	write_color(int fd, int colors[4], int swap)
{
	static char	foreground[] = "\033[38;2;000;000;000m";
	static char	background[] = "\033[48;2;000;000;000m";

	if (colors[2] > 0)
	{
		set_color(foreground, colors[(swap + 0) % 2]);
		write(fd, foreground, 19);
	}
	if (colors[2] > 1)
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

size_t	write_all_color(int fd, int colors[4], const char **s, va_list list_arg)
{
	size_t	len;
	int		count;

	count = 0;
	len = 0;
	write_options(fd, colors[3]);
	write_color(fd, colors, get_bit(colors[3], 6));
	while (*s && **s && !(**s == ')' && count < 1))
	{
		if (**s == '%')
		{
			soprintf_select(fd, list_arg, s, &len);
			write_options(fd, colors[3]);
			write_color(fd, colors, get_bit(colors[3], 6));
			(*s)++;
		}
		else
		{
			check_c_in_str(s, '(', ')', &count);
			ft_putchar_len(fd, **s, &len);
			(*s)++;
		}
	}
	write(fd, "\033[0m", 4);
	return (len);
}

void	soprintf_putcolor_len(int fd, const char **s, va_list list_arg,
			size_t *len)
{
	int		colors[4];

	(*s)++;
	colors[0] = 0;
	colors[1] = 0;
	colors[2] = 0;
	colors[3] = 0;
	if (!*s)
		return (ft_putstr_len(fd, "\nERROR COLOR\n", len));
	if (!solib_strcmp(*s, "clear()", 7))
		return ((void)((*s) += 6, write(fd, "\033[H\e[2J", 7)));
	while (*s && **s && **s != '(')
	{
		if (**s == '#')
			colors[(colors[2]++) % 2] = read_hex_to_int((*s + 1));
		if (**s == '-')
			set_option((*s + 1), &colors[3]);
		(*s)++;
	}
	(*s)++;
	*len += write_all_color(fd, colors, s, list_arg);
}
