/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:27:00 by gyun              #+#    #+#             */
/*   Updated: 2026/07/26 18:03:56 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != 0 && s1[start])
		++start;
	while (end > start && ft_strrchr(set, s1[end - 1]) != 0 && s1[end - 1])
		--end;
	out = (char *)malloc(sizeof(char) * (end - start + 1));
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, &s1[start], end - start + 1);
	return (out);
}
