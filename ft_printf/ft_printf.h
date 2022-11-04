/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:43:33 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/04 14:28:13 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printstr(const char *str);
int	ft_printnbr(int nbr);
int	ft_printunsigned(unsigned int nbr);
int	ft_printhex(unsigned int hex, const char hex_case);
int	ft_print_ptr(unsigned long ptr);
int	ft_printf(const char *format_str, ...);
int	ft_printhex_ptr(unsigned long hex, const char hex_case);

#endif