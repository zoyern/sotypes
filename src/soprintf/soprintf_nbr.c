/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:03:54 by marvin            #+#    #+#             */
/*   Updated: 2024/08/23 20:12:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

void	ft_putnbr_len(long long n, size_t *len)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_len('-', len);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_len(nbr / 10, len);
		ft_putnbr_len(nbr % 10, len);
	}
	else
		ft_putchar_len(nbr + '0', len);
}

void	ft_putnbr_len_base(unsigned long long n, char *base, size_t *len)
{
	unsigned long long	nbr;
	unsigned long long	len_base;

	nbr = n;
	len_base = soprint_strlen(base);
	if (nbr > (len_base - 1))
	{
		ft_putnbr_len_base(nbr / len_base, base, len);
		ft_putnbr_len_base(nbr % len_base, base, len);
	}
	else
		ft_putchar_len(base[nbr], len);
}

void	ft_putptr_len(unsigned long n, char *base, size_t *len)
{
	if (n == 0)
	{
		ft_putstr_len("(nil)", len);
		return ;
	}
	ft_putstr_len("0x", len);
	ft_putnbr_len_base(n, base, len);
}
