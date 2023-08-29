/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/24 15:24:37 by mvalk         #+#    #+#                 */
/*   Updated: 2023/08/29 16:08:16 by mvalk         ########   odam.nl         */
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

typedef struct s_philo	t_philo;

typedef	struct s_params
{
	size_t			max_eat;
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	struct	timeval start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_c;
	bool			is_dead;
	bool			eat_limit;
	pthread_t		*philos;
	t_philo			*philo_params;
	size_t			*eat_count;
}					t_params;

typedef	enum e_forks_held
{
	no_fork,
	left_fork,
	both_forks
}			t_forks_held;

typedef	enum	e_print_statement
{
	taken_fork,
	is_eating,
	is_sleeping,
	is_thinking,
	is_start,
	died
}	t_print;

typedef struct s_philo
{
	pthread_mutex_t	eat_c;
	struct	timeval last_eaten;
	size_t			philo_id;
	bool			eat_limit;
	t_params		*s_params;
}				t_philo;

//UTILS

size_t		gettime_dif(struct timeval start_time);
void		*ft_calloc(size_t count, size_t size);
int32_t		ft_atoi(const char *str);

//FUNCTIONS

int		philosophers(t_params *s_params);
void	ph_sleep(size_t naptime, t_philo *philo);
// void	ph_sleep(size_t naptime);
int		check_input_type(char **input);
int		init_philosophers(int ac, char **av, t_params *s_params);
void	init_forks(t_params *s_params);
void	init_params(t_params *s_params);

//ACTIONS

bool	ac_check_eatc(t_philo *philo);
bool	ac_check_stop(t_philo *philo);
bool	ac_check_death(t_philo *philo);
bool	ac_print(t_philo *philo, t_print print);
void	ac_eat(t_philo *philo);
void	ac_sleep(t_philo *philo);
int		ac_hungry(t_philo *philo);

#endif