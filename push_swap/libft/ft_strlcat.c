/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 18:38:24 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:18:14 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	return_size;

	if (dstsize == 0 && dst == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize > dst_len)
		return_size = src_len + dst_len;
	else
		return_size = src_len + dstsize;
	if (dstsize >= dst_len)
		ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	if (*src != '\0' && src_len + dst_len < dstsize + 1)
		ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (return_size);
}
