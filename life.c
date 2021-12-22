/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:22:27 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/22 14:12:47 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	if (philo->index % 2)
		if (!spend_time(0, 10))
			pthread_mutex_unlock(&(philo->info->terminate));
	if (!get_time(&(philo->curr_time)))
		pthread_mutex_unlock(&(philo->info->terminate));
	while (true)
	{
		if (!philo_pickup(philo) || !philo_eat(philo) \
			|| !philo_putdown(philo) || !philo_sleep(philo) \
			|| !philo_think(philo))
			break ;
	}
	pthread_mutex_unlock(&(philo->info->terminate));
	return (NULL);
}
