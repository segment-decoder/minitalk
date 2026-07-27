/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:52:59 by gyun              #+#    #+#             */
/*   Updated: 2025/11/15 23:44:28 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **out, size_t dimension)
{
	while (dimension--)
	{
		free(out[dimension]);
	}
	free(out);
}

static size_t	ft_dimentioncheck(char const *s, char c)
{
	size_t	i;
	size_t	dimension;

	i = 0;
	dimension = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		if (s[i])
			++dimension;
		while (s[i] && s[i] != c)
			++i;
	}
	return (dimension);
}

static int	ft_fillstr(char **out, char const *s, char c)
{
	size_t	i;
	size_t	dimension;

	dimension = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (!(*s))
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			++i;
		out[dimension] = malloc(sizeof(char) * (i + 1));
		if (out[dimension] == NULL)
		{
			ft_free(out, dimension);
			return (0);
		}
		ft_strlcpy(out[dimension], s, i + 1);
		out[dimension][i] = '\0';
		++dimension;
		s += i;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	dimension;
	char	**out;

	if (s == NULL)
		return (NULL);
	dimension = ft_dimentioncheck(s, c);
	out = (char **)malloc(sizeof(char *) * (dimension + 1));
	if (out == NULL)
		return (NULL);
	if (ft_fillstr(out, s, c) == 0)
		return (NULL);
	out[dimension] = NULL;
	return (out);
}
