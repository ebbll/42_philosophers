/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:56:06 by eunlee            #+#    #+#             */
/*   Updated: 2021/12/18 17:06:30 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_message(t_philo *philo, t_state state)
{
	long long	curr;

	if (pthread_mutex_lock(&(philo->info->print)))
		return (false);
}