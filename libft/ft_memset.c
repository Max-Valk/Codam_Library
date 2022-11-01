/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:53:23 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:24 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*modstr;

	modstr = (unsigned char *)str;
	while (len > 0)
	{
		*modstr = (unsigned char)c;
		modstr++;
		len--;
	}
	return (str);
}
