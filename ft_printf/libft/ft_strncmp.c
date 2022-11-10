/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 10:57:47 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:59:22 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || (s1 == 0 && s2 == 0))
		return (0);
	while (s1[i] != '\0' && s2[i] == s1[i])
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return ((unsigned char) s1[i] - (unsigned char)s2[i]);
}
