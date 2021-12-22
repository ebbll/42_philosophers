/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:50:22 by eunji             #+#    #+#             */
/*   Updated: 2021/12/22 14:07:13 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_time(long long *curr)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (false);
	*curr = (long long)(time.tv_sec * 1000 + time.tv_usec / 1000);
	return (true);
}

bool	spend_time(long long start, long long timeunit)
{
	long long	curr;

	if (!start)
		if (!get_time(&start))
			return (false);
	while (true)
	{
		if (!get_time(&curr))
			return (false);
		if (curr - start >= timeunit)
			break ;
		if (usleep(10) == -1)
			return (false);
	}
	return (true);
}
