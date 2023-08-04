/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/04 15:16:51 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(size_t naptime)
{
	struct	timeval start_time;
	size_t	m_seconds;

	m_seconds = 0;
	gettimeofday(&start_time, NULL);
	while (m_seconds < naptime)
	{
		usleep(200);
		m_seconds = gettime_dif(start_time);
	}
}

void	*philosopher_thread(void *philo)
{
	struct	timeval last_eaten;
	t_philo	*data;
	size_t	m_seconds;

	data = (t_philo *)philo;
	gettimeofday(&last_eaten, NULL);
	ph_sleep(2000);
	m_seconds = gettime_dif(last_eaten);
	// usleep(1000);
	printf("time elapsed in philo [%zu]: %zu m_secs\n", data->philo_id + 1, m_seconds);
	return (NULL);
}

int32_t	philosophers(t_params *s_params)
{
	pthread_mutex_t	forks[s_params->philo_count];
	pthread_t		philos[s_params->philo_count];
	t_philo			philo_params[s_params->philo_count];
	// size_t			eat_count[s_params->philo_count];
	int				status;
	size_t			i;

	i = 0;
	status = 0;
	// memset(eat_count, 0, s_params->philo_count * sizeof(size_t));
	memset(forks, 0, s_params->philo_count * sizeof(pthread_mutex_t));
	memset(philos, 0, s_params->philo_count * sizeof(pthread_t));
	memset(philo_params, 0, s_params->philo_count * sizeof(t_philo));
	while (i < s_params->philo_count)
	{
		philo_params[i].s_params = s_params;
		philo_params[i].philo_id = i;
		// printf("creating_philo %zu\n", i + 1);
		pthread_create(&philos[i], NULL, philosopher_thread, &philo_params[i]);
		status = pthread_mutex_init(&forks[i], NULL);
		if (status != 0)
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < s_params->philo_count)
	{
		if (!pthread_join(philos[i], NULL))
			printf("philo: %zu exited\n", i + 1);
		i++;
	}
	return (0);
}

int32_t	init_philosophers(int ac, char **av)
{
	t_params	*s_params;

	s_params = ft_calloc(1, sizeof(t_params));
	if (s_params == NULL)
		return (1);
	if (ac == 6)
		s_params->max_eat = ft_atoi(av[--ac]);
	s_params->time_to_sleep = ft_atoi(av[--ac]);
	s_params->time_to_eat = ft_atoi(av[--ac]);
	s_params->time_to_die = ft_atoi(av[--ac]);
	s_params->philo_count = ft_atoi(av[--ac]);
	// printf("%zu, %zu, %zu, %zu, %zu\n", philo_count, s_params->time_to_die, s_params->time_to_eat, s_params->time_to_sleep, s_params->max_eat);
	philosophers(s_params);
	return (0);
}
