/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 16:45:56 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/15 16:46:48 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_read_line(int fd, char *saved_str)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 1;
	if (!saved_str)
		saved_str = ft_strdup("");
	while (read_bytes && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (saved_str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
	}
	if (!saved_str[0])
	{
		free (saved_str);
		return (NULL);
	}
	return (saved_str);
}

char	*ft_trim_saved_str(char	*saved_str)
{
	int		saved_i;
	char	*trimmed_str;

	saved_i = 0;
	if (!saved_str)
		return (NULL);
	while (saved_str[saved_i])
	{
		if (saved_str[saved_i] == '\n')
		{
			trimmed_str = ft_strdup(&saved_str[saved_i] + 1);
			free (saved_str);
			if (!trimmed_str)
				return (NULL);
			return (trimmed_str);
		}
		saved_i++;
	}
	free (saved_str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*line;
	int			line_i;

	line_i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str = ft_read_line(fd, saved_str);
	if (!saved_str)
		return (NULL);
	line = ft_strdup(saved_str);
	saved_str = ft_trim_saved_str(saved_str);
	while (line[line_i])
	{
		if (line[line_i] == '\n')
			line[line_i + 1] = '\0';
		line_i++;
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);

// 	int i = 1;
// 	while (i <= 1)
// 	{
// 		char *line = get_next_line(fd);
// 		printf("line %i: %s", i, line);
// 		free (line);
// 		i++;
// 	}

// 	close(fd);
// 	// char *line = get_next_line();
// 	// printf("line:\t%s", line);
// 	// free (line);
// 	// free (list);
// 	system("leaks -q a.out");
// 	return (0);
// }
