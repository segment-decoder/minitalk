/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:55:52 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 00:04:15 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _DEFAULT_SOURCE
# define SEND_DELAY 100
# define BYTE_TIMEOUT 10000

# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# include <errno.h>
# include "libft.h"

typedef struct sigaction	t_sig;

typedef struct s_server
{
	unsigned char	buf;
	int				bit_count;
	char			client_end;
}	t_server;

void	ft_exit(char *str, int app);

#endif