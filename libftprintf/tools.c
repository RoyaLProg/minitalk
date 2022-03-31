/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:27:41 by ccambium          #+#    #+#             */
/*   Updated: 2021/12/17 10:27:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pow(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (nb * ft_pow(nb, power - 1));
	return (0);
}

int	get_mem(long long int x)
{
	char		buff[2 + sizeof(x) * 2];
	size_t		i;
	char		*hex;

	buff[0] = '0';
	buff[1] = 'x';
	i = 0;
	hex = "0123456789abcdef";
	while (i < sizeof(x) * 2)
	{
		buff[i + 2] = hex[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
		i++;
	}
	return (write_mem(buff));
}
