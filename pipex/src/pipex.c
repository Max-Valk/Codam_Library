/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 16:37:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/02 11:47:42 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	pipex(t_pipex *pipex_info)
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;

	if (pipe(pipex_info->pipe_fd) == -1)
		error_exit("pipe", errno);
	pid_1 = fork();
	if (pid_1 == -1)
		error_exit("fork", errno);
	if (pid_1 == 0)
		child_cmd_1(pipex_info);
	pid_2 = fork();
	if (pid_2 == -1)
		error_exit("fork", errno);
	if (pid_2 == 0)
		child_cmd_2(pipex_info);
	close(pipex_info->pipe_fd[0]);
	close(pipex_info->pipe_fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	close(pipex_info->fd_in);
	close(pipex_info->fd_out);
	return (EXIT_SUCCESS);
}

void	child_cmd_1(t_pipex *pipex_info)
{
	if (dup2(pipex_info->pipe_fd[1], STDOUT_FILENO) < 0)
		error_exit("dup2", errno);
	close(pipex_info->pipe_fd[0]);
	if (dup2(pipex_info->fd_in, STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	exec_command_paths(pipex_info, 2);
}

void	child_cmd_2(t_pipex *pipex_info)
{
	if (dup2(pipex_info->pipe_fd[0], STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	close(pipex_info->pipe_fd[1]);
	if (dup2(pipex_info->fd_out, STDOUT_FILENO) < 0)
		error_exit("dup2", errno);
	exec_command_paths(pipex_info, 3);
}

void	exec_command_paths(t_pipex *pipex_info, int cmdn)
{
	char	*cmd;
	char	**cmd_args;

	cmd_args = ft_split(pipex_info->argv[cmdn], ' ');
	cmd = cmd_path(pipex_info->paths, cmd_args[0], pipex_info->path_f);
	if (cmd != NULL)
		if (execve(cmd, cmd_args, pipex_info->envp) < 0)
			error_exit("execve", errno);
	ft_putstr_fd(pipex_info->argv[cmdn], 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}
