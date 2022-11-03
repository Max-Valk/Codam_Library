/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:32:15 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/03 16:31:27 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_conversions(va_list args, const char convert)
{
	int	arg_print_len;

	arg_print_len = 0;
	if (convert == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		arg_print_len++;
	}
	else if (convert == 's')
		arg_print_len += ft_printstr(va_arg(args, const char *));
	else if (convert == 'p')
		
	else if (convert == 'd')
		arg_print_len += ft_printnbr(va_arg(args, int));
	else if (convert == 'i')
		arg_print_len += ft_printnbr(va_arg(args, int));
	else if (convert == 'u')
		arg_print_len += ft_printunsigned(va_arg(args, unsigned int));
	else if (convert == 'x')
		arg_print_len += ft_printhex(va_arg(args, unsigned int), 0);
	else if (convert == 'X')
		arg_print_len += ft_printhex(va_arg(args, unsigned int), 1);
	else
	{
		ft_putchar_fd('%', 1);
		arg_print_len++;
	}
	return (arg_print_len);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int	i;
	int	print_len;

	i = 0;
	print_len = 0;
	va_start(args, format_str);
	while (format_str[i] != '\0')
	{
		if (format_str[i] == '%' && format_str[i + 1] != '\0')
		{
			i++;
			print_len += ft_conversions(args, format_str[i]);
			i++;
		}
		else
		{
			ft_putchar_fd(format_str[i], 1);
			i++;
			print_len++;
		}
	}
	va_end(args);
	return (print_len);
}

int main(void)
{
	int a = 37;
	int car = 97;
	
	ft_printf("Hello World, the answer is");
	return (0);
}