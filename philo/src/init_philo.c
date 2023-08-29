/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 16:37:18 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/29 15:54:24 by mvalk         ########   odam.nl         */
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
	s_params->eat_count = ft_calloc(s_params->philo_count, sizeof(size_t));
	s_params->forks = ft_calloc(s_params->philo_count, sizeof(pthread_mutex_t));
	s_params->philos = ft_calloc(s_params->philo_count, sizeof(pthread_t));
	s_params->philo_params = ft_calloc(s_params->philo_count, sizeof(t_philo));
	pthread_mutex_init(&s_params->death_c, NULL);
	init_forks(s_params);
}
