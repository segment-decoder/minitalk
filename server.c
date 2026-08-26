/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:25:39 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 00:56:46 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server = {0};

static void	ft_reset_g(void)
{
	g_server.buf = 0;
	g_server.bit_count = 0;
}

static void	ft_handler(int sig)
{
	g_server.buf = ((g_server.buf << 1) | (sig == SIGUSR2));
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.buf == '\0')
		{
			g_server.client_end = 1;
			if (write(1, "\n", 1) == -1)
				ft_exit("Write function", 2);
		}
		else
			if (write(1, &g_server.buf, 1) == -1)
				ft_exit("Write function", 2);
		ft_reset_g();
	}
	return ;
}

int	main(void)
{
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	ft_printf("Server is now running.\nPID: %d\n", getpid());
	while (1)
	{
		pause();
		while (g_server.client_end != 1)
		{
			if (usleep(BYTE_TIMEOUT) == 0)
			{
				ft_reset_g();
				break ;
			}
		}
		g_server.client_end = 0;
	}
	return (0);
}
