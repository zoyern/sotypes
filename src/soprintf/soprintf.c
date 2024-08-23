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

int	soprintf_cmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	soprintf_select_nbr(va_list list_arg, const char **str, size_t *len)
{
	if (!soprintf_cmp(*str, "i", 1) || !soprintf_cmp(*str, "d", 1))
		return (ft_putnbr_len(va_arg(list_arg, int), len));
	else if (!soprintf_cmp(*str, "X", 1))
		return (ft_putnbr_len_base((va_arg(list_arg, unsigned int)),
				"0123456789ABCDEF", len));
	else if (!soprintf_cmp(*str, "x", 1))
		return (ft_putnbr_len_base((va_arg(list_arg, unsigned int)),
				"0123456789abcdef", len));
	else if (!soprintf_cmp(*str, "u", 1))
		return (ft_putnbr_len_base((va_arg(list_arg, unsigned int)),
				"0123456789", len));
	else if (!soprintf_cmp(*str, "p", 1))
		return (ft_putptr_len((va_arg(list_arg, unsigned long)),
				"0123456789abcdef", len));
}

void	soprintf_select(va_list list_arg, const char **str, size_t *len)
{
	(*str)++;
	if (!soprintf_cmp(*str, "lld", 1))
		return (ft_putnbr_len(va_arg(list_arg, long long), len));
	if (!soprintf_cmp(*str, "ld", 1))
		return (ft_putnbr_len(va_arg(list_arg, long), len));
	if (!soprintf_cmp(*str, "c", 1))
		return (ft_putchar_len(va_arg(list_arg, int), len));
	else if (!soprintf_cmp(*str, "C", 1))
		return (soprintf_putcolor_len(str, list_arg, 0, len));
	else if (!soprintf_cmp(*str, "B", 1))
		return (soprintf_putcolor_len(str, list_arg, 1, len));
	else if (!soprintf_cmp(*str, "%", 1))
		return (ft_putchar_len('%', len));
	else if (!soprintf_cmp(*str, "s", 1))
		return (ft_putstr_len(va_arg(list_arg, char *), len));
	else if (!soprintf_cmp(*str, "S", 1))
		return (ft_putstrs_len(va_arg(list_arg, char **), len));
	else if (!soprintf_cmp(*str, "b", 1))
		return (ft_putbool_len(va_arg(list_arg, int), len));
	soprintf_select_nbr(list_arg, str, len);
}

int	soprintf(const char *str, ...)
{
	va_list	list_arg;
	size_t	len;

	len = 0;
	if (!str)
		return (-1);
	va_start(list_arg, str);
	while (*str)
	{
		if (*str == '%')
			soprintf_select(list_arg, &str, &len);
		else
			ft_putchar_len(*str, &len);
		str++;
	}
	va_end(list_arg);
	return (len);
}
