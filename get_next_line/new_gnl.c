/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_gnl.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 17:39:49 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/10 16:58:51 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c != '\0')
		return ((char *)s);
	else
		return (0);
}

int	ft_nl_check(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
	{
		if (buffer[i] == '\n')
		
	}
	// printf("NL_LOC: |%i|\n", i);
	return (i);
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

void	ft_read_line(int fd, static char *saved_str)
{
	int		buffer_end;
	char	buffer[BUFFER_SIZE + 1];

	buffer_end = 1;
	while (buffer_end)
	{
		buffer_end = read(fd, buffer, BUFFER_SIZE);
		buffer[buffer_end] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return ;
}

char	*get_next_line(int fd)
{
	// static char	buffer[BUFFER_SIZE + 1];
	static char	*saved_str;
	char		*line;
	int			nl_pos;
	
	if (!saved_str)
		saved_str = ft_strdup("");
	savft_read_line(fd, buffer);
	// printf("saved_str_start: |%s|\n", saved_str);
	// saved_str = ft_strjoin(saved_str, buffer);
	nl_pos = ft_nl_check(buffer);
	while (nl_pos == BUFFER_SIZE)
	{
		// printf("buffer: |%s|\n", buffer);
		nl_pos = ft_nl_check(buffer);
		if (nl_pos < BUFFER_SIZE)
		{
			line = ft_strdup(saved_str);
			saved_str = ft_trim_saved_str(saved_str);
		}
		else
			ft_read_line(fd, buffer);
	}
	printf("saved_str: |%s|\n", saved_str);
	// free (saved_str);
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
	// system("leaks -q a.out");
	return (0);
}