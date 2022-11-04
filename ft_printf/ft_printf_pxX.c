/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_pxX.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 13:57:32 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/04 13:58:27 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_print_ptr(unsigned long ptr)
{
	write(1, "0x", 2);
	return (ft_printhex_ptr(ptr, 'x') + 2);
}

int	ft_printhex(unsigned int hex, const char hex_case)
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

int	ft_printhex_ptr(unsigned long hex, const char hex_case)
{
	int	print_len;

	print_len = 0;
	if (hex >= 16)
	{
		print_len += ft_printhex_ptr(hex / 16, hex_case);
		print_len += ft_printhex_ptr(hex % 16, hex_case);
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
