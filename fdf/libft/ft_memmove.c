/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:38:39 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:16:21 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*mod_dst;
	unsigned char	*mod_src;
	size_t			i;

	mod_dst = (unsigned char *)dst;
	mod_src = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	if (mod_dst > mod_src)
	{
		while (len > 0)
		{
			len--;
			mod_dst[len] = mod_src[len];
		}
	}
	while (i < len)
	{
		mod_dst[i] = mod_src[i];
		i++;
	}
	return (dst);
}
