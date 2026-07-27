/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:18:16 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:46:30 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_fill_wid(int i, char c)
{
	while (i-- > 0)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf_putnbr(t_ull n, char *base)
{
	t_ull	len;
	int		count;
	int		i;

	len = ft_strlen(base);
	count = 0;
	if (n >= len)
	{
		i = ft_printf_putnbr(n / len, base);
		if (i == -1)
			return (-1);
		count += i;
	}
	if (write(1, &base[n % len], 1) == -1)
		return (-1);
	return (++count);
}

int	ft_printf_nbrlen(t_ull n, char *base)
{
	int		len;
	t_ull	base_len;

	base_len = ft_strlen(base);
	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base_len;
		++len;
	}
	return (len);
}
