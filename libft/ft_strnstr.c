/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:05:48 by gyun              #+#    #+#             */
/*   Updated: 2025/11/10 21:38:39 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	idx;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		idx = 0;
		while (big[i + idx] == little[idx] && little[idx] && i + idx < len)
			++idx;
		if (little[idx] == '\0')
			return ((char *)(big + i));
		++i;
	}
	return (NULL);
}
