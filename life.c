/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:22:27 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/20 21:31:05 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_life(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	// 짝수 필로소퍼는 대기
	if (!get_time(philo->curr_time))
		pthread_mutex_unlock(&(philo->info->terminate));
	while (true)
	{
		if (!philo_pickup(philo) || !philo_eat(philo) \
		|| !philo_putdown(philo) || !philo_sleep(philo) \
		|| !philo_think(philo))
			break;
	}
	pthread_mutex_unlock(&(philo->info->terminate));
	return (true);
}