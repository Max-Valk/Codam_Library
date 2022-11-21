/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:56:08 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/21 17:21:36 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
// # include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

void	*ft_free(char *str);
int		ft_strlen(char const *line);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_trim_saved_str(char	*saved_str);
char	*ft_read_line(int fd, char *saved_str);
char	*ft_trim_line(char *line);

char	*get_next_line(int fd);

#endif
