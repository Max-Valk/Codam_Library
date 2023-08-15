/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 16:37:18 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/15 17:00:43 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_params *s_params)
{
	size_t	i;
	i = 0;
	while (i < s_params->philo_count)
	{
		pthread_mutex_init(&s_params->forks[i], NULL);
		i++;
	}
}

void	init_params(t_params *s_params)
{
	pthread_mutex_t	forks[s_params->philo_count];
	pthread_t		philos[s_params->philo_count];
	t_philo			philo_params[s_params->philo_count];
	size_t			eat_count[s_params->philo_count];

	memset(eat_count, 0, s_params->philo_count * sizeof(size_t));
	memset(forks, 0, s_params->philo_count * sizeof(pthread_mutex_t));
	memset(philos, 0, s_params->philo_count * sizeof(pthread_t));
	memset(philo_params, 0, s_params->philo_count * sizeof(t_philo));
	s_params->philos = philos;
	s_params->forks = forks;
	s_params->philo_params = philo_params;
	s_params->eat_count = eat_count;
}
