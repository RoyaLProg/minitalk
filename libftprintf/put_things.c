/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:24:04 by marvin            #+#    #+#             */
/*   Updated: 2021/10/07 21:24:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr(unsigned int v)
{
	if (v < 10)
	{
		v += 48;
		write(1, &v, 1);
		return (1);
	}
	return (write_nbr(v / 10) + write_nbr(v % 10));
}

int	ft_putnbr(int nb)
{
	unsigned int	v;
	int				x;

	x = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		v = -nb;
		x += 1;
	}
	else
		v = nb;
	return (x + write_nbr(v));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	unsigned int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
