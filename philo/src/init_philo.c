/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/15 16:37:18 by mvalk         #+#    #+#                 */
/*   Updated: 2023/09/08 14:09:04 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_params *s_data)
{
	size_t	i;

	i = 0;
	while (i < s_data->philo_count)
	{
		pthread_mutex_init(&s_data->forks[i], NULL);
		i++;
	}
}

int	init_params(t_params *s_data)
{
	s_data->eat_count = ft_calloc(s_data->philo_count, sizeof(size_t));
	if (!s_data->eat_count)
		return (-1);
	s_data->forks = ft_calloc(s_data->philo_count, sizeof(pthread_mutex_t));
	if (!s_data->forks)
		return (free(s_data->eat_count), -1);
	s_data->philos = ft_calloc(s_data->philo_count, sizeof(pthread_t));
	if (!s_data->philos)
		return (free(s_data->eat_count), free(s_data->forks), -1);
	s_data->ph_par = ft_calloc(s_data->philo_count, sizeof(t_philo));
	if (!s_data->ph_par)
		return (free(s_data->eat_count), free(s_data->forks),
			free(s_data->philos), -1);
	pthread_mutex_init(&s_data->death_c, NULL);
	pthread_mutex_init(&s_data->death_c, NULL);
	pthread_mutex_init(&s_data->print_c, NULL);
	pthread_mutex_init(&s_data->eat_c, NULL);
	init_forks(s_data);
	return (0);
}
