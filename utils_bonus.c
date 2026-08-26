/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyun <gyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:14:50 by gyun              #+#    #+#             */
/*   Updated: 2026/08/27 01:03:56 by gyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit(char *str, int app)
{
	if (app == 1)
		ft_printf("%s error.\nTo send message, type: [PID] [message]", str);
	if (app == 2)
		ft_printf("%s error.\n System will shut down.", str);
	exit(1);
}
