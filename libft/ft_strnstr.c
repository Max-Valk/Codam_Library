/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:00:16 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:19:20 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_nee;
	size_t	i_hay;

	i_nee = 0;
	i_hay = 0;
	if (needle[i_nee] == 0 || needle == haystack)
		return ((char *)haystack);
	while (i_hay < len && haystack[i_hay] != '\0')
	{
		i_nee = 0;
		while (haystack[i_hay + i_nee] == needle[i_nee] && i_hay + i_nee < len)
		{
			i_nee++;
			if (i_nee == ft_strlen(needle))
				return ((char *)haystack + i_hay);
		}
		i_hay++;
	}
	return (0);
}
