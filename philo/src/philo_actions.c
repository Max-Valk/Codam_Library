/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:49:33 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/07 18:16:31 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ac_print(t_philo *philo, t_print print)
{
	if (philo->s_params->printable == false)
		return (false);
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
	return (true);
}

void	ac_eat(t_philo *philo)
{
	ac_print(philo, is_eating);
	gettimeofday(&philo->last_eaten, NULL);
	ph_sleep(philo->s_params->time_to_eat);
	pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
	pthread_mutex_unlock(&philo->s_params->forks[(philo->philo_id + 1)
		% philo->s_params->philo_count]);
}

void	ac_sleep(t_philo *philo)
{
	size_t	sleep_time;

	sleep_time = philo->s_params->time_to_sleep;
	ac_print(philo, is_sleeping);
	ph_sleep(sleep_time);
}

bool	ac_hungry(t_philo *philo)
{
	t_forks_held acquired;

	// if ((philo->philo_id + 1) % 2 == 0)
	// 	ph_sleep(1);
	while (true)
	{
		acquired = no_fork;
		// printf("\n");
		// usleep(1);
		if (pthread_mutex_lock(&philo->s_params->forks[philo->philo_id]) == 0)
		{
			acquired = left_fork;
			ac_print(philo, taken_fork);
			if (pthread_mutex_lock(&philo->s_params->forks[(philo->philo_id + 1)
				% philo->s_params->philo_count]) == 0)
			{
				acquired = both_forks;
				ac_print(philo, taken_fork);
				return (true);
			}
			else
				pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
		}
		ph_sleep(1);
	}
}
