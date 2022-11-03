/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_write_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:42:51 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/03 16:30:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

int	ft_printstr(const char *str)
{
	int	print_len;
	
	print_len = ft_strlen(str);
	if (print_len > 0)
		write(1, &str, print_len);
	return (print_len);
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
	int print_len;
	
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

int	ft_printhex(unsigned int hex, int hex_case)
{
	int	print_len;

	print_len = 0;
	if (hex >= 0)
	{
		if (hex > 15)
		{
			print_len += ft_printhex(hex / 16, hex_case);
			if (hex % 16 > 9 && hex_case == 1)
				ft_putchar_fd((hex % 16) + ('A' - 10), 1);
			else if (hex % 16 > 9 && hex_case == 0)
				ft_putchar_fd((hex % 16) + ('a' - 10), 1);
			else
				ft_putchar_fd((hex % 16) + '0', 1);
		}
		else
			ft_putchar_fd((hex % 10) + '0', 1);
		print_len++;
	}
	return (print_len);
}

// int	ft_printhex_lower(unsigned int hex)
// {
// 	int	print_len;

// 	print_len = 0;
// 	if (hex >= 0)
// 	{
// 		if (hex > 15)
// 		{
// 			print_len += ft_printhex_lower(hex / 16);
// 			if (hex % 16 > 9)
// 				ft_putchar_fd((hex % 16) + ('a' - 10), 1);
// 			else
// 				ft_putchar_fd((hex % 16) + '0', 1);
// 		}
// 		else
// 			ft_putchar_fd((hex % 10) + '0', 1);
// 		print_len++;
// 	}
// 	return (print_len);
// }

int main(void)
{
	unsigned int a = 2255;
	// int b = 0;

	printf("\nlength: %X", ft_printhex_lower(a));
	return (0);
}