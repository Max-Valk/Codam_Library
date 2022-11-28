/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_siu.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:42:51 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/18 13:45:51 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	ft_printstr(const char *str)
{
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
}

int	ft_printnbr(int nbr)
{
	int	print_len;

	print_len = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		print_len++;
		if (nbr < -9)
			print_len += ft_printnbr(-(nbr / 10));
		ft_putchar_fd(-(nbr % 10) + '0', 1);
		print_len++;
	}
	else
	{
		if (nbr > 9)
			print_len += ft_printnbr(nbr / 10);
		ft_putchar_fd((nbr % 10) + '0', 1);
		print_len++;
	}
	return (print_len);
}

int	ft_printunsigned(unsigned int nbr)
{
	int	print_len;

	print_len = 0;
	if (nbr >= 0)
	{
		if (nbr > 9)
			print_len += ft_printunsigned(nbr / 10);
		ft_putchar_fd((nbr % 10) + '0', 1);
		print_len++;
	}
	return (print_len);
}
