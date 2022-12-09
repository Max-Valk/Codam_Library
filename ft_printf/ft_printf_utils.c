/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_sidu.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:42:51 by mvalk         #+#    #+#                 */
/*   Updated: 2022/12/07 13:23:01 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_print_ptr(unsigned long ptr)
{
	write(1, "0x", 2);
	return (ft_printhex(ptr, 'x') + 2);
}

int	ft_printhex(unsigned long hex, const char hex_case)
{
	int	print_len;

	print_len = 0;
	if (hex >= 16)
	{
		print_len += ft_printhex(hex / 16, hex_case);
		print_len += ft_printhex(hex % 16, hex_case);
	}
	else
	{
		if (hex < 10)
			ft_putchar_fd((hex % 10) + '0', 1);
		else if (hex_case == 'X')
			ft_putchar_fd((hex % 16) + ('A' - 10), 1);
		else if (hex_case == 'x')
			ft_putchar_fd((hex % 16) + ('a' - 10), 1);
		print_len++;
	}
	return (print_len);
}

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
