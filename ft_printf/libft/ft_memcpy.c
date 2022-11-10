/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:29:48 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:12 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*moddst;
	unsigned char	*modsrc;

	moddst = (unsigned char *)dst;
	modsrc = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (NULL);
	while (n > 0)
	{
		*moddst = *modsrc;
		modsrc++;
		moddst++;
		n--;
	}
	return (dst);
}
