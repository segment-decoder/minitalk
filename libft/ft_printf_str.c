/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:30:04 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 19:28:48 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_len(int len, int precision)
{
	if (len > precision)
		return (precision);
	else
		return (len);
}

static int	ft_putstr(char *s, int s_len)
{
	if (write(1, s, s_len) == -1)
		return (-1);
	return (0);
}

static int	ft_flag_minus(char *s, int width, int minus, int s_len)
{
	if (width >= 0 && minus == 0)
	{
		if (ft_printf_fill_wid(width - s_len, ' ') == -1)
			return (-1);
		if (ft_putstr(s, s_len) == -1)
			return (-1);
	}
	else
	{
		if (width < 0)
			width *= -1;
		if (ft_putstr(s, s_len) == -1)
			return (-1);
		if (ft_printf_fill_wid(width - s_len, ' ') == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf_str(va_list args, t_flags *flags)
{
	char	*s;
	int		s_len;

	s = (char *)va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (flags->precision >= 0)
		s_len = ft_s_len((int)ft_strlen(s), flags->precision);
	else
		s_len = (int)ft_strlen(s);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	if (ft_flag_minus(s, flags->width, flags->minus, s_len) == -1)
		return (-1);
	if (flags->width > s_len)
		return (flags->width);
	return (s_len);
}
