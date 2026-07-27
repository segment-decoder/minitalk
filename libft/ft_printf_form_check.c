/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_form_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 03:08:28 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:06 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isflag(const char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '#')
		flags->sharp = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
	else
		return (0);
	return (1);
}

static int	ft_iswidth(const char *format, t_flags *flags, va_list args)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (*format == '*')
	{
		flags->width = va_arg(args, int);
		flags->wild_wid = 1;
		++i;
		while (ft_isdigit(format[i]) != 0)
			++i;
	}
	else
	{
		while (ft_isdigit(format[i]) != 0)
			num = num * 10 + (format[i++] - '0');
		flags->width = num;
	}
	return (i);
}

static int	ft_isprecision(const char *format, t_flags *flags, va_list args)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (format[i] == '*')
	{
		flags->precision = va_arg(args, int);
		flags->wild_pre = 1;
		++i;
		while (ft_isdigit(format[i]) != 0)
			++i;
	}
	else
	{
		while (ft_isdigit(format[i]) != 0)
			num = num * 10 + (format[i++] - '0');
		flags->precision = num;
	}
	return (i);
}

int	ft_printf_form_check(const char *format, t_flags *flags, va_list args)
{
	size_t	i;

	i = 0;
	if (ft_strchr("cspdiuxX%", *format) != NULL)
		return (i);
	while (ft_isflag(format[i], flags) != 0)
		++i;
	i += ft_iswidth(format + i, flags, args);
	if (format[i] == '.')
	{
		i++;
		i += ft_isprecision(format + i, flags, args);
	}
	return (i);
}
