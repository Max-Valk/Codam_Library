/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:24:09 by mvalk         #+#    #+#                 */
/*   Updated: 2023/10/12 13:40:45 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char **av)
{
	t_params	s_data;

	memset(&s_data, 0, sizeof(t_params));
	if (ac == 5 || ac == 6)
	{
		if (check_input_type(av))
		{
			printf("Error, invalid argument\n");
			return (EINVAL);
		}
		if (init_philosophers(ac, av, &s_data))
			return (EINVAL);
		if (init_params(&s_data) == -1)
			return (ENOMEM);
		philosophers(&s_data);
	}
	else
		printf("Error, invalid argument count\n");
	return (0);
}
