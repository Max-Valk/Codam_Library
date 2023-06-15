/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:37:32 by mvalk         #+#    #+#                 */
/*   Updated: 2023/06/07 15:11:46 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*s_pipex;

	if (argc == 5)
	{
		s_pipex = ft_calloc(sizeof(t_pipex), 1);
		if (!s_pipex)
			return (EXIT_FAILURE);
		s_pipex->argv = argv;
		s_pipex->envp = envp;
		s_pipex->path_f = 0;
		s_pipex->paths = parse_env(s_pipex->envp);
		if (!s_pipex->paths)
			s_pipex->path_f = -1;
		pipex(s_pipex);
		return (free_pipex(s_pipex), EXIT_SUCCESS);
	}
	else
		error_exit("invalid argument count", EINVAL);
}
