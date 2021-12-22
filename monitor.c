/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:37:49 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/22 13:57:46 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg_philo)
{
	t_philo		*philo;
	long long	curr;

	philo = (t_philo *)arg_philo;
	if (!spend_time(0, philo->info->time_to_die - 10))
		pthread_mutex_unlock(&(philo->info->terminate));
	while (true)
	{
		if (!get_time(&curr))
			pthread_mutex_unlock(&(philo->info->terminate));
		if (curr - philo->curr_time >= (long long)philo->info->time_to_die)
		{
			print_message(philo, DEAD);
			pthread_mutex_unlock(&(philo->info->terminate));
			break ;
		}
	}
	return (NULL);
}
