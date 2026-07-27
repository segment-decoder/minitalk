/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:12:21 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:32 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format_handler(const char *format, va_list args)
{
	int		len;
	int		i;
	t_flags	flags;

	len = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_printf_init_flags();
			i = ft_printf_form_check(++format, &flags, args) + 1;
			i = ft_printf_help((format += i) - (i + 1), i, &flags, args);
			if (i == -1)
				return (-1);
			len += i;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		output;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	output = ft_format_handler(format, args);
	va_end(args);
	return (output);
}
