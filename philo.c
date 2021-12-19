/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:05:54 by eunji             #+#    #+#             */
/*   Updated: 2021/12/18 17:20:45 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	setup(int argc, char **argv, t_info *info, t_philo **philo)
{
	int	i;

	memset(info, 0, sizeof(t_info));
	if (!parsing(argc, argv, info) || !get_time(&info->start_time))
		return (false);
	info->fork = (pthread_mutex_t *)malloc \
		(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->fork)
		return (false);
	i = 0;
	while (i < info->num_philo)
		if (pthread_mutex_init(&info->fork[i++], NULL))
			return (false);
	if (pthread_mutex_init(&info->print, NULL) \
		|| pthread_mutex_init(&info->terminate, NULL))
		return (false);
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_philo);
	if (!(*philo))
		return (false);
	memset(*philo, 0, sizeof(t_philo) * info->num_philo);
	return (true);
}

bool	start_eating(t_info *info, t_philo *philo)
{
	int	i;

	if (!info || !philo)
		return (false);
	if (pthread_mutex_lock(&(info->terminate)) || !get_time(&(info->start_time)))
		return (false);
	i = 0;
	while (i < info->num_philo)
	{
		philo[i].index = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % info->num_philo;
		philo[i].info = info;
		if (pthread_create() || pthread_detach())
			return (false);
		if (pthread_create() || pthread_detach())
			return (false);
	}
	if (pthread_mutex_lock(&(info->terminate)))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	philo = NULL;
	if (!setup(argc, argv, &info, &philo))
		return (에러처리함수);
	if (!start_eat(&info, philo))
		return (에러처리함수);
	return (0);
}

// 1. state function (5개)
// 2. spend_time
// 3. print
/*
	print mutex lock
	printf
	print mutex unlock

	//lock or unlock 실패 시 return bool
*/

// 4. monitoring
/*
처음에 바로 시작을 하면

*/

// 5. free with exit
