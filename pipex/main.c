/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:37:32 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/30 13:24:06 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex *pipex_info;

	if (argc == 5)
	{
		pipex_info = ft_calloc(sizeof(t_pipex), 1);
		if (!pipex_info)
			return(EXIT_FAILURE);
		pipex_info->fd_in = open(argv[1], O_RDONLY);
		pipex_info->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (access(argv[4], W_OK) != 0)
			error_exit(argv[4], errno);
		pipex_info->argv = argv;
		pipex_info->envp = envp;
		return (pipex(pipex_info));
	}
	else
		error_exit("invalid argument count", errno);
}


/**
 * main for testign parsing path

int	main(int argc, char	*argv[], char *envp[])
{
	char **parsed_path;
	argv = NULL;
	argc = 0;

	parsed_path = NULL;
	parsed_path = parse_paths(envp);
	while (*parsed_path != NULL)
	{
		printf("path=%s\n", *parsed_path);
		parsed_path++;
	}
	return (0);
}*/
