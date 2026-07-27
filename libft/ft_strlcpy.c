/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:36:17 by gyun              #+#    #+#             */
/*   Updated: 2025/11/10 21:38:36 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		++len;
	if (dsize == 0)
		return (len);
	while (src[i] && i + 1 < dsize)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}
