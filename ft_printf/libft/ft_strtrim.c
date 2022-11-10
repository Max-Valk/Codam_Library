/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:12:30 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/28 16:27:51 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrstr;
	size_t	s1end;

	if (s1 == NULL || set == NULL)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
			s1++;
	s1end = ft_strlen(s1);
	while (s1end > 0 && ft_strchr(set, s1[s1end]))
		s1end--;
	ptrstr = ft_substr((char *)s1, 0, s1end + 1);
	return (ptrstr);
}
