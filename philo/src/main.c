/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:24:09 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/30 18:49:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void lk(void)
{
	system("leaks -q philo");
}

int	main(int ac, char **av)
{
	t_params	*s_params;
	
	// atexit(&lk);
	s_params = malloc(sizeof(t_params));
	if (!s_params)
		exit(1);
	if (ac == 5 || ac == 6)
	{
		if (check_input_type(av))
		{
			printf("Error, invalid argument\n");
			return (EINVAL);
		}
		if (init_philosophers(ac, av, s_params))
			return (errno);
		init_params(s_params);
		philosophers(s_params);
	}
	else
		printf("Error, invalid argument count\n");
	return (0);
}
