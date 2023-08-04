/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:24:37 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/04 15:15:42 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/time.h>

//STRUCT DEFINES

typedef	struct s_params
{
	size_t			philo_count;
	size_t			max_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	size_t			*eat_count;
}					t_params;

typedef	enum e_forks_held
{
	left_fork,
	both_forks
}			t_forks_held;

typedef struct s_philo
{
	size_t		philo_id;
	t_params	*s_params;
}				t_philo;

//UTILS

size_t		gettime_dif(struct timeval start_time);
void		*ft_calloc(size_t count, size_t size);
int32_t		ft_atoi(const char *str);

//FUNCTIONS

void	ph_sleep(size_t naptime);
int		check_input_type(char **input);
int		init_philosophers(int ac, char **av);

//ACTIONS



#endif
