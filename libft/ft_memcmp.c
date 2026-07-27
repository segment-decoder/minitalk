/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:57:28 by gyun              #+#    #+#             */
/*   Updated: 2025/11/10 21:38:27 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_p;
	unsigned char	*s2_p;

	i = 0;
	if (n == 0)
		return (0);
	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	while (i < n && s1_p[i] == s2_p[i])
		++i;
	if (!(i < n))
		return (0);
	else if (s1_p[i] < s2_p[i])
		return (-1);
	else
		return (1);
}
