/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:23:32 by mvalk         #+#    #+#                 */
/*   Updated: 2022/10/31 17:59:17 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*f_string;
	unsigned int	index;

	index = 0;
	f_string = (char *)malloc(ft_strlen(s) + 1);
	if (!f_string)
		return (0);
	while (s[index] != '\0')
	{
		f_string[index] = f(index, s[index]);
		index++;
	}
	f_string[index] = '\0';
	return (f_string);
}
