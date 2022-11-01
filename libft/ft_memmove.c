/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:38:39 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:17 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*moddst;
	unsigned char	*modsrc;
	size_t			i;

	moddst = (unsigned char *)dst;
	modsrc = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	if (moddst > modsrc)
	{
		while (len > 0)
		{
			len--;
			moddst[len] = modsrc[len];
		}
	}
	while (i < len)
	{
		moddst[i] = modsrc[i];
		i++;
	}
	return (dst);
}
