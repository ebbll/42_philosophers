/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:56:06 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/22 14:25:56 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_state(t_philo *philo, t_state state)
{
	long long	curr;

	if (!get_time(&curr))
		return (false);
	curr -= philo->info->start_time;
	if (state == PICKUP)
		printf("%lld %d has taken a fork\n", curr, philo->index + 1);
	else if (state == EATING)
		printf("%lld %d is eating\n", curr, philo->index + 1);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping\n", curr, philo->index + 1);
	else if (state == THINKING)
		printf("%lld %d is thinking\n", curr, philo->index + 1);
	else if (state == DEAD)
		printf("%lld %d died\n", curr, philo->index + 1);
	else if (state == FULFILL)
		printf("all philosopher has eaten\n");
	return (true);
}

bool	print_message(t_philo *philo, t_state state)
{
	if (pthread_mutex_lock(&(philo->info->print)))
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
				print_state(philo, FULFILL);
				return (false);
			}
		}
	}
	if (state == DEAD)
		return (false);
	if (pthread_mutex_unlock(&(philo->info->print)))
		return (false);
	return (true);
}
