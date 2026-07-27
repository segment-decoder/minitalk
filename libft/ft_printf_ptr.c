/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:30:12 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 19:34:06 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ptr_null(t_flags *flags)
{
	long long	width;

	width = (long long)flags->width;
	if (width < 0)
	{
		flags->minus = 1;
		width *= -1;
	}
	if (flags->minus == 0)
		if (ft_printf_fill_wid((int)(width - 5), ' ') == -1)
			return (-1);
	if (write(1, "(nil)", 5) == -1)
		return (-1);
	if (flags->minus != 0)
		if (ft_printf_fill_wid((int)(width - 5), ' ') == -1)
			return (-1);
	if (width > 5)
		return ((int)width);
	return (5);
}

static int	ft_put_ptr(t_ull ptr, t_pads pads, char *base)
{
	if (ft_printf_fill_wid(pads.pre_pad, ' ') == -1)
		return (-1);
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_printf_fill_wid(pads.zero_pad, '0') == -1)
		return (-1);
	if (ft_printf_putnbr(ptr, base) == -1)
		return (-1);
	if (ft_printf_fill_wid(pads.post_pad, ' ') == -1)
		return (-1);
	return (0);
}

int	ft_printf_ptr(va_list args, t_flags *flags)
{
	void	*ptr;
	t_pads	pads;
	int		total_len;
	char	*base;

	ptr = va_arg(args, void *);
	ft_printf_flag_dup(flags);
	flags->plus = 0;
	flags->space = 0;
	if (ptr == NULL)
		return (ft_ptr_null(flags));
	base = "0123456789abcdef";
	pads = ft_printf_init_pads(0, flags);
	pads.sign_len = 2;
	total_len = ft_printf_set_pads((t_ull)ptr, &pads, flags, base);
	if (ft_put_ptr((t_ull)ptr, pads, base) == -1)
		return (-1);
	return (total_len);
}
