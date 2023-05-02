/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:37:32 by mvalk         #+#    #+#                 */
/*   Updated: 2023/05/02 11:44:12 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex_info;

	if (argc == 5)
	{
		pipex_info = ft_calloc(sizeof(t_pipex), 1);
		if (!pipex_info)
			return (EXIT_FAILURE);
		pipex_info->argv = argv;
		pipex_info->envp = envp;
		pipex_info->path_f = 0;
		pipex_info->paths = parse_env(pipex_info->envp);
		if (!pipex_info->paths)
			pipex_info->path_f = -1;
		pipex_info->fd_in = open(argv[1], O_RDONLY);
		if (access(pipex_info->argv[1], R_OK) != 0)
			error_exit(pipex_info->argv[1], errno);
		pipex_info->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (access(pipex_info->argv[4], W_OK) != 0)
			error_exit(pipex_info->argv[4], errno);
		pipex(pipex_info);
		return (free (pipex_info), 0);
	}
	else
		error_exit("invalid argument count", 1);
}
