/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/07 18:18:42 by mvalk         ########   odam.nl         */
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
	// struct	timeval last_eaten;
	t_philo	*data;
	// size_t	m_seconds;

	data = (t_philo *)philo;
	// usleep(20 * data->philo_id);
	// m_seconds = gettime_dif(last_eaten);
	// ph_sleep(1 * data->philo_id);
	if ((data->philo_id + 1) % 2 == 0)
	{
		ac_print(data, is_thinking);
		ph_sleep(1);
	}
	while (true)
	{
		if (ac_hungry(data) == true)
		{
			ac_eat(data);
			ac_sleep(data);
		}
		ac_print(data, is_thinking);
		if (gettime_dif(data->last_eaten) > data->s_params->time_to_die)
			break ;
	}
	// printf("time elapsed in philo [%zu]: %zu m_secs\n", data->philo_id + 1, m_seconds);
	return (NULL);
}

bool	check_death(t_params *s_params)
{
	size_t	i;

	ph_sleep(100);
	while (true)
	{
		i = 0;
		while (i < s_params->philo_count)
		{
			printf("%zu deathtime in philo [%zu] for some reason\n", gettime_dif(s_params->philo_data[i].last_eaten), i);
			if (gettime_dif(s_params->philo_data[i].last_eaten) > s_params->time_to_die)
			{
				ac_print(&s_params->philo_data[i], died);
				s_params->printable = false;
				return (true);
			}
			i++;
		}
	}
	return (false);
}

int32_t	philosophers(t_params *s_params)
{
	pthread_mutex_t	forks[s_params->philo_count];
	pthread_t		philos[s_params->philo_count];
	t_philo			philo_params[s_params->philo_count];
	// size_t			eat_count[s_params->philo_count];
	
	struct timeval	start_time;
	int				status;
	size_t			i;

	i = 0;
	status = 0;
	gettimeofday(&start_time, NULL);
	// memset(eat_count, 0, s_params->philo_count * sizeof(size_t));
	memset(forks, 0, s_params->philo_count * sizeof(pthread_mutex_t));
	memset(philos, 0, s_params->philo_count * sizeof(pthread_t));
	memset(philo_params, 0, s_params->philo_count * sizeof(t_philo));
	s_params->philos = philos;
	s_params->forks = forks;
	s_params->philo_data = philo_params;
	while (i < s_params->philo_count)
	{
		status = pthread_mutex_init(&forks[i], NULL);
		if (status != 0){
			printf("fork L at %zu\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	gettimeofday(&s_params->start_time, NULL);
	while (i < s_params->philo_count)
	{
		philo_params[i].s_params = s_params;
		// philo_params[i].start_time = start_time;
		philo_params[i].philo_id = i;
		// printf("creating_philo %zu\n", i + 1);
		pthread_create(&philos[i], NULL, philosopher_thread, &philo_params[i]);
		i++;
	}
	check_death(s_params);
	i = 0;
	while (i < s_params->philo_count)
	{
		if (!pthread_join(philos[i], NULL))
			// printf("philo: %zu exited\n", i + 1);
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
	s_params->printable = true;
	// printf("%zu, %zu, %zu, %zu, %zu\n", philo_count, s_params->time_to_die, s_params->time_to_eat, s_params->time_to_sleep, s_params->max_eat);
	philosophers(s_params);
	return (0);
}
