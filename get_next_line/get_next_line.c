/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 16:45:56 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/09 17:40:57 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_read_line(int fd, char *buffer)
// {
// 	int	end;

// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
// 	end = read(fd, buffer, BUFFER_SIZE);
// 	if (end < 0)
// 		return (NULL);
// 	buffer[end] = '\0';
// 	return (buffer);
// }

// int	ft_nl_check(char *buffer)
// {
// 	int	i;

// 	i = 0;
// 	while (buffer[i] != '\0')
// 	{
// 		if (buffer[i] == '\n')
// 			return (i + 1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*get_next_line(int fd)
// {
// 	static char 	*static_str;
// 	char			*buffer;
// 	int				loc_nl;

// 	buffer = ft_read_line(fd, buffer);
// 	if (!buffer)
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	loc_nl = ft_nl_check(buffer) - 1;
// 	if (loc_nl < 0)
// 	{
// 		static_str = ft_strjoin(static_str, buffer);
// 	}
// 	else
// 		static_str = ft_strjoin(static_str, buffer);
// 	printf("loc_nl:%i\n\n", loc_nl);
// 	return (static_str);
// }

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);

	int i = 1;
	while (i <= 6)
	{
		char *line = get_next_line(fd);
		printf("line %i: %s\n ---------------- \n", i, line);
		free (line);
		i++;
	}
	// printf("read_line: %s", line);
	close(fd);
	// free (line);
	// free (list);
	// system("leaks -q a.out");
	return (0);
}
