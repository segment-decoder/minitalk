/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:29:56 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:45:51 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list args, t_flags *flags)
{
	char	c;

	c = (char)va_arg(args, int);
	if (flags->width >= 0 && flags->minus == 0)
	{
		if (ft_printf_fill_wid(flags->width - 1, ' ') == -1)
			return (-1);
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	else
	{
		if (flags->width < 0)
			flags->width *= -1;
		if (write(1, &c, 1) == -1)
			return (-1);
		if (ft_printf_fill_wid(flags->width - 1, ' ') == -1)
			return (-1);
	}
	if (flags->width > 1)
		return (flags->width);
	else
		return (1);
}
