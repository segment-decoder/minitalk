/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:25:39 by gyun              #+#    #+#             */
/*   Updated: 2026/07/29 16:45:44 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



int	main(void)
{
	ft_printf("Server is now running.\nPID: %d\n", getpid());
	while (1)
	{
		if (bitcount == 0)
			pause();
		else if (usleep(TIMEOUT) == 0)
			reset_buffer(s);
	}
	return (0);
}
