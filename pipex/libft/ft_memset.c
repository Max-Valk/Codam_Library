/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:53:23 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:16:30 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*mod_str;

	mod_str = (unsigned char *)str;
	while (len > 0)
	{
		*mod_str = (unsigned char)c;
		mod_str++;
		len--;
	}
	return (str);
}
