/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:56:05 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 01:38:31 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack = 0;

static void	ft_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	ft_message(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2))
				ft_exit("SIGUSR2", 1);
		}
		else
			if (kill(pid, SIGUSR1))
				ft_exit("SIGUSR1", 1);
		usleep(SEND_DELAY);
		--i;
	}
}

static int	ft_pidcheck(const char *str)
{
	int		i;
	long	pid;

	if (!str || !(*str))
		return (-1);
	i = 0;
	pid = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		pid = pid * 10 + (str[i] - '0');
		if (pid > INT_MAX)
			return (-1);
		i++;
	}
	if (pid <= 0)
		return (-1);
	return ((int)pid);
}

static void	ft_send(pid_t pid, const char *msg)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
	while (msg[i])
	{
		if (re > 3)
			ft_exit("Resend", 1);
		g_ack = 0;
		ft_message(pid, (unsigned char)(msg[i]));
		if (!g_ack)
			usleep(BYTE_TIMEOUT);
		if (g_ack)
		{
			re = 0;
			++i;
		}
		else
			++re;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	re;

	re = 0;
	signal(SIGUSR1, ft_handler);
	if (argc != 3)
		ft_exit("Arguments", 1);
	pid = ft_pidcheck(argv[1]);
	if (pid < 0)
		ft_exit("PID", 1);
	ft_send(pid, argv[2]);
	while (re++ < 3)
	{
		g_ack = 0;
		ft_message(pid, '\0');
		usleep(BYTE_TIMEOUT);
		if (g_ack)
			return (0);
	}
	ft_exit("Null terminate", 1);
	return (0);
}
