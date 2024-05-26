/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/26 14:23:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

size_t	soprint_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_len(char c, size_t *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr_len(char *s, size_t *len)
{
	if (!s)
		return (ft_putstr_len("(null)", len));
	*len += write(1, s, soprint_strlen(s));
}

void	ft_putstrs_len(char **strs, size_t *len)
{
	int	i;

	if (!strs)
		return (ft_putstr_len("(null)", len));
	i = 0;
	while (strs[i])
	{
		ft_putnbr_len(i, len);
		*len += write(1, "~", 1);
		*len += write(1, strs[i], soprint_strlen(strs[i]));
		*len += write(1, "\n", 1);
		i++;
	}
}
