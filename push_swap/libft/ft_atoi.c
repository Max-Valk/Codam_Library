/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 16:43:55 by mvalk         #+#    #+#                 */
/*   Updated: 2023/01/16 17:05:55 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int		neg;
	long	number;

	neg = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg--;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = 10 * number + (*str - 48);
		str++;
	}
	if (neg < 0)
		return (neg * number);
	return (number);
}
