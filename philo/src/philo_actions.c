/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:49:33 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/15 16:21:15 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ac_check_d(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_c);
	if (gettime_dif(philo->last_eaten) > philo->s_params->time_to_die)
	{
		pthread_mutex_lock(&philo->s_params->death_c);
		philo->s_params->is_dead = true;
		ac_print(philo, died);
		pthread_mutex_unlock(&philo->s_params->death_c);
		pthread_mutex_unlock(&philo->eat_c);
		return (true);
	}
	pthread_mutex_unlock(&philo->eat_c);
	return (false);
}

bool	ac_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_params->death_c);
	if (philo->s_params->is_dead == true)
	{
		pthread_mutex_unlock(&philo->s_params->death_c);
		return (true);
	}
	pthread_mutex_unlock(&philo->s_params->death_c);
	return (false);
}

void	ac_print(t_philo *philo, t_print print)
{
	if (print == died)
		printf("%zu %zu died\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
	else if (print == is_eating)
		printf("%zu %zu is eating\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
	else if (print == taken_fork)
		printf("%zu %zu has taken a fork\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
	else if (print == is_sleeping)
		printf("%zu %zu is sleeping\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
	else if (print == is_thinking)
		printf("%zu %zu is thinking\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
}

void	ac_eat(t_philo *philo)
{
	if (ac_check_death(philo) == true)
		return ;
	ac_print(philo, is_eating);
	philo->s_params->eat_count[philo->philo_id]++;
	gettimeofday(&philo->last_eaten, NULL);
	ph_sleep(philo->s_params->time_to_eat, philo);
	pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
	pthread_mutex_unlock(&philo->s_params->forks[(philo->philo_id + 1)
		% philo->s_params->philo_count]);
}

void	ac_sleep(t_philo *philo)
{
	size_t	sleep_time;

	sleep_time = philo->s_params->time_to_sleep;
	if (ac_check_death(philo) == true)
		return ;
	ac_print(philo, is_sleeping);
	ph_sleep(sleep_time, philo);
}

int	ac_hungry(t_philo *philo)
{
	t_forks_held acquired;

	while (true)
	{
		acquired = no_fork;
		if (ac_check_d(philo) == true)
		{
			ac_print(philo, died);
			return (false);
		}
		if (pthread_mutex_lock(&philo->s_params->forks[philo->philo_id]) == 0)
		{
			acquired = left_fork;
			if (ac_check_death(philo) == true)
				return (false);
			ac_print(philo, taken_fork);
			if (pthread_mutex_lock(&philo->s_params->forks[(philo->philo_id + 1)
				% philo->s_params->philo_count]) == 0)
			{
				acquired = both_forks;
				if (ac_check_death(philo) == true)
					return (false);
				ac_print(philo, taken_fork);
				return (true);
			}
			else
				pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
		}
		ph_sleep(1, philo);
	}
}
