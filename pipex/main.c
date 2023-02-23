/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:37:32 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/23 13:39:41 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
		pipex(argc, argv, envp);
	else
		perror("Invalid argument count");
}