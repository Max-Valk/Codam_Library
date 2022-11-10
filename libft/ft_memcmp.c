/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:48:06 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:15:34 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mod_s1;
	unsigned char	*mod_s2;

	i = 0;
	mod_s1 = (unsigned char *)s1;
	mod_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (mod_s1[i] != mod_s2[i])
			return (mod_s1[i] - mod_s2[i]);
		i++;
	}
	return (0);
}
