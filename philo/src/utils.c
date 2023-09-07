/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/27 17:16:18 by mvalk         #+#    #+#                 */
/*   Updated: 2023/09/07 18:00:00 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	gettime_dif(struct timeval start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
		- (start_time.tv_sec * 1000 + start_time.tv_usec / 1000));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}

void	ph_sleep(size_t naptime, t_philo *philo)
{
	struct timeval	start_time;
	size_t			m_seconds;

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
		}
	}
}

bool	check_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->s_data->eat_c);
	if (philo->eat_limit == true && philo->s_data->eat_count[philo->philo_id]
		>= philo->s_data->max_eat)
	{
		pthread_mutex_unlock(&philo->s_data->eat_c);
		return (true);
	}
	if (gettime_dif(philo->last_eaten) > philo->s_data->time_to_die)
	{
		pthread_mutex_lock(&philo->s_data->death_c);
		philo->s_data->is_dead = true;
		ac_print(philo, DIED);
		pthread_mutex_unlock(&philo->s_data->death_c);
		pthread_mutex_unlock(&philo->s_data->eat_c);
		return (true);
	}
	pthread_mutex_unlock(&philo->s_data->eat_c);
	return (false);
}
