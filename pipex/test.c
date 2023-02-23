/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 13:28:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/02/22 16:46:18 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	id;

	if (pipe(fd) == -1)
		return (printf("Error\n"));
	id = fork();
	if (id == 0)
	{
		close (fd[0]);
		int x;
		printf("insert number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close (fd[0]);
		printf("got from child process: %d\n", y);
	}
	return (0);
}