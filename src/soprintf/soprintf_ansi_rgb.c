/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_ansi_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:18:35 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 12:42:39 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	ansi_grey_ramp(int r, int g, int b)
{
	int	grey;
	int	cc;

	grey = (r + g + b) / 3;
	if (grey < 5)
		cc = 0;
	else if (grey > 246)
		cc = 15;
	else
		cc = (grey - 3) / 10 + 232;
	return (cc);
}

void	ansi_16_basic_colors_red(int r, int *cc)
{
	if (r < 48)
		;
	else if (r < 115)
		*cc += (36 * 1);
	else if (r < 156)
		*cc += (36 * 2);
	else if (r < 196)
		*cc += (36 * 3);
	else if (r < 235)
		*cc += (36 * 4);
	else
		*cc += (36 * 5);
}

void	ansi_16_basic_colors_green(int g, int *cc)
{
	if (g < 115 && g > 47)
		*cc += (6 * 1);
	else if (g < 156)
		*cc += (6 * 2);
	else if (g < 196)
		*cc += (6 * 3);
	else if (g < 235)
		*cc += (6 * 4);
	else
		*cc += (6 * 5);
}

void	ansi_16_basic_colors_blue(int b, int *cc)
{
	if (b < 48)
		;
	else if (b < 115)
		*cc += 1;
	else if (b < 156)
		*cc += 2;
	else if (b < 196)
		*cc += 3;
	else if (b < 235)
		*cc += 4;
	else
		*cc += 5;
}
