/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:48:20 by eunji             #+#    #+#             */
/*   Updated: 2021/12/22 14:03:41 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_pickup(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->info->fork[philo->left_fork])) \
		|| !print_message(philo, PICKUP) \
		|| pthread_mutex_lock(&(philo->info->fork[philo->right_fork])) \
		|| !print_message(philo, PICKUP))
		return (false);
	return (true);
}

bool	philo_eat(t_philo *philo)
{
	if (!get_time(&(philo->curr_time)))
		return (false);
	philo->eat_count++;
	if (!print_message(philo, EATING) \
		|| !spend_time(0, philo->info->time_to_eat))
		return (false);
	return (true);
}

bool	philo_putdown(t_philo *philo)
{
	if (pthread_mutex_unlock(&(philo->info->fork[philo->left_fork])) \
		|| pthread_mutex_unlock(&(philo->info->fork[philo->right_fork])))
		return (false);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	if (!print_message(philo, SLEEPING) \
		|| !spend_time(0, philo->info->time_to_sleep))
		return (false);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (!print_message(philo, THINKING))
		return (false);
	return (true);
}
