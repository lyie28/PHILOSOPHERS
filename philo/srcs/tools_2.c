/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:33:50 by lyie              #+#    #+#             */
/*   Updated: 2021/11/23 16:57:22 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_mini_free(t_philos *data)
{
	free(data->forks);
	free(data->philos);
	free(data->check_last_eat);
	return (1);
}

int	ft_check_deaths(t_node *m)
{
	if (m->max_eat > 0)
	{
		pthread_mutex_lock(m->stop);
		if ((*m->stops) == m->no_philos)
		{
			pthread_mutex_unlock(m->stop);
			return (1);
		}
		pthread_mutex_unlock(m->stop);
	}
	pthread_mutex_lock(m->check_all);
	if (*m->deaths != 0)
	{
		pthread_mutex_unlock(m->check_all);
		return (1);
	}
	pthread_mutex_unlock(m->check_all);
	return (0);
}

int	ft_clear_up(t_philos *data, t_list *list, int ret)
{
	int	i;

	i = -1;
	while (++i < data->no_philos)
	{
		if (data->philos[i])
			pthread_join(data->philos[i], NULL);
	}
	ft_big_free(list, data);
	return (ret);
}

int	ft_check_stop(t_philos *data)
{
	pthread_mutex_lock(&data->stop);
	if (data->stops == data->no_philos)
	{
		pthread_mutex_unlock(&data->stop);
		return (1);
	}
	pthread_mutex_unlock(&data->stop);
	return (0);
}

int	ft_error(char *error, int ret)
{
	write(2, error, ft_strlen(error));
	return (ret);
}
