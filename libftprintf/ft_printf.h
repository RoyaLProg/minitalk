/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 03:58:01 by ccambium          #+#    #+#             */
/*   Updated: 2021/12/16 03:58:01 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		write_nbr(unsigned int v);
int		ft_putnbr(int nb);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		get_mem(long long int x);
int		write_mem(char *str);
int		write_hex(long long int nb, char c);
int		ft_atoi(const char *str);
int		ft_pow(int nb, int power);
int		ft_putdouble(double nb);
int		ft_printf(const char *str, ...);

#endif
