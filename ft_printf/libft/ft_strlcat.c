/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 18:38:24 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:59 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	return_size;

	if (dstsize == 0 && dst == 0)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize > dstlen)
		return_size = srclen + dstlen;
	else
		return_size = srclen + dstsize;
	if (dstsize >= dstlen)
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	if (*src != '\0' && srclen + dstlen < dstsize + 1)
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (return_size);
}
