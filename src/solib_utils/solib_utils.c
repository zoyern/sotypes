/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 17:59:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

size_t	solib_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	solib_strcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	solib_strmcat(char **dst, char *src)
{
	char	*out;
	int		dst_len;
	int		src_len;
	int		k;

	dst_len = solib_strlen(*dst);
	src_len = solib_strlen(src);
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

char	*solib_strchr(const char *str, int c)
{
	if (*str == (unsigned char)c)
		return ((char *)str);
	if (!*str)
		return (0);
	return (solib_strchr(str + 1, c));
}

long long	solib_atoi(const char *nptr)
{
	long long	i;
	long long	sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr && (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	while (nptr && (nptr[i] == '-' || nptr[i] == '+'))
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr && (nptr[i] >= '0' && nptr[i] <= '9'))
		num = (num * 10) + (nptr[i++] - '0');
	return (num * sign);
}
