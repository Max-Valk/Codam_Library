/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 13:49:33 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/31 16:40:20 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ac_check_eatc(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_params->eat_c);
	if (philo->eat_limit == true && philo->s_params->eat_count[philo->philo_id]
		>= philo->s_params->max_eat)
	{
		pthread_mutex_unlock(&philo->s_params->eat_c);
		return (true);
	}
	pthread_mutex_unlock(&philo->s_params->eat_c);
	return (false);
}

bool	ac_check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_params->eat_c);
	if (philo->eat_limit == true && philo->s_params->eat_count[philo->philo_id]
		>= philo->s_params->max_eat)
	{
		pthread_mutex_unlock(&philo->s_params->eat_c);
		return (true);
	}
	if (gettime_dif(philo->last_eaten) > philo->s_params->time_to_die)
	{
		pthread_mutex_unlock(&philo->s_params->eat_c);
		pthread_mutex_lock(&philo->s_params->death_c);
		philo->s_params->is_dead = true;
		// usleep(200);
		ph_sleep(1, NULL);
		ac_print(philo, died);
		pthread_mutex_unlock(&philo->s_params->death_c);
		return (true);
	}
	pthread_mutex_unlock(&philo->s_params->eat_c);
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

bool	ac_print(t_philo *philo, t_print print)
{
	if (print == died)
	{
		printf("%zu %zu died\n", gettime_dif(philo->s_params->start_time),
			philo->philo_id);
		return (true);
	}
	if (ac_check_death(philo) == true)
	{
		return (false);
	}
	pthread_mutex_lock(&philo->s_params->print_c);
	if (print == is_eating)
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
	// fflush(stdout);
	// usleep(100);
	pthread_mutex_unlock(&philo->s_params->print_c);
	return (true);
}

void	ac_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_params->eat_c);
	gettimeofday(&philo->last_eaten, NULL);
	philo->s_params->eat_count[philo->philo_id]++;
	pthread_mutex_unlock(&philo->s_params->eat_c);
	if (ac_print(philo, is_eating) == false)
	{
		pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
		pthread_mutex_unlock(&philo->s_params->forks[(philo->philo_id + 1)
			% philo->s_params->philo_count]);
		return ;
	}
	ph_sleep(philo->s_params->time_to_eat, philo);
	pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
	pthread_mutex_unlock(&philo->s_params->forks[(philo->philo_id + 1)
		% philo->s_params->philo_count]);
}

void	ac_sleep(t_philo *philo)
{
	size_t	sleep_time;

	sleep_time = philo->s_params->time_to_sleep;
	if (ac_print(philo, is_sleeping) == false)
		return ;
	ph_sleep(sleep_time, philo);
}

int	ac_hungry(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_params->forks[philo->philo_id]);
	if (ac_print(philo, taken_fork) == false)
	{
		pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
		return (false);
	}
	pthread_mutex_lock(&philo->s_params->forks[(philo->philo_id + 1)
		% philo->s_params->philo_count]);
		ac_print(philo, taken_fork);
	return (true);
}

// int	ac_hungry(t_philo *philo)
// {
// 	t_forks_held acquired;

// 	while (true)
// 	{
// 		acquired = no_fork;
// 		if (pthread_mutex_lock(&philo->s_params->forks[philo->philo_id]) == 0)
// 		{
// 			acquired = left_fork;
// 			if (ac_print(philo, taken_fork) == false)
// 			{
// 				pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
// 				return (0);
// 			}
// 			if (pthread_mutex_lock(&philo->s_params->forks[(philo->philo_id + 1)
// 				% philo->s_params->philo_count]) == 0)
// 			{
// 				acquired = both_forks;
// 				ac_print(philo, taken_fork);
// 				return (true);
// 			}
// 			else
// 				pthread_mutex_unlock(&philo->s_params->forks[philo->philo_id]);
// 		}
// 		ph_sleep(1, philo);
// 	}
// }

// i = 0;
// lock()
// i++;
// local = i;
// if (local == 1) {
// unlock();
// ...
// }
// else {
// unlock();
// }