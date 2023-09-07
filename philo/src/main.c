/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:24:09 by mvalk         #+#    #+#                 */
/*   Updated: 2023/09/07 17:50:36 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lk(void)
{
	system("leaks -q philo");
}

int	main(int ac, char **av)
{
	t_params	s_data;

	if (ac == 5 || ac == 6)
	{
		if (check_input_type(av))
		{
			printf("Error, invalid argument\n");
			return (EINVAL);
		}
		if (init_philosophers(ac, av, &s_data))
			return (errno);
		if (init_params(&s_data) == -1)
			return (ENOMEM);
		philosophers(&s_data);
	}
	else
		printf("Error, invalid argument count\n");
	return (0);
}
