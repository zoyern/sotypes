/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/14 21:36:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	ft_putchar_len(int fd, char c, size_t *len)
{
	if (len)
		*len += write(fd, &c, 1);
	else
		write(fd, &c, 1);
}

void	ft_putstr_len(int fd, char *s, size_t *len)
{
	if (!s)
		return (ft_putstr_len(fd, "(null)", len));
	if (len)
		*len += write(fd, s, solib_strlen(s));
	else
		write(fd, s, solib_strlen(s));
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
		ft_putchar_len(fd, '~', len);
		ft_putstr_len(fd, strs[i], len);
		ft_putchar_len(fd, '\n', len);
		i++;
	}
}

void	ft_putbool_len(int fd, int boolean, size_t *len)
{
	if (boolean)
		*len += soprintf_fd(fd, "%C-bi#0000FF(TRUE)");
	else
		*len += soprintf_fd(fd, "%C-bi#FF0000(FALSE)");
}
