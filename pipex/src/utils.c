/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 17:44:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/17 16:17:28 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_exit(char *function, int error_num)
{
	perror(function);
	exit(error_num);
}

char	**parse_env(char **envp)
{
	char	**split_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	split_path = ft_split(envp[i], ':');
	return (split_path);
}

char	*cmd_path(char **paths, char *cmd, int path_f)
{
	char	*full_cmd;
	char	*tmp;

	if (ft_strchr(cmd, '/') || path_f == -1)// leaks after this statement is triggerd and execve fails
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		full_cmd = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(full_cmd, F_OK) == 0)
			return (full_cmd);
		free (full_cmd);
		paths++;
	}
	return (NULL);
}
