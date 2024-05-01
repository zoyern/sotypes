/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_ansi_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:19:43 by marvin            #+#    #+#             */
/*   Updated: 2024/05/01 05:19:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

int	soconvert_rgb_to_ansi(int r, int g, int b)
{
	if (abs(r - g) < 16 && abs(r - b) < 16 && abs(g - b) < 16)
		return (ansi_grey_ramp(r,g,b));
    return (ansi_16_basic_colors(r,g,b));
}

void	ansi_strmcat(char **dst, char *src)
{
	char	*out;
	int		dst_len;
	int		src_len;
	int		k;

	dst_len = soprint_strlen(*dst);
	src_len = soprint_strlen(src);
	out = malloc((dst_len + src_len + 1) * sizeof(char));
	k = 0;
	while (k < (dst_len + src_len))
	{
		if (k < dst_len)
			out[k] = (*dst)[k];
		else
		{
			if (src[k - dst_len] == -1)
				break ;
			out[k] = src[k - dst_len];
		}
		k++;
	}
	out[k] = 0;
	free(*dst);
	*dst = out;
}

size_t	ansi_nbrlen(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ansi_itoa(int n)
{
	char		*s;
	size_t		count;
	int			sign;
	long int	nb;

	nb = n;
	count = ansi_nbrlen(nb);
	sign = 0;
	s = (char *)malloc(sizeof(char) * count + 1);
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[sign++] = '-';
	}
	while (count-- > (size_t)sign)
	{
		s[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}