/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:56:08 by mvalk         #+#    #+#                 */
/*   Updated: 2022/11/11 12:02:38 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

#ifndef BUFFER_SIZE

#define BUFFER_SIZE = 40;

#endif

// typedef struct s_list
// {
// 	char			*line;
// 	char			*buffer;
// 	int				nl_check;
// 	size_t			buffer_size;
// 	int				fd;
// 	struct s_list	*next;
// }					gnl_list;

int		ft_strlen(char const *line);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_nl_check(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif
