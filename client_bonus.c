/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:56:05 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 04:40:19 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_ack = 0;

static void	ft_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	ft_send_bit(pid_t pid, int i, unsigned char c)
{
	if ((c >> i) & 1)
	{
		if (kill(pid, SIGUSR2))
			ft_exit("SIGUSR2", CLIENT_SEND);
	}
	else
		if (kill(pid, SIGUSR1))
			ft_exit("SIGUSR1", CLIENT_SEND);
}

static void	ft_message(pid_t pid, unsigned char c)
{
	int	i;
	int	re;

	i = 7;
	re = 0;
	while (i >= 0)
	{
		if (re > 3)
			ft_exit("Resend", CLIENT_SEND);
		g_ack = 0;
		ft_send_bit(pid, i, c);
		if (!g_ack)
			usleep(BIT_TIMEOUT);
		if (g_ack)
		{
			re = 0;
			--i;
		}
		else
			++re;
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

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, ft_handler);
	if (argc != 3)
		ft_exit("Arguments", CLIENT_SEND);
	pid = ft_pidcheck(argv[1]);
	if (pid < 0 || kill(pid, 0) == -1)
		ft_exit("PID", CLIENT_SEND);
	while (argv[2][i])
		ft_message(pid, (unsigned char)(argv[2][i++]));
	ft_message(pid, '\0');
	return (0);
}
