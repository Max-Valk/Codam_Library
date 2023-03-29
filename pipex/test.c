/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 13:28:24 by mvalk         #+#    #+#                 */
/*   Updated: 2023/03/24 13:42:47 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	argc = 0;
	
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}
	return (0);
}