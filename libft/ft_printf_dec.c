/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:30:39 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:00 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_dec(t_ull n, t_pads pads, t_flags *flags)
{
	if (ft_printf_fill_wid(pads.pre_pad, ' ') == -1)
		return (-1);
	if (pads.sign != 0)
		if (write(1, &pads.sign, 1) == -1)
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

int	ft_printf_dec(va_list args, t_flags *flags)
{
	long long	n;
	t_ull		abs_n;
	int			total_len;
	t_pads		pads;

	n = va_arg(args, int);
	ft_printf_flag_dup(flags);
	pads = ft_printf_init_pads(n, flags);
	if (n < 0)
		abs_n = (t_ull)(-(long long)n);
	else
		abs_n = (t_ull)n;
	total_len = ft_printf_set_pads(abs_n, &pads, flags, "0123456789");
	if (ft_put_dec(abs_n, pads, flags) == -1)
		return (-1);
	return (total_len);
}
