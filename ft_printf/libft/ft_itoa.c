/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:31:52 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/01 14:17:15 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_character_counter(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*integer_string;
	int		index;
	int		neg;

	neg = 0;
	index = ft_character_counter(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	integer_string = (char *)malloc(index + 1);
	if (!integer_string)
		return (0);
	if (n < 0)
	{
		integer_string[0] = '-';
		n *= -1;
		neg = 1;
	}
	integer_string[index] = '\0';
	while (index-- > neg)
	{
		integer_string[index] = n % 10 + '0';
		n /= 10;
	}
	return (&integer_string[0]);
}
