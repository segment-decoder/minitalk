/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:56:05 by gyun              #+#    #+#             */
/*   Updated: 2026/08/26 22:48:08 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int sig)
{
	(void)sig;
}

static void	ft_message(pid_t pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
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

static void	ft_exit(void)
{
	ft_printf("Wrong arguments.\nTo send message, type: [PID] [message]");
	exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	bit;
	int	re;

	i = 0;
	bit = 0;
	re = 0;
	signal(SIGUSR1, ft_handler);
	if (argc != 3)
		ft_exit();
	pid = ft_pidcheck(argv[1]);
	if (pid < 0)
		ft_exit();
	while (argv[2][i])
	{
		while (bit++ < 8)
			ft_message(pid, (unsigned char)(argv[2][i++]));
		if (usleep(BYTE_TIMEOUT) == -1)
			i = i - 8;
		bit = 0;
	}
	ft_message(pid, '\0');
	return (0);
}
