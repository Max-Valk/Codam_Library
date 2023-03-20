/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:37:32 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/20 15:10:09 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex *var_struct;

	var_struct = ft_calloc(sizeof(t_pipex), 1);
	var_struct->fd_in = open(argv[1], O_RDONLY);
	var_struct->fd_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	var_struct->argv = argv;
	var_struct->envp = envp;
	if (argc == 5)
		return (pipex(var_struct));
	else
		return (perror("Invalid argument count"), 1);
	return (0);
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
