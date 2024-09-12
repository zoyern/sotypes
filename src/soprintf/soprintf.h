/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:57:56 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 18:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOPRINTF_H
# define SOPRINTF_H

# include <sotypes/all.h>

void	soprintf_select(int fd, va_list list_arg, const char **str,
			size_t *len);
size_t	soprint_strlen(const char *str);
size_t	soprintf_putcolor_len(int fd, const char **s, va_list list_arg,
			int is_background);
void	ft_putchar_len(int fd, char c, size_t *len);
void	ft_putstr_len(int fd, char *s, size_t *len);
void	ft_putstrs_len(int fd, char **strs, size_t *len);
void	ft_putbool_len(int fd, int boolean, size_t *len);
void	ft_putnbr_len(int fd, long long n, size_t *len);
void	ft_putnbr_len_base(int fd, unsigned long long n, char *base,
			size_t *len);
void	ft_putptr_len(int fd, unsigned long n, char *base, size_t *len);
char	*hex_to_ansi(char *hex, int is_background);
char	*ansi_format(int cc, int is_background);
char	*ansi_concat(char *base, char *cc, char *out);
int		ansi_16_basic_colors(int r, int g, int b);
void	ansi_16_basic_colors_blue(int b, int *cc);
void	ansi_16_basic_colors_green(int g, int *cc);
void	ansi_16_basic_colors_red(int r, int *cc);
int		ansi_grey_ramp(int r, int g, int b);
void	soconvert_hex_to_rgb(char *hex, int *r, int *g, int *b);
int		hex_char_to_int(char hex_char);
char	*ansi_itoa(int n);
size_t	ansi_nbrlen(int n);
void	ansi_strmcat(char **dst, char *src);
int		soconvert_rgb_to_ansi(int r, int g, int b);
int		soprintf_cmp(const char *s1, const char *s2, size_t n);

#endif
