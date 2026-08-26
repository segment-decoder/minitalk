/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:25:39 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 04:22:27 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server = {0};

static void	ft_init_sig(void (*handler)(int))
{
	t_sig	sig;

	sig.sa_handler = handler;
	sig.sa_flags = 0;
	if (sigemptyset(&sig.sa_mask))
		ft_exit("Signal set", SERVER_SEND);
	if (sigaddset(&sig.sa_mask, SIGUSR1) || sigaddset(&sig.sa_mask, SIGUSR2))
		ft_exit("Signal set", SERVER_SEND);
	if (sigaction(SIGUSR1, &sig, NULL) || sigaction(SIGUSR2, &sig, NULL))
		ft_exit("Signal set", SERVER_SEND);
}

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
				ft_exit("Write function", SERVER_SEND);
		}
		else
			if (write(1, &g_server.buf, 1) == -1)
				ft_exit("Write function", SERVER_SEND);
		ft_reset_g();
	}
	return ;
}

int	main(void)
{
	ft_init_sig(ft_handler);
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
