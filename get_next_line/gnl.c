/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 11:52:53 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/11 12:56:18 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *saved_str)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*temp;
	int			read_bytes;

	read_bytes = 1;
	while (read_bytes)
	{
		if (ft_strchr(saved_str, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(saved_str, buffer);
		saved_str = temp;
		free (temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	printf("joined_str: |%s|\n", saved_str);
	return (temp);
}

char	*ft_trim_saved_str(char	*saved_str)
{
	size_t	i;

	i = 0;
	if (!saved_str)
		return (0);
	while (saved_str[i] && saved_str[i - 1] != '\n')
		i++;
	return (&saved_str[i]);
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*line;

	if (!saved_str)
		saved_str = ft_strdup("");
	printf("saved_str: |%s|\n", saved_str);
	// empty_line = ft_strchr(saved_str, '\n');
	// if (empty_line)
	// {
	// 	line = ft_strdup(saved_str);
	// 	return (line);
	// }
	saved_str = ft_read_line(fd, saved_str);
	line = ft_strdup(saved_str);
	// printf("line: |%s|\n", line);
	saved_str = ft_trim_saved_str(saved_str);
	return (line);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);

	int i = 1;
	while (i <= 6)
	{
		char *line = get_next_line(fd);
		printf("line %i: |%s|\n ---------------- \n", i, line);
		free (line);
		i++;
	}
	
	close(fd);
	// char *line = get_next_line();
	// printf("line:\t%s", line);
	// free (line);
	// free (list);
	system("leaks -q a.out");
	return (0);
}