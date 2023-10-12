/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 13:58:57 by mvalk         #+#    #+#                 */
/*   Updated: 2023/10/12 15:00:47 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->s_data->start_signal);
		pthread_mutex_lock(&philo->s_data->eat_c);
	gettimeofday(&philo->last_eaten, NULL);
	pthread_mutex_unlock(&philo->s_data->eat_c);
	pthread_mutex_unlock(&philo->s_data->start_signal);
	if ((philo->philo_id + 1) % 2 != 0)
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
	pthread_mutex_lock(&s_data->start_signal);
	while (i < s_data->philo_count)
	{
		s_data->ph_par[i].s_data = s_data;
		if (s_data->eat_limit == true)
			s_data->ph_par[i].eat_limit = true;
		s_data->ph_par[i].philo_id = i;
		if (pthread_create(&s_data->philos[i], NULL, ph_thread, &s_data->ph_par[i]) < 0)
			return (free(s_data->eat_count), free(s_data->forks),
				free(s_data->philos), free(s_data->ph_par), 1);
		i++;
	}
	if (i != s_data->philo_count)
	{
		pthread_mutex_lock(&s_data->death_c);
		s_data->is_dead = true;
		pthread_mutex_unlock(&s_data->death_c);
	}
	gettimeofday(&s_data->start_time, NULL);
	pthread_mutex_unlock(&s_data->start_signal);
	check_death(s_data);
	i = 0;
	while (i < s_data->philo_count)
	{
		pthread_join(s_data->philos[i], NULL);
		i++;
	}
	return (free(s_data->eat_count), free(s_data->forks),
		free(s_data->philos), free(s_data->ph_par), 0);
}
