/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:43:21 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/22 16:45:00 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <fcntl.h>
#include <stddef.h>

static void	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

static char	*ft_line_merge(char *s1, const char *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc (s1len + s2len + 1);
	if (!ptr)
		return (ft_free(s1));
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		ptr[s1len + i] = s2[i];
	ptr[s1len + s2len] = '\0';
	free (s1);
	return (ptr);
}

/**reads from fd to buffer until \n or eof
concatenates 'saved_str' and 'buffer' until \n or eof
returns a pointer to the created string*/
static char	*ft_read_line(int fd, char *saved_str)
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
		saved_str = ft_line_merge(saved_str, buffer);
		if (!saved_str)
			return (NULL);
	}
	if (!saved_str[0])
		return (ft_free(saved_str));
	return (saved_str);
}

/**trims the input 'str'
returns a pointer to a copy of 'str' until the newline if saved = 0
returns a pointer to a copy of 'str' from newline to \0 if saved = 1*/
static char	*ft_trim_str(char	*str, int saved)
{
	int		saved_i;
	char	*trimmed_str;

	saved_i = 0;
	while (str[saved_i])
	{
		if (str[saved_i] == '\n')
		{
			if (saved == 1)
				trimmed_str = ft_strdup(&str[saved_i] + 1);
			else
			{
				str[saved_i + 1] = '\0';
				trimmed_str = ft_strdup(str);
			}
			free (str);
			return (trimmed_str);
		}
		saved_i++;
	}
	if (saved == 1)
		return (ft_free(str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*saved_str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	saved_str[fd] = ft_read_line(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	line = ft_strdup(saved_str[fd]);
	if (!line)
	{
		free(saved_str[fd]);
		saved_str[fd] = NULL;
		return (NULL);
	}
	saved_str[fd] = ft_trim_str(saved_str[fd], 1);
	line = ft_trim_str(line, 0);
	if (!line)
	{
		free(saved_str[fd]);
		saved_str[fd] = NULL;
		return (NULL);
	}
	return (line);
}
