/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:56:48 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:09 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(const char format, va_list args, t_flags *flags)
{
	if (format == 'c')
		return (ft_printf_char(args, flags));
	if (format == 's')
		return (ft_printf_str(args, flags));
	if (format == 'p')
		return (ft_printf_ptr(args, flags));
	if (format == 'd' || format == 'i')
		return (ft_printf_dec(args, flags));
	if (format == 'u')
		return (ft_printf_un_dec(args, flags));
	if (format == 'x')
		return (ft_printf_lower_hex(args, flags));
	if (format == 'X')
		return (ft_printf_upper_hex(args, flags));
	if (format == '%')
	{
		if (write(1, &"%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	ft_printnbr(long i, int len)
{
	char	out;

	if (i < 0)
	{
		i *= -1;
		if (write(1, &"-", 1) == -1)
			return (-1);
		++len;
	}
	out = i % 10 + '0';
	if (i >= 10)
		len = ft_printnbr(i / 10, ++len);
	if (write(1, &out, 1) == -1)
		return (-1);
	return (len);
}

static int	ft_print_nformat(const char *format, int i, t_flags *flags)
{
	int	idx;
	int	out;

	idx = 0;
	out = 0;
	while (*format && i-- > 0)
	{
		if (*format == '*' && flags->wild_wid-- == 1)
			idx = ft_printnbr(flags->width, 1);
		else if (*format == '*' && flags->wild_pre-- == 1)
			idx = ft_printnbr(flags->precision, 1);
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			++out;
		}
		if (idx == -1)
			return (-1);
		out += idx;
		format++;
	}
	return (out);
}

int	ft_printf_help(const char *format, int i, t_flags *flags, va_list args)
{
	int		out;

	out = 0;
	if (ft_strchr("cspdiuxX%", format[i]) != NULL)
		return (ft_print_format(format[i], args, flags));
	else
	{
		out = ft_print_nformat(format, i + 1, flags);
		if (out == -1)
			return (-1);
		return (out);
	}
}
