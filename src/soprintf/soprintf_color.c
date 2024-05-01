/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:30:23 by marvin            #+#    #+#             */
/*   Updated: 2024/05/01 05:30:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sotypes/all.h>

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

void	soprintf_putcolor_len(const char **s,va_list list_arg, size_t *len)
{
	(void)list_arg;
	int		var_len;
	char	*hex;
	int		flag;
	char*	ansi_code;

	(*s)++;
	if (!*s)
		return ft_putstr_len("\nERROR COLOR\n", len);
	hex = soprintf_color_gethex(*s, &var_len);
	*s += var_len;
	if (!hex)
		return ;
	flag = 1;
	if (**s == '(')
		(*s)++;
	else
		return (free(hex));
	ansi_code = hex_to_ansi(hex, 0);
	write(1, ansi_code, soprint_strlen(ansi_code));
	while (*s && (**s != ')' && flag > 0))
	{
		if (**s == '(')
			flag++;
		if (**s == ')' && flag > 0)
			flag--;
		if (**s == '%')
			soprintf_select(list_arg, s, len);
		else
			ft_putchar_len(**s, len);
		(*s)++;
	}
	ft_putchar_len(**s, len);
	write(1, "\033[0m", 4);
	(*s)++;
	free(hex);
	free(ansi_code);
}