/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:31:07 by user42            #+#    #+#             */
/*   Updated: 2021/11/23 16:56:14 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_big_free(t_list *list, t_philos *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->check_last_eat)
		free(data->check_last_eat);
	if (list && list->head)
		ft_freelist(list->head);
	if (list)
		free(list);
}	

long long	ft_time_origin(long long start)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - start);
}

long long	ft_time(t_node *node)
{
	long long		start;
	struct timeval	tv;
	struct timezone	tz;

	pthread_mutex_lock(node->time_lock);
	start = *(node->start);
	pthread_mutex_unlock(node->time_lock);
	gettimeofday(&tv, &tz);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - start);
}

void	ft_usleep(long long duration, t_node *philo)
{
	long long	hold;
	long long	new;

	hold = ft_time(philo);
	while (ft_check_deaths(philo) == 0)
	{
		new = ft_time(philo);
		if ((new - hold) >= duration)
			break ;
		usleep(500);
	}
}
