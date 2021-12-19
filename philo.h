/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:04:48 by eunji             #+#    #+#             */
/*   Updated: 2021/12/18 21:24:40 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				fulfill;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	terminate;
}	t_info;

typedef enum e_state
{
	THINKING,
	PICKUP,
	EATING,
	SLEEPING,
	FULFILL,
	DEAD
}	t_state;

typedef struct s_philo
{
	pthread_t	th_philo;
	pthread_t	th_monitor;
	int			index;
	int			left_fork;
	int			right_fork;
	int			eat_count;
	long long	curr_time;
	t_info		*info;
}	t_philo;

/* action.c */
bool	philo_pickup(t_philo *philo);
bool	philo_eat(t_philo *philo);
bool	philo_putdown(t_philo *philo);
bool	philo_sleep(t_philo *philo);
bool	philo_think(t_philo *philo);

/* time.c */
bool	get_time(long long *curr);
bool	spend_time(long long *start, long long *end);

/* free.c */
bool	err_clear_info(t_info *info);
bool	err_clear_all(t_info *info, t_philo *philo);
bool	clear_all(t_info *info, t_philo *philo);

/* parsing.c */
bool	ft_atoi(char *str, int *addr);
bool	parsing(int argc, char **argv, t_info *info);

/* philo.c */
bool	setup(int argc, char **argv, t_info *info, t_philo **philo);
bool	start_eating(t_info *info, t_philo *philo);
int		main(int argc, char **argv);

#endif