/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/29 16:10:13 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->philo_id + 1) % 2 == 0)
	{
		ac_print(philo, is_thinking);
		ph_sleep(1, philo);
	}
	else if (philo->philo_id == philo->s_params->philo_count - 1)
	{
		ac_print(philo, is_thinking);
		ph_sleep(philo->s_params->time_to_eat - 1, philo);
	}
	while (true)
	{
		if (ac_check_death(philo) || ac_check_eatc(philo))
			return (NULL);
		if (ac_hungry(philo) == true)
			ac_eat(philo);
		else
			return (NULL);
		ac_sleep(philo);
		if (ac_check_death(philo) == true)
			return (NULL);
		ac_print(philo, is_thinking);
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
			if (ac_check_stop(&s_params->philo_params[i]) == true)
				return (true);
			i++;
		}
		ph_sleep(1, NULL);
	}
	return (false);
}

int	philosophers(t_params *s_params)
{
	size_t			i;

	i = 0;
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
	return (0);
}

int	init_philosophers(int ac, char **av, t_params *s_params)
{
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
	return (0);
}
