/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:15:00 by gyun              #+#    #+#             */
/*   Updated: 2025/11/15 23:44:46 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*out;

	i = 0;
	out = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (out == NULL)
		return (NULL);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		++i;
	}
	out[i] = '\0';
	return (out);
}
