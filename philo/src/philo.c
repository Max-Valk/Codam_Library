/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/15 17:02:49 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_sleep(size_t naptime, t_philo *philo)
{
	struct	timeval start_time;
	size_t	m_seconds;

	m_seconds = 0;
	gettimeofday(&start_time, NULL);
	while (m_seconds < naptime)
	{
		usleep(200);
		m_seconds = gettime_dif(start_time);
		if (philo != NULL)
		{
			if (ac_check_death(philo) == true)
				return ;
			if (ac_check_d(philo) == true)
			{
				ac_print(philo, died);
				return ;
			}
		}	
	}
}

void	*philosopher_thread(void *philo)
{
	t_philo	*data;

	data = (t_philo *)philo;
	if ((data->philo_id + 1) % 2 == 0)
	{
		ac_print(data, is_thinking);
		ph_sleep(1, data);
	}
	if (data->s_params->philo_count % 2 != 0 && data->philo_id == data->s_params->philo_count - 1)
	{
		ac_print(data, is_thinking);
		ph_sleep(data->s_params->time_to_eat - 1, data);
		ac_check_d(data);
	}
	while (true)
	{
		if (ac_check_death(data) == true)
			return (NULL);
		if (ac_hungry(data) == true)
			ac_eat(data);
		else
			return (NULL);
		ac_sleep(data);
		if (ac_check_death(data) == true)
			return (NULL);
		ac_print(data, is_thinking);
		if (data->eat_limit == true && data->s_params->eat_count[data->philo_id]
				>= data->s_params->max_eat)
			return (NULL);
		if (ac_check_d(philo) == true)
		{
			ac_print(philo, died);
			break ;
		}
	}
	return (NULL);
}

bool	check_death(t_params *s_params)
{
	size_t	i;

	ph_sleep(s_params->time_to_die - 1, NULL);
	while (true)
	{
		i = 0;
		while (i < s_params->philo_count)
		{
			if (ac_check_d(&s_params->philo_params[i]) == true)
				return (true);
		}
		ph_sleep(1, NULL);
	}
	return (false);
}

int	philosophers(t_params *s_params)
{
	size_t			i;

	i = 0;
	// init_params(s_params);
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
	pthread_mutex_init(&s_params->death_c, NULL);
	init_forks(s_params);
	gettimeofday(&s_params->start_time, NULL);
	while (i < s_params->philo_count)
	{
		s_params->philo_params[i].s_params = s_params;
		if (s_params->eat_limit == true)
			s_params->philo_params[i].eat_limit = true;
		s_params->philo_params[i].last_eaten = s_params->start_time;
		s_params->philo_params[i].philo_id = i;
		pthread_create(&s_params->philos[i], NULL, philosopher_thread, &s_params->philo_params[i]);
		i++;
	}
	check_death(s_params);
	i = 0;
	while (i < s_params->philo_count)
	{
		pthread_join(s_params->philos[i], NULL);
		i++;
	}
	return (free(s_params), 0);
}

int	init_philosophers(int ac, char **av)
{
	t_params	*s_params;

	s_params = ft_calloc(1, sizeof(t_params));
	if (s_params == NULL)
		return (1);
	if (ac == 6)
	{
		s_params->max_eat = ft_atoi(av[--ac]);
		s_params->eat_limit = true;
	}
	s_params->time_to_sleep = ft_atoi(av[--ac]);
	s_params->time_to_eat = ft_atoi(av[--ac]);
	s_params->time_to_die = ft_atoi(av[--ac]);
	s_params->philo_count = ft_atoi(av[--ac]);
	s_params->is_dead = false;
	philosophers(s_params);
	return (0);
}
