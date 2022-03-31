/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:46:07 by marvin            #+#    #+#             */
/*   Updated: 2021/10/07 18:46:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_flag(char c, va_list av)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(av, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(av, char *)));
	else if (c == 'p')
		return (get_mem(va_arg(av, long long int)));
	else if (c == 'x' || c == 'X')
		return (write_hex(va_arg(av, unsigned int), c));
	else if (c == 0)
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(av, int)));
	else if (c == 'u')
		return (write_nbr(va_arg(av, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	av;

	i = 0;
	n = 0;
	va_start(av, str);
	while (str[i] != 0)
	{
		if (str[i] != '%')
			n += ft_putchar(str[i++]);
		else
		{
			if (str[i + 1] != 0)
			{
				n += ft_flag(str[i + 1], av);
				i += 2;
			}
			else
				i++;
		}
	}
	va_end(av);
	return (n);
}
