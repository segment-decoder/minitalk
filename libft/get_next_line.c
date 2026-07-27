/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:13:18 by gyun              #+#    #+#             */
/*   Updated: 2026/07/27 16:17:56 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free_strs(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*ft_get_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_gnl_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		rd;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free_strs(stash, NULL));
	rd = 1;
	while (!ft_gnl_strchr(stash, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
			return (ft_free_strs(buff, stash));
		buff[rd] = '\0';
		stash = ft_gnl_strjoin(stash, buff);
		if (!stash)
			return (ft_free_strs(buff, NULL));
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || fd > FD_MAX - 1 || BUFFER_SIZE <= 0)
		return (0);
	stash[fd] = ft_read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_new_stash(stash[fd]);
	return (line);
}
