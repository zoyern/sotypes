/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 04:15:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	soprintf_select_nbr(int fd, va_list list_arg, const char **str,
			size_t *len)
{
	if (!solib_strcmp(*str, "i", 1) || !solib_strcmp(*str, "d", 1))
		return (ft_putnbr_len(fd, va_arg(list_arg, int), len));
	else if (!solib_strcmp(*str, "X", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789ABCDEF", len));
	else if (!solib_strcmp(*str, "x", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789abcdef", len));
	else if (!solib_strcmp(*str, "u", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789", len));
	else if (!solib_strcmp(*str, "p", 1))
		return (ft_putptr_len(fd, (va_arg(list_arg, unsigned long)),
				"0123456789abcdef", len));
}

size_t	soprintf_select(int fd, va_list list_arg, const char **str, size_t *len)
{
	size_t	tmp;

	tmp = *len;
	(*str)++;
	if (!solib_strcmp(*str, "lld", 3))
		return ((*str) += 2, ft_putnbr_len(fd, va_arg(list_arg, long long),
				len), *len - tmp);
	if (!solib_strcmp(*str, "ld", 2))
		return ((*str)++, ft_putnbr_len(fd, va_arg(list_arg, long), len),
			*len - tmp);
	if (!solib_strcmp(*str, "c", 1))
		return (ft_putchar_len(fd, va_arg(list_arg, int), len), *len - tmp);
	else if (!solib_strcmp(*str, "C", 1))
		return (soprintf_putcolor_len(fd, str, list_arg, len), *len - tmp);
	else if (!solib_strcmp(*str, "%", 1))
		return (ft_putchar_len(fd, '%', len), *len - tmp);
	else if (!solib_strcmp(*str, "s", 1))
		return (ft_putstr_len(fd, va_arg(list_arg, char *), len), *len - tmp);
	else if (!solib_strcmp(*str, "S", 1))
		return (ft_putstrs_len(fd, va_arg(list_arg, char **), len), *len - tmp);
	else if (!solib_strcmp(*str, "b", 1))
		return (ft_putbool_len(fd, va_arg(list_arg, int), len), *len - tmp);
	return (soprintf_select_nbr(fd, list_arg, str, len), *len - tmp);
}

int	ft_printf(int fd, const char *str, va_list args)
{
	size_t	len;

	len = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			soprintf_select(fd, args, &str, &len);
		else
			ft_putchar_len(fd, *str, &len);
		str++;
	}
	va_end(args);
	return (len);
}

int	soprintf(const char *str, ...)
{
	va_list	list_arg;

	if (!str)
		return (-1);
	va_start(list_arg, str);
	return (ft_printf(1, str, list_arg));
}

int	soprintf_fd(int fd, const char *str, ...)
{
	va_list	list_arg;

	if (!str)
		return (-1);
	va_start(list_arg, str);
	return (ft_printf(fd, str, list_arg));
}
