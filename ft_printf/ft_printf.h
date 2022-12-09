/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:43:33 by mvalk         #+#    #+#                 */
/*   Updated: 2022/12/06 17:55:32 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printstr(const char *str);
int	ft_printnbr(int nbr);
int	ft_printunsigned(unsigned int nbr);
int	ft_print_ptr(unsigned long ptr);
int	ft_printhex(unsigned long hex, const char hex_case);

int	ft_printf(const char *format_str, ...);

#endif