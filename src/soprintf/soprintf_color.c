/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:30:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 18:37:17 by marvin           ###   ########.fr       */
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

char	*soprintf_color_gethex(const char *s, int *len)
{
	char	*hex;

	hex = (char *)malloc(sizeof(char) * (7));
	hex[6] = '\0';
	*len = 0;
	while (s[*len] && *len < 6 && s[*len] != '(')
	{
		hex[*len] = s[*len];
		(*len)++;
	}
	if (*len != 6)
		return (free(hex), NULL);
	return (hex);
}

size_t	soprintf_putcolor_write(int fd,
	const char **s, char *ansi_code, va_list list_arg)
{
	size_t	len;
	int		flag;

	flag = 1;
	len = 0;
	write(fd, "\033[1m", 4);
	write(fd, ansi_code, soprint_strlen(ansi_code));
	while (*s && flag > 0)
	{
		if (**s == '%')
			soprintf_select(fd, list_arg, s, &len);
		else
			ft_putchar_len(fd, **s, &len);
		(*s)++;
		if (**s == '(')
			flag++;
		if (**s == ')' && flag > 0)
			flag--;
		write(fd, ansi_code, soprint_strlen(ansi_code));
	}
	write(fd, "\033[0m", 4);
	free(ansi_code);
	return (len);
}

size_t	soprintf_putcolor_len(int fd, const char **s, va_list list_arg,
		int is_background)
{
	size_t	len;
	int		var_len;
	char	*hex;
	char	*ansi_code;

	(*s)++;
	len = 0;
	if (!*s)
		return (ft_putstr_len(fd, "\nERROR COLOR\n", &len), len);
	if (!soprintf_cmp(*s, "clear()", 7))
		return ((*s) += 6, write(fd, "\033[H\e[2J", 7));
	hex = soprintf_color_gethex(*s, &var_len);
	*s += var_len;
	if (!hex)
		return (len);
	if (**s == '(')
		(*s)++;
	else
		return (free(hex), len);
	ansi_code = hex_to_ansi(hex, is_background);
	return (free(hex), soprintf_putcolor_write(fd, s, ansi_code, list_arg));
}
