/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:05:46 by eunji             #+#    #+#             */
/*   Updated: 2021/12/22 13:41:32 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_all(t_info *info, t_philo **philo, int ret)
{
	int	i;

	i = 0;
	if (info->fork)
	{
		while (i < info->num_philo)
			pthread_mutex_destroy(&(info->fork[i++]));
		free(info->fork);
	}
	pthread_mutex_destroy(&(info->print));
	pthread_mutex_destroy(&(info->terminate));
	if (*philo)
		free(*philo);
	return (ret);
}
