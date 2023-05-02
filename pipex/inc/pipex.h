/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 14:26:05 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/02 11:59:07 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	char	**paths;
	int		path_f;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
}	t_pipex;

//test
int		pipex(t_pipex *var_struct);

void	child_cmd_1(t_pipex	*var_struct);
void	child_cmd_2(t_pipex	*var_struct);
void	exec_command_paths(t_pipex *pipex_info, int cmdn);
char	*cmd_path(char **envp, char *cmd, int path_f);
void	error_exit(char *function, int error_num);
char	**parse_env(char **envp);

#endif