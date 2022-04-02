/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:38:32 by ccambium          #+#    #+#             */
/*   Updated: 2022/04/02 06:15:02 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << i);
	else if (sig == SIGUSR2)
		c &= ~(1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	server(void)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (signal(SIGUSR1, signal_handler) == SIG_ERR)
				return (0);
			if (signal(SIGUSR2, signal_handler) == SIG_ERR)
				return (0);
			i++;
		}
	}
	return (1);
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	server();
	return (1);
}
