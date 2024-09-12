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
	if (!soprintf_cmp(*str, "i", 1) || !soprintf_cmp(*str, "d", 1))
		return (ft_putnbr_len(fd, va_arg(list_arg, int), len));
	else if (!soprintf_cmp(*str, "X", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789ABCDEF", len));
	else if (!soprintf_cmp(*str, "x", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789abcdef", len));
	else if (!soprintf_cmp(*str, "u", 1))
		return (ft_putnbr_len_base(fd, (va_arg(list_arg, unsigned int)),
				"0123456789", len));
	else if (!soprintf_cmp(*str, "p", 1))
		return (ft_putptr_len(fd, (va_arg(list_arg, unsigned long)),
				"0123456789abcdef", len));
}

void	soprintf_select(int fd, va_list list_arg, const char **str, size_t *len)
{
	(*str)++;
	if (!soprintf_cmp(*str, "lld", 3))
		return ((*str) += 2, ft_putnbr_len(fd, va_arg(list_arg, long long),
				len));
	if (!soprintf_cmp(*str, "ld", 2))
		return ((*str)++, ft_putnbr_len(fd, va_arg(list_arg, long), len));
	if (!soprintf_cmp(*str, "c", 1))
		return (ft_putchar_len(fd, va_arg(list_arg, int), len));
	else if (!soprintf_cmp(*str, "C", 1))
		return ((void)(*len += soprintf_putcolor_len(fd, str, list_arg, 0)));
	else if (!soprintf_cmp(*str, "B", 1))
		return ((void)(*len += soprintf_putcolor_len(fd, str, list_arg, 1)));
	else if (!soprintf_cmp(*str, "%", 1))
		return (ft_putchar_len(fd, '%', len));
	else if (!soprintf_cmp(*str, "s", 1))
		return (ft_putstr_len(fd, va_arg(list_arg, char *), len));
	else if (!soprintf_cmp(*str, "S", 1))
		return (ft_putstrs_len(fd, va_arg(list_arg, char **), len));
	else if (!soprintf_cmp(*str, "b", 1))
		return (ft_putbool_len(fd, va_arg(list_arg, int), len));
	soprintf_select_nbr(fd, list_arg, str, len);
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
