/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:40:35 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:18:26 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *source, size_t dstsize)
{
	size_t	pos;
	size_t	src_len;

	src_len = ft_strlen(source);
	pos = 0;
	if (dstsize == 0)
		return (src_len);
	while (pos < dstsize - 1 && source[pos] != '\0')
	{
		dst[pos] = source[pos];
		pos++;
	}
	if (pos < dstsize)
		dst[pos] = '\0';
	return (src_len);
}
