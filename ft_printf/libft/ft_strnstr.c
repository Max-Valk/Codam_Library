/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:00:16 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 18:01:03 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	inee;
	size_t	ihay;

	inee = 0;
	ihay = 0;
	if (needle[inee] == 0 || needle == haystack)
		return ((char *)haystack);
	while (ihay < len && haystack[ihay] != '\0')
	{
		inee = 0;
		while (haystack[ihay + inee] == needle[inee] && ihay + inee < len)
		{
			inee++;
			if (inee == ft_strlen(needle))
				return ((char *)haystack + ihay);
		}
		ihay++;
	}
	return (0);
}
