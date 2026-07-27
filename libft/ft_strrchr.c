/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:24:58 by gyun              #+#    #+#             */
/*   Updated: 2025/11/10 21:38:39 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*s)
	{
		if (*s == (char)c)
			p = s;
		++s;
	}
	if (*s == (char)c)
		p = s;
	if (*p == (char)c)
		return ((char *)p);
	return (0);
}
