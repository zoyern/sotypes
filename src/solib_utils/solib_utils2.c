/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 19:28:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

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

int	set_option(const char *in, int *options)
{
	static char	*flags = "cbdipfsrm";
	size_t		k;

	while (in && *in && !solib_strchr("-#(", *in))
	{
		k = 0;
		while (k < solib_strlen(flags))
		{
			if (*in == flags[k])
				set_bit(options, 1, k);
			k++;
		}
		in++;
	}
	return (0);
}

int	check_c_in_str(const char **s, char c_in, char c_out, int *count)
{
	int	nbr;

	nbr = 0;
	if (**s == c_in)
	{
		nbr = 1;
		(*count)++;
	}
	if (**s == c_out)
	{
		nbr = -1;
		(*count)--;
	}
	return (nbr);
}

t_sofuncs	sofuncs(int (*start)(),
		int (*update)(), int (*quit)())
{
	t_sofuncs	funcs;

	funcs.start = start;
	funcs.update = update;
	funcs.quit = quit;
	return (funcs);
}
