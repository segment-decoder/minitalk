/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:31:15 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:12 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_lower_hex(t_ull n, t_pads pads, t_flags *flags, char *base)
{
	if (ft_printf_fill_wid(pads.pre_pad, ' ') == -1)
		return (-1);
	if (flags->sharp != 0 && n != 0)
		if (write(1, "0x", 2) == -1)
			return (-1);
	if (ft_printf_fill_wid(pads.zero_pad, '0') == -1)
		return (-1);
	if (!(n == 0 && flags->precision == 0))
		if (ft_printf_putnbr(n, base) == -1)
			return (-1);
	if (ft_printf_fill_wid(pads.post_pad, ' ') == -1)
		return (-1);
	return (0);
}

int	ft_printf_lower_hex(va_list args, t_flags *flags)
{
	unsigned int	n;
	t_pads			pads;
	int				total_len;
	char			*base;

	n = va_arg(args, unsigned int);
	base = "0123456789abcdef";
	ft_printf_flag_dup(flags);
	flags->plus = 0;
	flags->space = 0;
	pads = ft_printf_init_pads(0, flags);
	if (flags->sharp != 0 && n != 0)
		pads.sign_len = 2;
	total_len = ft_printf_set_pads((t_ull)n, &pads, flags, base);
	if (ft_put_lower_hex((t_ull)n, pads, flags, base) == -1)
		return (-1);
	return (total_len);
}
