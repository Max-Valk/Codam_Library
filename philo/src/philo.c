/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/10/09 15:12:31 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->philo_id + 1) % 2 == 0)
	{
		ac_print(philo, IS_THINKING);
		ph_sleep(philo->s_data->time_to_eat / 2, philo);
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
		if (ac_print(philo, IS_THINKING) == false)
			return (NULL);
	}
	return (NULL);
}

bool	check_death(t_params *s_data)
{
	size_t	i;

	ph_sleep(s_data->time_to_die / 2, NULL);
	while (true)
	{
		i = 0;
		while (i < s_data->philo_count)
		{
			if (check_stop(&s_data->ph_par[i]) == true)
				return (true);
			i++;
		}
		ph_sleep(1, NULL);
	}
	return (false);
}

int	philosophers(t_params *s_data)
{
	size_t			i;

	i = 0;
	gettimeofday(&s_data->start_time, NULL);
	while (i < s_data->philo_count)
	{
		s_data->ph_par[i].s_data = s_data;
		if (s_data->eat_limit == true)
			s_data->ph_par[i].eat_limit = true;
		s_data->ph_par[i].last_eaten = s_data->start_time;
		s_data->ph_par[i].philo_id = i;
		pthread_create(&s_data->philos[i], NULL, ph_thread, &s_data->ph_par[i]);
		i++;
	}
	check_death(s_data);
	i = 0;
	while (i < s_data->philo_count)
	{
		pthread_join(s_data->philos[i], NULL);
		i++;
	}
	return (0);
}

int	init_philosophers(int ac, char **av, t_params *s_data)
{
	if (ac == 6)
	{
		s_data->max_eat = ft_atoi(av[--ac]);
		s_data->eat_limit = true;
		if (s_data->max_eat < 1)
			return (-1);
	}
	s_data->time_to_sleep = ft_atoi(av[--ac]);
	s_data->time_to_eat = ft_atoi(av[--ac]);
	s_data->time_to_die = ft_atoi(av[--ac]);
	s_data->philo_count = ft_atoi(av[--ac]);
	if (s_data->time_to_sleep < 1 || s_data->time_to_die < 1)
		return (-1);
	if (s_data->max_eat > __INT_MAX__ || s_data->time_to_sleep > __INT_MAX__
		|| s_data->time_to_die > __INT_MAX__)
		return (-1);
	s_data->is_dead = false;
	return (0);
}
