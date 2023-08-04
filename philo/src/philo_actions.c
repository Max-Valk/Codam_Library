/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:49:33 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/04 15:15:56 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	ac_sleep(t_philo *philo)
{
	size_t	sleep_time;

	sleep_time = philo->s_params->time_to_sleep;
	ph_sleep(sleep_time);
}

bool	ac_hungry(t_philo *philo)
{
	t_forks_held acquired;

	while (true)
	{
		if (pthread_mutex_lock(&philo->s_params->forks[philo->philo_id]) == 0)
			acquired = left_fork;
		{
			if (pthread_mutex_lock(&philo->s_params->forks[(philo->philo_id + 1)
				% philo->s_params->philo_count]) == 0)
			acquired = both_forks;
		}
		if (acquired == both_forks)
			return (true);
		else
		{
			pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
			ph_sleep(1);
		}
	}
}
