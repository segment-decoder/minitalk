/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:58:49 by gyun              #+#    #+#             */
/*   Updated: 2025/11/10 21:38:17 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	out;
	int	neg;

	neg = 1;
	out = 0;
	while (*nptr == 32 || (9 <= *nptr && *nptr <= 13))
		++nptr;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg = -neg;
		++nptr;
	}
	if (!('0' <= *nptr && *nptr <= '9'))
		return (0);
	while ('0' <= *nptr && *nptr <= '9')
	{
		out = out * 10 + (*nptr - '0');
		++nptr;
	}
	return (neg * out);
}
