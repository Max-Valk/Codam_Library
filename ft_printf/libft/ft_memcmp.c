/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:48:06 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:07 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mods1;
	unsigned char	*mods2;

	i = 0;
	mods1 = (unsigned char *)s1;
	mods2 = (unsigned char *)s2;
	while (i < n)
	{
		if (mods1[i] != mods2[i])
			return (mods1[i] - mods2[i]);
		i++;
	}
	return (0);
}
