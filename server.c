/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:38:32 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/31 03:15:22 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	c << 1;
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
	char	c;
	int		i;

	while (1)
	{
		c = 0;
		i = 0;
		while (i < 8)
		{
			c = c << 1;
			if (signal(SIGUSR1, signal_handler) == SIG_ERR)
				return (0);
			if (signal(SIGUSR2, signal_handler) == SIG_ERR)
				return (0);
			i++;
		}
	}
	return (c);
}

int	main(void)
{
	int		pid;
	char	c;

	c = 1;
	pid = getpid();
	ft_printf("%d\n", pid);
	while (server)
	{
		c = server();
		if (c == 0)
			break ;
	}
	return (1);
}
