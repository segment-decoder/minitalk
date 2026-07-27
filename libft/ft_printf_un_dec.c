/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_un_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:31:01 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:24 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_un_dec(t_ull n, t_pads pads, t_flags *flags)
{
	if (ft_printf_fill_wid(pads.pre_pad, ' ') == -1)
		return (-1);
	if (ft_printf_fill_wid(pads.zero_pad, '0') == -1)
		return (-1);
	if (!(n == 0 && flags->precision == 0))
		if (ft_printf_putnbr(n, "0123456789") == -1)
			return (-1);
	if (ft_printf_fill_wid(pads.post_pad, ' ') == -1)
		return (-1);
	return (0);
}

int	ft_printf_un_dec(va_list args, t_flags *flags)
{
	unsigned int	n;
	t_pads			pads;
	int				total_len;

	n = va_arg(args, unsigned int);
	ft_printf_flag_dup(flags);
	flags->plus = 0;
	flags->space = 0;
	pads = ft_printf_init_pads(0, flags);
	total_len = ft_printf_set_pads((t_ull)n, &pads, flags, "0123456789");
	if (ft_put_un_dec((t_ull)n, pads, flags) == -1)
		return (-1);
	return (total_len);
}
