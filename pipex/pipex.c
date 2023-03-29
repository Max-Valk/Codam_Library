/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 16:37:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/29 18:23:10 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_pipex *pipex_info)
{
	pid_t	pid_1;
	pid_t	pid_2;

	if (pipe(pipex_info->pipe_fd) == -1)
		error_exit("pipe", errno);
	pid_1 = fork();
	if (pid_1 == -1)
		error_exit("fork", errno);
	if (pid_1 == 0 && access(pipex_info->argv[1], R_OK) == 0)
		child_cmd_1(pipex_info);
	else if (pid_1 == 0 && access(pipex_info->argv[1], R_OK) != 0)
		error_exit(pipex_info->argv[1], errno);
	pid_2 = fork();
	if (pid_2 == -1)
		error_exit("fork", errno);
	else if (pid_2 == 0 && access(pipex_info->argv[4], W_OK) != 0)
		error_exit(pipex_info->argv[4], errno);
	if (pid_2 == 0)
	{
		waitpid(pid_1, NULL, 0);
		child_cmd_2(pipex_info);
	}
	close(pipex_info->pipe_fd[0]);
	close(pipex_info->pipe_fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	close(pipex_info->fd_in);
	close(pipex_info->fd_out);
	return(EXIT_SUCCESS);
}

void	child_cmd_1(t_pipex *pipex_info)
{
	if (dup2(pipex_info->pipe_fd[1], STDOUT_FILENO) < 0)
		error_exit("dup2-1-1", errno);
	close(pipex_info->pipe_fd[0]);
	if (dup2(pipex_info->fd_in, STDIN_FILENO) < 0)
		error_exit("dup2-1-2", errno);
	exec_command_paths(pipex_info->argv, pipex_info->envp, 2);
}

void	child_cmd_2(t_pipex *pipex_info)
{
	if (dup2(pipex_info->pipe_fd[0], STDIN_FILENO) < 0)
		error_exit("dup2-2-1", errno);
	close(pipex_info->pipe_fd[1]);
	// if (pipex_info->fd_out == -1)
	// 	error_exit(pipex_info->argv[4], 2);
	if (dup2(pipex_info->fd_out, STDOUT_FILENO) < 0)
		error_exit("dup2-2-2", errno);
	exec_command_paths(pipex_info->argv, pipex_info->envp, 3);
}

void	exec_command_paths(char **argv, char **envp, int cmdn)
{
	char **cmd_paths;
	char **cmd_args;
	char *full_cmd;
	char *tmp;

	if (ft_strncmp(argv[cmdn], "awk", 3) == 0)
		cmd_args = parse_awk(argv[cmdn]);
	else
		cmd_args = ft_split(argv[cmdn], ' ');
	if (!cmd_args)
		error_exit("cmd_split", errno);
	if (argv[cmdn][0] == '/')
		if (execve(cmd_args[0], cmd_args, envp) < 0)
			error_exit("execve", errno);
	cmd_paths = parse_paths(envp);
	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		if (!tmp)
			error_exit("malloc", errno);
		full_cmd = ft_strjoin(tmp, cmd_args[0]);
		free (tmp);
		if (!full_cmd)
			error_exit("malloc", errno);
		if (access(full_cmd, F_OK) == 0)
		{
			if (access(full_cmd, X_OK) != 0)
				error_exit("access", errno);
			else if (execve(full_cmd, cmd_args, envp) < 0)
				error_exit("execve", errno);
		}
		free (full_cmd);
		cmd_paths++;
	}
	ft_putstr_fd(argv[cmdn], 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}

char	**parse_paths(char **envp)
{
	char	*path_line;
	char	**parsed_path;

	while (*envp != NULL && !ft_strnstr(*envp, "PATH=", ft_strlen(*envp)))
		envp++;
	if (!*envp)
		return (NULL);
	path_line = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	parsed_path = ft_split(path_line, ':');
	free (path_line);
	return (parsed_path);
}

char	**parse_awk(char *cmd)
{
	char	**cmd_args;
	size_t	start_apho;
	size_t	end_apho;

	start_apho = 0;
	while (cmd[start_apho] != 39 && cmd[start_apho] != 34)
		start_apho++;
	while (cmd[start_apho] == 39 || cmd[start_apho] == 34)
		start_apho++;
	end_apho = start_apho + 1;
	while (cmd[end_apho] != 39 && cmd[start_apho] != 34)
		end_apho++;
	cmd_args = ft_calloc(sizeof(char **), 3);
	if (!cmd_args)
		return (NULL);
	cmd_args[0] = "awk";
	cmd_args[1] = ft_substr(cmd, start_apho, end_apho - start_apho - 1);
	return (cmd_args);
}

void	error_exit(char *function, int error_num)
{
	perror(function);
	exit(error_num);
}
