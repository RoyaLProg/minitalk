/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:38:32 by ccambium          #+#    #+#             */
/*   Updated: 2022/05/09 17:03:54 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_s;

void	reset_print(void)
{
	ft_printf("%s", g_s);
	free(g_s);
	g_s = NULL;
}

void	add_char(char c)
{
	int		x;
	char	*new_s;

	if (c == 0)
	{
		reset_print();
		return ;
	}
	if (g_s == NULL)
	{
		g_s = malloc(sizeof(char) * 2);
		g_s[0] = c;
		g_s[1] = 0;
		return ;
	}
	x = ft_strlen(g_s);
	new_s = malloc(sizeof(char) * x + 2);
	if (new_s == NULL)
		return ;
	ft_strlcpy(new_s, g_s, x + 1);
	new_s[x] = c;
	new_s[x + 1] = 0;
	free(g_s);
	g_s = new_s;
}

void	signal_handler(int sig, siginfo_t *siginfo, void *something)
{
	static int	i = 0;
	static char	c = 0;

	(void) something;
	if (sig == SIGUSR1)
		c |= (1 << i);
	else if (sig == SIGUSR2)
		c &= ~(1 << i);
	i++;
	if (i == 8)
	{
		add_char(c);
		i = 0;
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

void	ft_end(int sigid)
{
	(void)sigid;
	if (g_s != NULL)
		free(g_s);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	g_s = NULL;
	pid = getpid();
	ft_printf("%u\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		;
}
