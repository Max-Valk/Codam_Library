/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 18:43:33 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/03 16:30:55 by mvalk         ########   odam.nl         */
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
int	ft_printhex_lower(unsigned int hex);
int	ft_printhex(unsigned int hex, int hex_case);

#endif