/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:25:39 by gyun              #+#    #+#             */
/*   Updated: 2026/08/26 22:54:18 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server = {.buf = 0, .bit_count = 0};

static t_sig	ft_init_sig(void (*handler)(int, siginfo_t *, void *))
{
	t_sig	sig;

	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	return (sig);
}

static void	ft_reset_g(void)
{
	g_server.buf = 0;
	g_server.bit_count = 0;
}

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_server.buf = ((g_server.buf << 1) | (sig == SIGUSR2));
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		if (g_server.buf != '\0')
			write(1, &g_server.buf, 1);
		kill(info->si_pid, SIGUSR1);
		ft_reset_g();
	}
	return ;
}

int	main(void)
{
	t_sig	sig;

	sig = ft_init_sig(ft_handler);
	ft_printf("Server is now running.\nPID: %d\n", getpid());
	while (1)
	{
		if (usleep(BYTE_TIMEOUT) == 0)
			ft_reset_g();
	}
	return (0);
}
