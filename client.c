/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:25:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/09 17:04:33 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	g_lock;

void	send(int pid, char msg)
{
	int		i;
	char	c;

	i = 0;
	while (i < 8)
	{
		g_lock = 1;
		c = (msg >> i) & 1;
		if (c == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_lock)
			pause();
	}
}

void	arecup(int sig)
{
	(void)sig;
	g_lock = 0;
}

int	main(int ac, char **av)
{
	int					pid;
	size_t				i;

	if (ac != 3)
		return (0);
	g_lock = 0;
	signal(SIGUSR1, &arecup);
	pid = ft_atoi(av[1]);
	if (pid <= 1)
		return (write(1, "Error: invalid pid\n", 20));
	while (av[2][i])
	{
		send(pid, av[2][i]);
		i++;
	}
	send(pid, 0);
	return (EXIT_SUCCESS);
}
