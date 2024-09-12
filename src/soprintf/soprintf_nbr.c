/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:03:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 18:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	ft_putnbr_len(int fd, long long n, size_t *len)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_len(fd, '-', len);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_len(fd, nbr / 10, len);
		ft_putnbr_len(fd, nbr % 10, len);
	}
	else
		ft_putchar_len(fd, nbr + '0', len);
}

void	ft_putnbr_len_base(int fd, unsigned long long n, char *base,
			size_t *len)
{
	unsigned long long	nbr;
	unsigned long long	len_base;

	nbr = n;
	len_base = soprint_strlen(base);
	if (nbr > (len_base - 1))
	{
		ft_putnbr_len_base(fd, nbr / len_base, base, len);
		ft_putnbr_len_base(fd, nbr % len_base, base, len);
	}
	else
		ft_putchar_len(fd, base[nbr], len);
}

void	ft_putptr_len(int fd, unsigned long n, char *base, size_t *len)
{
	if (n == 0)
	{
		ft_putstr_len(fd, "(nil)", len);
		return ;
	}
	ft_putstr_len(fd, "0x", len);
	ft_putnbr_len_base(fd, n, base, len);
}
