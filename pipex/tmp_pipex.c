#include "pipex.h"

int	pipex(t_pipex *var_struct)
{
	pid_t	pid_1;
	pid_t	pid_2;
	
	// printf("hi there\n");
	if (pipe(var_struct->pipe_fd) == -1)
		error_exit("pipe", errno);
	pid_1 = fork();
	pid_2 = fork();
	if (pid_1 == -1)
		error_exit("fork", errno);
	if (pid_2 == -1)
		error_exit("fork", errno);
	if (pid_1 == 0)
		child_cmd_1(var_struct);
	if (pid_2 == 0)
	{
		waitpid(pid_1, NULL, 0);
		child_cmd_2(var_struct);	
	}
	// printf("hi there\n");
	close(var_struct->pipe_fd[0]);
	close(var_struct->pipe_fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	close(var_struct->fd_in);
	close(var_struct->fd_out);
	return(EXIT_SUCCESS);
}

void	child_cmd_1(t_pipex *var_struct)
{
	ft_printf("hi there1-1, error:%i\n", errno);
	if (dup2(var_struct->pipe_fd[1], STDOUT_FILENO) < 0)
	{
		ft_printf("hi there1-2, error:%i\n", errno);
		error_exit("dup2", errno);
	}
	ft_printf("hi there1dup\n");
	close(var_struct->pipe_fd[0]);
	if (dup2(var_struct->fd_in, STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	printf("hi there1dup2\n");
	exec_command_paths(var_struct->argv, var_struct->envp, 2);
	// return(EXIT_FAILURE);
}

void	child_cmd_2(t_pipex *var_struct)
{
	ft_printf("hi there2-1, error:%i\n", errno);
	if (dup2(var_struct->pipe_fd[0], STDIN_FILENO) < 0)
		error_exit("dup2", errno);
	ft_printf("hi there2-2, error:%i\n", errno);
	close(var_struct->pipe_fd[1]);
	if (dup2(var_struct->fd_out, STDOUT_FILENO) < 0)
		error_exit("dup2", errno);
	printf("hi there2\n");
	exec_command_paths(var_struct->argv, var_struct->envp, 3);
	// return (EXIT_FAILURE);
}

void	exec_command_paths(char **argv, char **envp, int cmdn)
{
	char **cmd_paths;
	char **cmd_args;
	char *full_cmd;
	char *tmp;

	cmd_args = ft_split(argv[cmdn], ' ');
	if (!cmd_args)
		error_exit("malloc", errno);
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
		if (access(full_cmd, X_OK) == 0)
			if (execve(full_cmd, cmd_args, envp) < 0)
				error_exit("execve", errno);
		free (full_cmd);
		cmd_paths++;
	}
	perror("nopath");
	// return (EXIT_SUCCESS);
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
	if (!parsed_path && !path_line)
		return (NULL);
	else
		return (free(path_line), NULL);
	return (parsed_path);
}

void	error_exit(char *function, int error_num)
{
	perror(function);
	// ft_printf("error_num:%i\n", error_num);
	// error_num = 0;
	exit(error_num);
}


#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "libft/libft.h"

typedef	struct t_pipex
{
	char 	**argv;
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

#endif