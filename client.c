/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:25:25 by ccambium          #+#    #+#             */
/*   Updated: 2022/03/31 02:31:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char msg)
{
	int		i;
	char	c;

	i = 0;
	while (i < 8)
	{
		c = (msg >> i) & 1;
		if (c == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 1)
		return (write(1, "Error: invalid pid\n", 21));
	while (av[2][i])
	{
		send(pid, av[2][i]);
		i++;
	}
	return (1);
}
