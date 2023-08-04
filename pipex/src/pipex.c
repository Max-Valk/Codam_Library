/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 16:37:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/07/11 15:24:58 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	pipex(t_pipex *s_pipex)
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;

	if (pipe(s_pipex->pipe_fd) == -1)
		error_exit("pipe", errno);
	pid_1 = fork();
	if (pid_1 == -1)
		error_exit("fork", errno);
	if (pid_1 == 0)
		child_cmd_1(s_pipex);
	pid_2 = fork();
	if (pid_2 == -1)
		error_exit("fork", errno);
	if (pid_2 == 0)
		child_cmd_2(s_pipex);
	close(s_pipex->pipe_fd[0]);
	close(s_pipex->pipe_fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, &status, 0);
	close(s_pipex->fd_in);
	close(s_pipex->fd_out);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}

void	child_cmd_1(t_pipex *s_pipex)
{
	s_pipex->fd_in = open(s_pipex->argv[1], O_RDONLY);
	if (access(s_pipex->argv[1], R_OK) != 0)
		error_exit(s_pipex->argv[1], 0);
	if (dup2(s_pipex->pipe_fd[1], STDOUT_FILENO) < 0)
		error_exit("dup2", errno);
	close(s_pipex->pipe_fd[0]);
	if (dup2(s_pipex->fd_in, STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	exec_command_paths(s_pipex, 2);
}

void	child_cmd_2(t_pipex *s_pipex)
{
	s_pipex->fd_out = open(s_pipex->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(s_pipex->argv[4], W_OK) != 0)
		error_exit(s_pipex->argv[4], errno);
	if (dup2(s_pipex->pipe_fd[0], STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	close(s_pipex->pipe_fd[1]);
	if (dup2(s_pipex->fd_out, STDOUT_FILENO) < 0)
		error_exit("dup2", errno);
	exec_command_paths(s_pipex, 3);
}

void	exec_command_paths(t_pipex *s_pipex, int cmdn)
{
	char	*cmd;
	char	**cmd_args;

	cmd_args = ft_split(s_pipex->argv[cmdn], ' ');
	cmd = cmd_path(s_pipex->paths, cmd_args[0], s_pipex->path_f);
	if (cmd != NULL)
		if (execve(cmd, cmd_args, s_pipex->envp) < 0)
			error_exit("execve", errno);
	ft_putstr_fd(s_pipex->argv[cmdn], 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}
