/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:32:15 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/13 14:48:38 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversions(va_list args, const char convert)
{
	if (convert == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (convert == 's')
		return (ft_printstr(va_arg(args, const char *)));
	else if (convert == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (convert == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (convert == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (convert == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	else if (convert == 'x' || convert == 'X')
		return (ft_printhex(va_arg(args, unsigned int), convert));
	else
	{
		ft_putchar_fd(convert, 1);
		return (1);
	}
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, format_str);
	while (format_str[i] != '\0')
	{
		if (format_str[i] == '%' && format_str[i + 1])
		{
			print_len += ft_conversions(args, format_str[i + 1]);
			i += 2;
		}
		else if (format_str[i] == '%' && format_str[i + 1] == '\0')
			i++;
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
