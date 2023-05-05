/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:18:22 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/21 17:18:00 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	cpy_len;

	cpy_len = 0;
	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (ft_strlen(s) - start < len)
		cpy_len = ft_strlen(s) - start + 1;
	else
		cpy_len = len + 1;
	ptr = ft_calloc(sizeof(char *), cpy_len);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s[start], cpy_len);
	return (ptr);
}
