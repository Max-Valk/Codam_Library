/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:43:21 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/21 15:09:46 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*ft_read_line(int fd, char *saved_str)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	read_bytes = 1;
	if (!saved_str)
		saved_str = ft_strdup("");
	if (!saved_str)
		return (NULL);
	buffer[0] = '\0';
	while (read_bytes && !ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free(saved_str));
		buffer[read_bytes] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
	}
	if (!saved_str[0])
		return (ft_free(saved_str));
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
			return (trimmed_str);
		}
		saved_i++;
	}
	free (saved_str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved_str[OPEN_MAX];
	char		*line;
	int			line_i;

	line_i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	saved_str[fd] = ft_read_line(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	line = ft_strdup(saved_str[fd]);
	if (!line)
		return (NULL);
	saved_str[fd] = ft_trim_saved_str(saved_str[fd]);
	while (line[line_i])
	{
		if (line[line_i] == '\n')
			line[line_i + 1] = '\0';
		line_i++;
	}
	return (line);
}
