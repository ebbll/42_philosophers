/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:56:06 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/20 21:53:39 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
*/

bool	print_state(t_philo *philo, t_state state)
{
	long long	curr;

	if (!get_time(&curr))
		return (false);
	if (state == PICKUP)
		printf("%lld %d has taken a fork\n", curr, philo->index + 1);
	else if (state == EATING)
		printf("%lld %d is eating\n", curr, philo->index);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping\n", curr, philo->index);
	else if (state == THINKING)
		printf("%lld %d is thinkng\n", curr, philo->index);
	else if (state == DEAD)
		printf("%lld %d died\n", curr, philo->index);
	else if (state == FULFILL)
		printf("%lld all philosopher has eaten\n");
	return (true);
}

bool	print_message(t_philo *philo, t_state state)
{
	long long	curr;

	if (pthread_mutex_lock(&(philo->info->print)))
		return (false);
	if (!get_time(&curr))
		return (false);
	if (!print_state(philo, state))
		return (false);
	if (state == EATING)
	{
		if (philo->info->num_must_eat)
		{	
			if (philo->eat_count == philo->info->num_must_eat)
				philo->info->fulfill++;
			if (philo->info->fulfill == philo->info->num_philo)
			{
				if (!print_state(philo, FULFILL))
					return (false);
				return (false);
			}
		}
	}
	if (pthread_mutex_unlock(&(philo->info->print)))
		return (false);
	return (true);
}
