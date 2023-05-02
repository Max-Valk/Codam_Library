/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:29:48 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:16:01 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*mod_dst;
	unsigned char	*mod_src;

	mod_dst = (unsigned char *)dst;
	mod_src = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (NULL);
	while (n > 0)
	{
		*mod_dst = *mod_src;
		mod_src++;
		mod_dst++;
		n--;
	}
	return (dst);
}
