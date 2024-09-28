/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solib_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 22:54:14 by marvin           ###   ########.fr       */
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

char	*soprintf_get(t_solib *solib, const char *str, ...)
{
	va_list	list_arg;
	int		pipefd[2];
	char	*buf;
	char	*line;
	char	*ret;

	if (pipe(pipefd) == -1)
		solib_close(solib, EXIT_FAILURE);
	if (!str)
		return (NULL);
	va_start(list_arg, str);
	ft_printf(pipefd[1], str, list_arg);
	buf = soenv_strdup(NULL, " ");
	line = soenv_strdup(NULL, "");
	close(pipefd[1]);
	while (read(pipefd[0], buf, 1))
		solib_strmcat(&line, buf);
	free(buf);
	ret = soenv_strdup(solib, line);
	free(line);
	close(pipefd[0]);
	return (ret);
}
