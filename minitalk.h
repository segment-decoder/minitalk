/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:55:52 by gyun              #+#    #+#             */
/*   Updated: 2026/08/26 20:11:36 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _DEFAULT_SOURCE
# define SEND_DELAY 100
# define BYTE_TIMEOUT 100000

# include <signal.h>
# include <sys/types.h>
# include <limits.h>
# include "libft.h"

typedef struct s_server
{
	unsigned char	buf;
	int				bit_count;
	int				pid;
}	t_server;

#endif