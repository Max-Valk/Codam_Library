/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:54:51 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:58:54 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc (s1len + s2len + 1);
	if (!ptr)
		return (0);
	if (s1 != '\0')
		ft_memmove(ptr, s1, s1len);
	if (s2 != '\0')
		ft_memmove(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);
}
