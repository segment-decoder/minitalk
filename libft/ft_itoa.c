/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:56:30 by gyun              #+#    #+#             */
/*   Updated: 2025/11/15 23:44:00 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setdigit(int n)
{
	int	out;

	out = 1;
	while (!(n < 10 && n > -10))
	{
		++out;
		n = n / 10;
	}
	return (out);
}

static void	ft_putnbr(char *out, long i, int digit)
{
	if (i >= 10)
		ft_putnbr(out, i / 10, digit - 1);
	out[digit] = '0' + i % 10;
}

char	*ft_itoa(int n)
{
	long	i;
	int		digit;
	char	*out;

	digit = ft_setdigit(n);
	if (n < 0)
	{
		out = (char *)malloc(sizeof(char) * (digit + 2));
		if (!out)
			return (NULL);
		i = n;
		out[digit + 1] = '\0';
		ft_putnbr(out, -i, digit);
		out[0] = '-';
	}
	else
	{
		out = (char *)malloc(sizeof(char) * (digit + 1));
		if (!out)
			return (NULL);
		i = n;
		out[digit] = '\0';
		ft_putnbr(out, i, digit - 1);
	}
	return (out);
}
