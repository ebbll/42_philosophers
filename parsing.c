/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:05:50 by eunji             #+#    #+#             */
/*   Updated: 2021/12/18 16:33:46 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_atoi(char *str, int *addr)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		ret = ret * 10 + *str - '0';
		str++;
	}
	if (ret == 0)
		return (false);
	*addr = ret;
	return (true);
}

bool	parsing(int argc, char **argv, t_info *info)
{
	if (argc < 5 || argc > 6)
		return (false);
	if (!ft_atoi(argv[1], &info->num_philo)
		|| !ft_atoi(argv[2], &info->time_to_die)
		|| !ft_atoi(argv[3], &info->time_to_eat)
		|| !ft_atoi(argv[4], &info->time_to_sleep))
		return (false);
	if (argc == 6)
		if (!ft_atoi(argv[5], &info->num_must_eat))
			return (false);
	return (true);
}
