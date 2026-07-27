/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:33:41 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:21 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	ft_printf_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.sharp = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.wild_wid = 0;
	flags.wild_pre = 0;
	return (flags);
}

void	ft_printf_flag_dup(t_flags *flags)
{
	if (flags->width < 0)
		flags->minus = 1;
	if (flags->minus != 0 || flags->precision >= 0)
		flags->zero = 0;
	if (flags->plus != 0)
		flags->space = 0;
}

t_pads	ft_printf_init_pads(int n, t_flags *flags)
{
	t_pads	pads;

	pads.pre_pad = 0;
	pads.zero_pad = 0;
	pads.post_pad = 0;
	pads.sign_len = 1;
	if (n >= 0 && flags->plus != 0)
		pads.sign = '+';
	else if (n >= 0 && flags->space != 0)
		pads.sign = ' ';
	else if (n < 0)
		pads.sign = '-';
	else
	{
		pads.sign = 0;
		pads.sign_len = 0;
	}
	return (pads);
}

int	ft_printf_set_pads(t_ull n, t_pads *pads, t_flags *flags, char *base)
{
	int			n_len;
	long long	total_len;
	long long	pad_len;

	if (n == 0 && flags->precision == 0)
		n_len = 0;
	else
		n_len = ft_printf_nbrlen(n, base);
	if (flags->precision > n_len)
		pads->zero_pad = flags->precision - n_len;
	total_len = pads->sign_len + pads->zero_pad + n_len;
	pad_len = (long long)flags->width;
	if (pad_len < 0)
		pad_len *= -1;
	pad_len -= total_len;
	if (pad_len < 0)
		pad_len = 0;
	if (flags->minus != 0)
		pads->post_pad = (int)pad_len;
	else if (flags->zero != 0 && flags->precision < 0)
		pads->zero_pad += (int)pad_len;
	else
		pads->pre_pad = (int)pad_len;
	return ((int)(total_len + pad_len));
}
