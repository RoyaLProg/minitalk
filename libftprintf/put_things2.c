/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 05:15:33 by ccambium          #+#    #+#             */
/*   Updated: 2021/12/16 05:15:33 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_mem(char *str)
{
	int	i;
	int	n;

	i = 2;
	n = 2;
	write(1, str, 2);
	while (str[i] != 0 && str[i] == '0')
		i++;
	while (str[i] != 0 && i < 18)
	{
		n += ft_putchar(str[i]);
		i++;
	}
	if (n == 2)
		n += ft_putchar('0');
	return (n);
}

int	write_hex(long long int nb, char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (nb < 0)
	{
		write(1, "-", 1);
		write_hex(-nb, c);
		return (1);
	}
	if (nb < 16)
	{
		write(1, &hex[nb], 1);
		return (1);
	}
	return (write_hex(nb / 16, c) + write_hex(nb % 16, c));
}
