/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 14:26:05 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/30 13:21:52 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "libft/libft.h"
# include <string.h>

typedef struct t_pipex
{
	char	**argv;
	char	**envp;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
}	t_pipex;

//test
int		pipex(t_pipex *var_struct);
void	child_cmd_1(t_pipex	*var_struct);
void	child_cmd_2(t_pipex	*var_struct);
char	**parse_paths(char **envp);
void	exec_command_paths(char **argv, char **envp, int cmdn);
void	error_exit(char *function, int error_num);
char	**parse_awk(char *cmd);
char	*ft_line_merge(char *s1, const char *s2);

#endif