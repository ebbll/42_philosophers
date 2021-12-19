/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:05:46 by eunji             #+#    #+#             */
/*   Updated: 2021/12/18 16:35:59 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	err_clear_info(t_info *info)
{
	int	i;

	i = 0;
	if (info->fork)
	{
		while (i < info->num_philo)
		{
			pthread_mutex_destroy(&(info->fork[i]));
			i++;
		}
		free(info->fork);
	}
	pthread_mutex_destroy(&info->print);
	free(info);
	return (false);
}

bool	err_clear_all(t_info *info, t_philo *philo)
{
	err_clear_info(info);
	free(philo);
	return (false);
}

bool	clear_all(t_info *info, t_philo *philo)
{
	err_clear_all(info, philo);
	return (true);
}
