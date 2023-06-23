/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:12:30 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 15:19:42 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_str;
	size_t	s1_end;

	if (s1 == NULL || set == NULL)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
			s1++;
	s1_end = ft_strlen(s1);
	while (s1_end > 0 && ft_strchr(set, s1[s1_end]))
		s1_end--;
	ptr_str = ft_substr((char *)s1, 0, s1_end + 1);
	return (ptr_str);
}
