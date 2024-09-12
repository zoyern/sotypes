/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:00 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 18:11:48 by marvin           ###   ########.fr       */
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

void	ft_putchar_len(int fd, char c, size_t *len)
{
	*len += write(fd, &c, 1);
}

void	ft_putstr_len(int fd, char *s, size_t *len)
{
	if (!s)
		return (ft_putstr_len(fd, "(null)", len));
	*len += write(fd, s, soprint_strlen(s));
}

void	ft_putstrs_len(int fd, char **strs, size_t *len)
{
	int	i;

	if (!strs)
		return (ft_putstr_len(fd, "(null)", len));
	i = 0;
	while (strs[i])
	{
		ft_putnbr_len(fd, i, len);
		*len += write(fd, "~", 1);
		*len += write(fd, strs[i], soprint_strlen(strs[i]));
		*len += write(fd, "\n", 1);
		i++;
	}
}

void	ft_putbool_len(int fd, int boolean, size_t *len)
{
	if (boolean)
		*len += soprintf_fd(fd, "%C0000FF(TRUE)");
	else
		*len += soprintf_fd(fd, "%CFF0000(FALSE)");
}
